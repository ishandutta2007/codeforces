#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
#define N (501*1000)
#define K (1001*1000)

ll n;
deque <ll> q[2];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=n-1;i>=1;i-=2)
		q[0].push_back(i),q[0].push_front(i);
	q[1].push_back(n);
	for(int i=n-2;i>=1;i-=2)
		q[1].push_back(i),q[1].push_front(i);
	q[1].push_back(n);
	for(int i=0;i<q[0].size();i++)cout<<q[0][i]<<" ";
	for(int i=0;i<q[1].size();i++)cout<<q[1][i]<<" ";		
	return 0;
}