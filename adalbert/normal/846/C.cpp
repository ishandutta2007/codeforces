
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <complex>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".sol","r",stdin); freopen (name".dat","w",stdout);
#define time pdojegoritg

#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define int ll

typedef long long ll;
typedef long double ld;
const int arr=4*1e5;
const int md=1e9+7;

int dp[10000][10],a[10000],pred[10000][10];

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }

    for (int i=0;i<=n;i++)
        for (int c=0;c<=4;c++)
            dp[i][c]=-1e18;

    dp[0][0]=0;

    for (int i=0;i<=n;i++)
        for (int c=1;c<=4;c++)
            for (int p=0;p<=i;p++)
            {
                int now=0;
                if (c%2)
                    now=dp[p][c-1]+a[i]-a[p]; else
                    now=dp[p][c-1]-(a[i]-a[p]);
                if (now>dp[i][c])
                {
                    dp[i][c]=now;
                    pred[i][c]=p;
                }
            }
    int now=n;
    vector<int> vec;
    for (int i=4;i>1;i--)
    {
        now=pred[now][i];
        vec.pb(now);
        now--;
    }
    reverse(vec.begin(),vec.end());
    for (int i=0;i<vec.size();i++)
        cout<<vec[i]<<' ';
}