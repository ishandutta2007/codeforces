#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)101*1000)
#define K ((ll)13)

ll n,k,a[N],fen[K][N],ans;

ll query(ll id,ll x){ll res=0;for(;x>0;x-=x&-x)res+=fen[id][x];return res;}
ll update(ll id,ll x,ll num){for(;x<N;x+=x&-x)fen[id][x]+=num;}

int main() {
   	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   	cin>>n>>k;
   	if(k==0)return cout<<n,0;
   	for(int i=0;i<n;i++)
   	{
   		cin>>a[i];
		for(ll j=0,x=1;j<k;j++)
		{
			ll ex=query(j,a[i]);
			update(j,a[i],x);
			x=ex;
			if(j==k-1)ans+=ex;
		}
	}
	cout<<ans;
    return 0;
}