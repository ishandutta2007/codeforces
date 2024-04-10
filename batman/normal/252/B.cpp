#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,a[N],b[3]={N-1,N-1,N-1},p,ex;

int main()
{
	cin>>n;
	a[N-1]=-INF;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(p>2)continue;
		if(!p)b[p++]=i;
		else if(a[i]!=a[b[0]] && a[i]!=a[b[1]])b[p++]=i;
	}
	if(p==1)return cout<<-1,0;
	if(p==3)
	{
		if(!((a[b[0]]>a[b[1]] && a[b[0]]>a[b[2]]) || (a[b[0]]<a[b[1]] && a[b[0]]<a[b[2]])))return cout<<b[1]+1<<" "<<b[2]+1,0;
		if(!((a[b[1]]>a[b[0]] && a[b[1]]>a[b[2]]) || (a[b[1]]<a[b[0]] && a[b[1]]<a[b[2]])))return cout<<b[0]+1<<" "<<b[1]+1,0;
		return cout<<b[0]+1<<" "<<b[1]+1,0;
	}
	for(int i=0;i<n-1;i++)
		if(a[i]==a[i+1])
		{
			if(a[b[0]]==a[i])swap(b[1],b[0]);
			if(b[0]<i)return cout<<b[0]+1<<" "<<i+1,0;
			return cout<<i+2<<" "<<b[0]+1,0;
		}
	if(n<4)return cout<<-1,0;
	cout<<"1 2";
    return 0;
}