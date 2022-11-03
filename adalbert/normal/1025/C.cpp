#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgjs
#define right rtyjtokh
#define y eth
#pragma GCC optimize ("O3")
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int md=1e9+7;
const int base=3;
const int arr=2e5;

int dp[arr];

signed main()
{
    string st;
    cin >> st;

    st+=st;

    dp[0]=1;
    for (int i=1;i<st.size();i++)
        if (st[i]!=st[i-1])
        dp[i]=dp[i-1]+1; else
        dp[i]=1;

    int res=0;

    for (int i=0;i<st.size();i++)
        res=max(res,dp[i]);

    cout << min(res, int(st.size())/2);
}