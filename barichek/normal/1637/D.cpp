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

const int max_n = 100+10, inf = 1000111222;

bitset<max_n*max_n> can;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        int n;
        cin>>n;
        vector<int> a0;
        vector<int> a1;
        for (int i=0;i<n;i++){
            int b;
            cin>>b;
            a0.pb(b);
        }
        for (int i=0;i<n;i++){
            int b;
            cin>>b;
            a1.pb(b);
        }
        ll sum=accumulate(all(a0),0)+accumulate(all(a1),0);
        can.reset();

        can[0]=1;
        for (int i=0;i<n;i++){
            can=(can<<a0[i])|(can<<a1[i]);
        }

        ll best=0;
        for (int i=0;i<max_n*max_n;i++){
            if (can[i] && i<=sum/2){
                best=i;
            }
        }

        ll ans=0;
        for (auto i:a0){
            ans+=1ll*i*i*(n-2);
        }
        for (auto i:a1){
            ans+=1ll*i*i*(n-2);
        }
        ans+=(1ll*best*best+1ll*(sum-best)*(sum-best));
        cout<<ans<<"\n";
    }
}