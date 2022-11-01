#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e15)
#define MOD ((ll)1e9+7)
#define N (301*1000)
#define ll long long
#define ld long double

ll a,b,c;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a>>b>>c;
    cout<<min(2*a+2*b,min(a+b+c,min(3*a+b+c,min(3*b+a+c,min(2*a+2*c,2*b+2*c)))));
	
    return 0;
}