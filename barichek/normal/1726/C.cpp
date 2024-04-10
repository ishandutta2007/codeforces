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

int before[max_n];
vector<int> vh[max_n];

int ans;

void solve(int l,int r)
{
    if (l>r){
        return;
    }
    ans++;

    while (l<=r){
        int next_l=*lower_bound(all(vh[before[l]]),l+1);
        solve(l+1,next_l-2);
        l=next_l;
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        string s;
        cin>>s>>s;
        for (int i=0;i<=len(s);i++){
            vh[i].clear();
        }

        int bal=0;
        vh[bal].pb(0);
        before[0]=bal;
        for (int i=0;i<len(s);i++){
            bal+=(s[i]=='(' ? +1 : -1);

            vh[bal].pb(i+1);
            before[i+1]=bal;
        }
        ans=0;
        solve(0,len(s)-1);
        cout<<ans<<"\n";
    }
}