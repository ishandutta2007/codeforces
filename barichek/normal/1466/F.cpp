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

const int max_n = 5e5+10, inf = 1000111222;

int p[max_n];
bool mark[max_n];

int f(int v)
{
    return p[v]==v?v:p[v]=f(p[v]);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    srand(time(0));

    int n,m;
    scanf("%d%d",&n,&m);

    int ans_T=1;
    vector<int> ans(0);

    auto add_ans=[&](int val)
    {
        ans_T*=2;
        ans_T=ans_T % ((int)(1e9+7));
        ans.pb(val);
    };

    for (int j=1;j<=m;j++){
        p[j]=j;
        mark[j]=0;
    }

    for (int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        if (k==1){
            int a;
            scanf("%d",&a);
            a=f(a);
            if (!mark[a]){
                mark[a]=1;
                add_ans(i+1);
            }
        }
        else{
            int a,b;
            scanf("%d%d",&a,&b);
            a=f(a);
            b=f(b);
            if (a!=b && (!mark[a] || !mark[b])){
                if (rand()&1){
                    swap(a,b);
                }
                p[a]=b;
                mark[b]|=mark[a];
                add_ans(i+1);
            }
        }
    }
    cout<<ans_T<<" "<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}