//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")

#ifdef __APPLE__
# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_map>
# include <unordered_set>
# include <thread>
#else
# include <bits/stdc++.h>
#endif

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 100+10, inf = 1000111222;

void maximize(int& a,int b)
{
    if (a<b){
        a=b;
    }
}

int a[max_n];
int b[max_n];

int dp[2][max_n][max_n*max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int SUM_B=0;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        SUM_B+=b[i];
    }

    for (int i=0;i<max_n;i++){
        for (int j=0;j<max_n*max_n;j++){
            dp[0][i][j]=-1e9;
            dp[1][i][j]=-1e9;
        }
    }

    int cur=0;
    dp[cur][0][0]=0;
    for (int i=1;i<=n;i++){
        for (int i=0;i<max_n;i++){
            for (int j=0;j<max_n*max_n;j++){
                dp[cur^1][i][j]=-1e9;
            }
        }

        for (int j=0;j<=n;j++){
            for (int taken_b=0;taken_b<=n*100;taken_b++){
                if (dp[cur][j][taken_b]!=-1e9){
                    // if take this
                    maximize(dp[cur^1][j+1][taken_b+b[i]], dp[cur][j][taken_b]+a[i]);
                    // if not take this
                    maximize(dp[cur^1][j][taken_b], dp[cur][j][taken_b]);
                }
            }
        }

        cur^=1;
    }

    for (int j=1;j<=n;j++){
        ld ans=0;
        for (int taken_b=0;taken_b<=n*100;taken_b++){
            if (dp[cur][j][taken_b]!=-1e9){
                ans=max(ans,taken_b + min((SUM_B-taken_b)/ld(2), ld(1)*(dp[cur][j][taken_b]-taken_b)));
            }
        }
        cout<<fixed<<setprecision(20)<<ans<<" ";
    }
    cout<<"\n";
}