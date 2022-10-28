#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<ll>> vvll;

#define PI 3.141592653589793
#define MOD 1000000007

int main()
{
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    if(n%4==0)
    {
        cout<<0;
    }
    else if (n%4==1)
    {
        cout << Min(3*a, a+b, c);
    }
    else if(n%4==2)
    {
        cout << Min(2*a, b, 2*c);
    }
    else if(n%4==3)
    {
        cout << Min(a, b+c, 3*c);
    }
    return 0;
}