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

const int max_n = 1, inf = 1000111222;

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
        int k;
        cin>>k;
        vector<int> a(k);
        for (auto& i:a){
            cin>>i;
        }
        bool ans=0;
        for (int iter=0;iter<2;iter++){
            vector<int> can;
            for (auto i:a){
                if (i/n>=2){
                    if (i/n!=m-1){
                        can.pb(i/n);
                    }
                    else{
                        if (m-2>=2){
                            can.pb(m-2);
                        }
                    }
                }
            }
            ll sum=accumulate(all(can),0ll);
            if (sum>=m){
                sort(all(can));
                D{
                    cerr<<"can :: ";
                    for (auto i:can){
                        cerr<<i<<" ";
                    }
                    cerr<<"\n";
                };
                ll left=sum-m;
                for (int i=0;left && i<len(can);i++){
                    LOG(i,left);
                    if (can[i]<=left){
                        left-=can[i];
                    }
                    else{
                        if (can[i]-2>=left){
                            left=0;
                            break;
                        }
                        left-=can[i]-2;
                        assert(left==1);
                        if (i==len(can)-1 || can.back()<=2){
                            left=1;
                            break;
                        }
                        else{
                            left=0;
                            break;
                        }
                    }
                }
                if (left==0){
                    ans=1;
                }
            }
            swap(n,m);
        }
        cout<<(ans ? "Yes" : "No")<<"\n";
    }
}

/*
1
3 5 3
6 6 6
*/