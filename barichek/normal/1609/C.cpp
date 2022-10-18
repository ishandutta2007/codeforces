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

const int max_n = 1e6+10, inf = 1000111222;

bool is_prime[max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i=2;i<max_n;i++){
        is_prime[i]=1;
    }

    for (int i=2;i<max_n;i++){
        if (is_prime[i]){
            for (int j=2*i;j<max_n;j+=i){
                is_prime[j]=0;
            }
        }
    }

    auto get_cnt=[&](const vector<int>& a)
    {
        auto get_cnt_internal=[&](const vector<int>& a)
        {
            ll res=0;

            int last_2=-1,prev_2=-1;
            for (int i=0;i<len(a);i++){
                if (a[i]==2){
                    prev_2=last_2;
                    last_2=i;
                }
                if (last_2!=-1){
                    if (a[i]==2){
                        res+=last_2-prev_2-1;
                    }
                    else{
                        res+=last_2-prev_2;
                    }
                }
            }

            return res;
        };

        ll res=0;
        vector<int> cur;
        for (auto i:a){
            if (i==3){
                res+=get_cnt_internal(cur);
                cur.clear();
            }
            else{
                cur.pb(i);
            }
        }
        res+=get_cnt_internal(cur);
        cur.clear();
        return res;
    };

    int test;
    cin>>test;
    while (test--){
        int n,e;
        cin>>n>>e;
        vector<int> a(n);
        for (auto& i:a){
            cin>>i;
        }
        ll ans=0;
        for (int rest=0;rest<e;rest++){
            vector<int> b;
            for (int i=rest;i<n;i+=e){
                b.pb((a[i]==1 ? 1 : (is_prime[a[i]] ? 2 : 3)));
            }
//            cout<<"b :: ";
//            for (auto j:b){
//                cout<<j<<" ";
//            }
//            cout<<"\n";
            ans+=get_cnt(b);
        }
        cout<<ans<<"\n";
    }
}