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

const int max_n = -1, inf = 1000111222;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;

    auto ok=[&](int pos)
    {
        return s[pos]=='a' && s[pos+1]=='b' && s[pos+2]=='c';
    };

    int ans=0;
    for (int i=0;i+2<len(s);i++){
        if (ok(i)){
            ans++;
        }
    }
    while (q--){
        int pos;
        char c;
        cin>>pos>>c;
        pos--;

        for (int j=max(0,pos-2);j<=pos && j+2<len(s); j++){
            if (ok(j)){
                ans--;
            }
        }
        s[pos]=c;
        for (int j=max(0,pos-2);j<=pos && j+2<len(s); j++){
            if (ok(j)){
                ans++;
            }
        }

        cout<<ans<<"\n";
    }
}