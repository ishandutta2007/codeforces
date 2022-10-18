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

char buf[max_n];

string read()
{
    scanf("%s",buf);
    return buf;
}

string s[max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){
        s[i]=read();
    }
    vector<int> poses;
    for (int i=0;i+1<n;i++){
        for (int j=1;j<m;j++){
            if (s[i][j]=='X' && s[i+1][j-1]=='X'){
                poses.pb(j-1);
            }
        }
    }
    sort(all(poses));
    int q;
    scanf("%d",&q);
    while (q--){
        int l,r;
        scanf("%d%d",&l,&r);
        l--;
        r--;
        auto it=lower_bound(all(poses),l);
        if (it!=poses.end() && *it<r){
            cout<<"NO"<<"\n";
        }
        else{
            cout<<"YES"<<"\n";
        }
    }
}