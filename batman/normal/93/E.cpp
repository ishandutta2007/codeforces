#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)102)
#define M ((ll)101*1000)

ll m,mem[M][N];
ll k,a[N];


ll calc(ll n,ll x)
{
	if(n<M && mem[n][x]!=-1)return mem[n][x];
	if(x==-1)return n;
	ll res=calc(n,x-1)-calc(n/a[x],x-1);
	if(n<M)mem[n][x]=res;
	return res;
}

int main()
{
	memset(mem,-1,sizeof mem);
	cin>>m>>k;
	for(int i=0;i<k;i++)cin>>a[i];
	sort(a,a+k);
	cout<<calc(m,k-1);
	return 0;
}