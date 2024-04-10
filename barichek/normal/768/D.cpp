#pragma GCC optimize("O3")
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

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

ld dp[1001][10001];

main()
{
    int k,q;
    cin>>k>>q;
    dp[0][0]=1;
    for (int i=1;i<=k;i++)
        for (int j=1;j<=10000;j++)
            dp[i][j]=dp[i-1][j-1]*(k-(i-1))/k+dp[i][j-1]*i/k;
    while (q--)
    {
        int val;
        cin>>val;
        ld p=val/2000.0;
        for (int i=0;i<10001;i++)
            if (dp[k][i]>=p)
            {
                cout<<i<<"\n";
                break;
            }
    }
}