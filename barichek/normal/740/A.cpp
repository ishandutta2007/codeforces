#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

main()
{
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int ans=maxint;
    if (n%4==0) return cout<<0, 0;
    for (int i=0;i<10;i++)
        for (int j=0;j<10;j++)
            for (int k=0;k<10;k++)
                if ((n+i+2*j+3*k)%4==0)
                    ans=min(ans,i*a+j*b+k*c);
    cout<<ans;
}