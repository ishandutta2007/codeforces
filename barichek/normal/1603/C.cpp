#pragma GCC optimize("Ofast", "unroll-loops")
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

const int max_n = 1e5+10, inf = 1000111222;
const int md=998244353;

void inc(int& a,int b)
{
    a+=b;
    if (a>=md){
        a-=md;
    }
}

int a[max_n];
int dp[2][1000];

vector<int> d[max_n];

int up(int a,int b)
{
    return (a+b-1)/b;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    scanf("%d",&test);
    while (test--){
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }

        memset(dp,0,sizeof(dp));
        int q1=0,q2=1;
        vector<int> d1;
        vector<int> d2;
        auto get_all=[&](int a)
        {
            vector<int> d,d1,d2;
            for (int j=1;j*j<=a;j++){
                d1.pb(j);
                d2.pb(a/j);
            }
            reverse(all(d2));
            d.resize(len(d1)+len(d2));
            merge(all(d1),all(d2),d.begin());

            d.resize(unique(all(d))-d.begin());

            return d;
        };
        d1=get_all(a[n-1]);
        auto find_index=[&](const vector<int>& a,int b)
        {
            return lower_bound(all(a),b)-a.begin();
        };

        int ans=0;
        for (int i=n-1;i>=1;i--){
            memset(dp[q2],0,sizeof(dp[q2]));
            inc(dp[q1][len(d1)-1],+1);
            d2=get_all(a[i-1]);

            int p1=0;
            int p2=0;

            for (int j=0;j<len(d1);j++){
                int d=d1[j];

//                cout<<"dp["<<i<<"]["<<d<<"] :: "<<dp[q1][j]<<"\n";

                if (a[i-1]%d==0){
                    inc(ans,1ll*dp[q1][j]*(a[i-1]/d-1)%md*i%md);
                    while (p1+1<len(d2) && d2[p1+1]<=d){
                        p1++;
                    }
                    inc(dp[q2][p1],dp[q1][j]);
                }
                else if (a[i-1]<d){
                    inc(dp[q2][len(d2)-1],dp[q1][j]);
                }
                else{
                    inc(ans,1ll*dp[q1][j]*(a[i-1]/d)%md*i%md);
                    int to=a[i-1]/(up(a[i-1],d));
                    while (p2+1<len(d2) && d2[p2+1]<=to){
                        p2++;
                    }
//                    if (dp[q1][j]){
//                        cout<<"to :: "<<to<<"\n";
//                    }
                    inc(dp[q2][p2],dp[q1][j]);
                }

//                cout<<"ans :: "<<ans<<"\n";
            }

            d1=d2;
            swap(q1,q2);
        }

        cout<<ans<<"\n";
    }
}