#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (4444)
#define T (86401)
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)

ll n,k;

int main()
{
	cin>>n>>k;
	ll i=1;
	for(;i<=2*k;i+=2)
		cout<<2*i-1<<" "<<2*i<<" "<<2*i+2<<" "<<2*i+1<<" ";	
	for(;i<=n;i++)
		cout<<2*i<<" "<<2*i-1<<" ";
	
    return 0;
}