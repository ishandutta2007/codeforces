//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4")

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

#if __APPLE__
#define D for (bool _FLAG = true; _FLAG; _FLAG = false)
#define LOG(...) print(#__VA_ARGS__" ::", __VA_ARGS__) << endl
template <class ...Ts> auto &print(Ts ...ts) { return ((cerr << ts << " "), ...); }
#else
#define D while (false)
#define LOG(...)
#endif

const int max_n = 2e5+10, inf = 1000111222;

const int md=998244353;

void inc(int& a,int b)
{
    a+=b;
    if (a>=md){
        a-=md;
    }
}

/*
0 smaller
1 equal
2 bigger
*/

/*
0 a
1 b
2 c
3 anyone
4 noone
*/

int dp[2][3][3][3][1ll<<3];

bool get_bit(int mask,int bit)
{
    return (mask>>bit)&1;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    reverse(all(s));
    dp[0][1][1][1][(1ll<<3)-1]=1;
    int q1=0,q2=1;
    for (int l=0;l<len(s);l++){
        memset(dp[q2],0,sizeof(dp[q2]));
        for (int s1=0;s1<3;s1++){
            for (int s2=0;s2<3;s2++){
                for (int s3=0;s3<3;s3++){
                    for (int n1=0;n1<2;n1++){
                        for (int n2=0;n2<2;n2++){
                            for (int n3=0;n3<2;n3++){
                                for (int from=0;from<(1ll<<3);from++){
                                    if (!dp[q1][s1][s2][s3][from]){
                                        continue;
                                    }
                                    int new_s1=(n1==s[l]-'0' ? s1 : (n1==1 ? 2 : 0));
                                    int new_s2=(n2==s[l]-'0' ? s2 : (n2==1 ? 2 : 0));
                                    int new_s3=(n3==s[l]-'0' ? s3 : (n3==1 ? 2 : 0));

                                    int new_from=0;
                                    if (get_bit(from,0) && (n1!=n2 || (n1==n2 && n2==n3))){
                                        new_from|=(1ll<<0);
                                    }
                                    if (get_bit(from,1) && (n2!=n3 || (n1==n2 && n2==n3))){
                                        new_from|=(1ll<<1);
                                    }
                                    if (get_bit(from,2) && (n3!=n1 || (n1==n2 && n2==n3))){
                                        new_from|=(1ll<<2);
                                    }

                                    LOG(n1,n2,n3,new_s1,new_s2,new_s2,new_from);
                                    inc(dp[q2][new_s1][new_s2][new_s3][new_from],dp[q1][s1][s2][s3][from]);
                                }
                            }
                        }
                    }
                }
            }
        }
        swap(q1,q2);
    }
    int ans=0;
    for (int s1=0;s1<2;s1++){
        for (int s2=0;s2<2;s2++){
            for (int s3=0;s3<2;s3++){
                inc(ans,dp[q1][s1][s2][s3][0]);
            }
        }
    }
    cout<<ans<<"\n";
}