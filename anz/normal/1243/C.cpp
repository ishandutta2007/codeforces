#include<iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int main()
{
ll n; cin>>n;
ll ans=n;
for(ll i=2;i*i<=n;i++) if(n%i==0){ans=gcd(ans,i);ans=gcd(ans,n/i);}
cout<<ans;
}