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

#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int max_n = 1000+10, inf = 1000111222;

bitset<max_n> b;

void solve()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<max_n;i++){
        b[i]=0;
    }
    for (int i=0;i<n;i++){
        char c;
        cin>>c;
        b[i]=(c=='1');
    }
    for (int iter=0;iter<min(max_n,m);iter++){
        b|=(b>>1)^(b<<1);
    }
    for (int i=0;i<n;i++){
        cout<<b[i];
    }
    cout<<"\n";
}

void ___main___()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ___main___();

    exit(0);
}