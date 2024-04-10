#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cerr << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int query(int i,int j)
{
	cout << "? " << i << " " << j << endl;
	int x;
	cin >> x;
	return x;
}

int arr[6]={4 , 8, 15, 16, 23, 42},ans[6];
bitset<10000> vis;

int main()
{jizz
	int x=query(1,2),a,b;
	for(int i=0;i<6;++i)
		for(int j=i+1;j<6;++j)
			if(arr[i]*arr[j]==x)
				a=arr[i],b=arr[j];
	x=query(1,5);
	for(int i=0;i<6;++i)
		if(arr[i]!=a&&arr[i]*a==x)
			ans[0]=a,ans[4]=arr[i],ans[1]=b;
	for(int i=0;i<6;++i)
		if(arr[i]!=b&&arr[i]*b==x)
			ans[0]=b,ans[4]=arr[i],ans[1]=a;
	
	x=query(3,4);
	for(int i=0;i<6;++i)
		for(int j=i+1;j<6;++j)
			if(arr[i]*arr[j]==x)
				a=arr[i],b=arr[j];
	x=query(3,5);
	ans[2]=x/ans[4],ans[3]=a*b/ans[2];
	for(int i=0;i<5;++i)
		vis[ans[i]]=1;
	for(int i=0;i<6;++i)
		if(!vis[arr[i]]) ans[5]=arr[i];
	cout << "!";
	for(int i=0;i<6;++i)
		cout << " " << ans[i];
	ET;
}