#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;
const int MAXN=200005;

ll n,ans=0;

ll work(ll n)
{
	ll x=n;
	for(ll i=2;i*i<=n;i++)
		if(!(n%i)){x=i;break;}
	return x;
}

int main()
{
	cin>>n;
	ll x=work(n);
	if(x==2)cout<<n/2<<endl;
	else cout<<(n-x)/2+1<<endl;
	return 0;
}