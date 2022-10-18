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

const int max_n = 1e3+10, inf = 1000111222;

int p[max_n];
int sz[max_n];

int f(int v)
{
    return v==p[v]?v:p[v]=f(p[v]);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,d;
    cin>>n>>d;
    for (int i=1;i<=n;i++){
        p[i]=i;
        sz[i]=1;
    }
    multiset<int> sizes;
    for (int i=1;i<=n;i++){
        sizes.insert(1);
    }
    int taken_into_ostov=0;
    for (int i=1;i<=d;i++){
        int x,y;
        cin>>x>>y;
        x=f(x);
        y=f(y);
        if (x!=y){
            taken_into_ostov++;
            sizes.erase(sizes.find(sz[x]));
            sizes.erase(sizes.find(sz[y]));

            sz[y]+=sz[x];
            sz[x]=0;
            p[x]=y;

            sizes.insert(sz[y]);
        }
        vector<int> kek(all(sizes));
        int rest_have=i-taken_into_ostov;

        int ans=kek.back()-1;
        kek.pop_back();
        while (rest_have && !kek.empty()){
            rest_have--;
            ans+=kek.back();
            kek.pop_back();
        }
        ans+=rest_have;

        cout<<ans<<"\n";
    }
}