#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)1001*1000)

ll n,k,prt[N],f[N],strt[N],fnsh[N],num=1;
string s;
vector <ll> child[N];

void dfs(ll x)
{
	strt[x]=num++;
	for(int i=0;i<child[x].size();i++)
		dfs(child[x][i]);
	fnsh[x]=num;
}

int main()
{
	cin>>n>>k>>s;
	for(int i=1,j=0;i<n;i++)
	{
		while(j && s[j]!=s[i])j=f[j];
		if(s[j]==s[i])j++;
		f[i+1]=j;
		child[j].push_back(i+1);
		//cout<<j<<" "<<i+1<<"\n";
	}
	for(int i=1;i<=n;i++)if(!strt[i])dfs(i);
	//cout<<strt[3]<<" "<<fnsh[3]<<" "<<strt[6]<<"\n";
	//cout<<strt[1]<<" "<<fnsh[1]<<" "<<strt[2]<<"\n";
	for(int i=1;i*k<=n;i++)
	{
		bool flg=1;
		for(int j=2*i;j<=k*i;j+=i)
			if(strt[j]<strt[i] || strt[j]>=fnsh[i])
				flg=0;
		
		if(!flg)continue;
		ll l=i*k,r=min(n+1,i*(k+1)+1);
		while(l<r-1)
		{
			ll mid=l+r>>1;
			//cout<<mid<<" "<<(strt[i]<=strt[mid] && strt[mid]<fnsh[i])<<"\n";
			if(strt[mid-i*k]<=strt[mid] && strt[mid]<fnsh[mid-i*k])l=mid;
			else r=mid;
		}
		prt[i*k-1]++;prt[l]--;
		//cout<<i<<" "<<i*k-1<<" "<<l<<"\n";
	}
	for(int i=0;i<n;i++)
	{
		if(i)prt[i]+=prt[i-1];
		cout<<(prt[i]>0);
	}
	return 0;
}