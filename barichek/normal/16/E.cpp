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

double a[100][100];
ld dp[1ll<<20];

int without(int a,int b)
{
    return a^(1ll<<b);
}

main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin>>a[i][j];
    dp[(1ll<<n)-1]=1.0;
    for (int mask=(1ll<<n)-1;mask>=0;mask--)
    {
        vi bits;
        bits.clear();
        for (int i=0;i<n;i++)
            if (mask&(1ll<<i))
                bits.pb(i);
        int cnt=__builtin_popcountll(mask);
        for (int i=0;i<bits.size();i++)
            for (int j=i+1;j<bits.size();j++)
                dp[without(mask,bits[j])]+=dp[mask]*a[bits[i]][bits[j]]*2.0/ld(cnt)/ld(cnt-1),
                dp[without(mask,bits[i])]+=dp[mask]*(1.0-a[bits[i]][bits[j]])*2.0/ld(cnt)/ld(cnt-1);
    }
    for (int i=0;i<n;i++)
        cout<<fixed<<setprecision(10)<<dp[1ll<<i]<<" ";
}