#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)2e9)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll n,k,a,b;
char A='G',B='B';

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k>>a>>b;
    if(a<b)swap(a,b),swap(A,B);
    ll num=(a+k-1)/k-1;
    if(num>b)return cout<<"NO",0;
    b-=num;
    for(int i=0;i<num;i++)
    {
    	for(int j=0;j<k;j++)cout<<A;
    	cout<<B;
    	for(int j=0;j<k-1 && b;j++,b--)cout<<B;
	}
	ll p=a%k;
	if(p==0)p=k;
	for(int j=0;j<p;j++)cout<<A;
	for(int j=0;j<k && b;j++,b--)cout<<B;
    return 0;
}