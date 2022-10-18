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

const int max_n = -1, inf = 1000111222;

ll get(ll R)
{
    if (!R){
        return 0;
    }
    ll al_least_one=[R]{
        ll l=0,r=2e9;
        while (r-l>0){
            ll m=(l+r+1)/2;
            if (m*m<=R){
                l=m;
            }
            else{
                r=m-1;
            }
        }
        return l;
    }();
    ll al_least_two=[R]{
        ll l=0,r=2e9;
        while (r-l>0){
            ll m=(l+r+1)/2;
            if (m*m+m<=R){
                l=m;
            }
            else{
                r=m-1;
            }
        }
        return l;
    }();
    ll al_least_three=[R]{
        ll l=0,r=2e9;
        while (r-l>0){
            ll m=(l+r+1)/2;
            if (m*m+2*m<=R){
                l=m;
            }
            else{
                r=m-1;
            }
        }
        return l;
    }();

    ll three=al_least_three;
    ll two=al_least_two-three;
    ll one=al_least_one-two-three;
    return one*1 + two*2 + three*3;
}

void solve()
{
    ll l,r;
    cin>>l>>r;
    cout<<get(r)-get(l-1)<<"\n";
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
        solve();
    }
}