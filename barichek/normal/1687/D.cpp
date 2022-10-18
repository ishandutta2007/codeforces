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

const int max_n = 2e6+10, inf = 1000111222;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<ll> squares;
    squares.reserve(max_n);
    for (int i=1;i<=max_n;i++){
        squares.pb(1ll*i*i);
    }

    ll ans=1e18;
    for (int d=1;d<=max_n;d++){
        if (1ll*d*d+d>=a[0]){
            LOG(d);
            ll L=max(0ll,1ll*d*d-a[0]);
            if (L>ans){
                break;
            }
            ll R=1ll*d*d+d-a[0];
            int cur=0;
            int pointer=d;
            while (L<=R && cur<n){
                LOG("iteration");
                LOG("value for bin search",1ll*pointer*pointer+pointer - L);
                int new_cur=upper_bound(all(a),1ll*pointer*pointer+pointer - L)-a.begin();
                LOG(L,R,cur,new_cur,pointer);
                R=min(R,1ll*pointer*pointer+pointer - a[new_cur-1]);
                if (new_cur!=n){
                    LOG(a[new_cur]+L);
                    int new_pointer=lower_bound(all(squares),a[new_cur]+L)-squares.begin()+1;
                    LOG("at start", new_pointer);
                    if (1ll*new_pointer*new_pointer>a[new_cur]+R){
                        new_pointer--;
                    }
                    if (new_pointer>max_n){
                        L=1,R=0;
                        break;
                    }
                    LOG(new_pointer);

                    L=max(L,1ll*new_pointer*new_pointer - a[new_cur]);
                    R=min(R,1ll*new_pointer*new_pointer+new_pointer - a[new_cur]);
                    pointer=new_pointer;
            if (L>ans){
                break;
            }
                }
                cur=new_cur;
                LOG("at the end", L,R,cur,new_cur);
            }
            if (L<=R){
                LOG("for ans",L);
                ans=min(ans,L);
            }
        }
    }
    cout<<ans<<"\n";
}