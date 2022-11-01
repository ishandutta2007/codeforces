#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((int)501*1000)

int n,k,a[N],fen[N];
vector <int> vec[N];

void update(int x){for(;x<N;x+=x&-x)fen[x]++;}
int query(int x){int res=0;for(;x>0;x-=x&-x)res+=fen[x];return res;}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	bool flg=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i],vec[a[i]].push_back(i);
		if(a[i]==k)flg=1;
		if(a[i]==0)update(i);
	}
	for(int i=k;i>0;i--)
	{
		int lst=-1;
		for(auto u:vec[i])
		{
			update(u);
			if(lst!=-1 && query(u)-query(lst)<u-lst)return cout<<"NO\n",0;
			lst=u;
		}
	}
	a[0]=a[n+1]=1;
	for(int i=1,lst=0;i<=n+1;i++)
	{
		if(a[i]==0)continue;
		if(lst==i-1){lst=i;continue;}
		int x=max(a[lst],a[i]);
		if(!flg)x=k,flg=1;
		for(int j=lst+1;j<i;j++)a[j]=x;
		lst=i;
	}
	if(!flg)return cout<<"NO\n",0;
	cout<<"YES\n";
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	cout<<"\n";
	return 0;
}