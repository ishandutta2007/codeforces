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

const int max_n = 1e5+10, inf = 1000111222;

ll ans;
vector<int> cur;

void add_one_to_cur(int a,int m)
{
    for (auto i:cur){
        if (a>i){
            ans++;
        }
    }
    cur.pb(a);
    if (len(cur)==m){
        cur.clear();
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;
    while (test--){
        int n,m;
        cin>>n>>m;

        vector<pii> a;
        for (int i=1;i<=n*m;i++){
            int b;
            cin>>b;
            a.pb(mp(b,i));
        }
        sort(all(a));

        ans=0;
        cur.clear();

        for (int i=0;i<len(a);){
            int j=i;
            while (j+1<len(a) && a[j+1].fir==a[i].fir){
                j++;
            }
            /// [i;j]

            for (int k=i;k<=j;){
                int to_take=-1;
                if (m-len(cur)<=j-k+1){
                    to_take=m-len(cur);
                }
                else{
                    to_take=j-k+1;
                }

                for (int l=k+to_take-1;l>=k;l--){
                    add_one_to_cur(a[l].sec,m);
                }
                k+=to_take;
            }

            i=j+1;
        }

        cout<<ans<<"\n";
    }
}