#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (301*1000)
#define INF ((ll)1e14)
#define MOD ((ll)1e9+7)

ll a,b,c,d;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	ll x=abs(a-c),y=abs(b-d);
	cout<<min(x,y)+abs(x-y);
	
		
    return 0;
}