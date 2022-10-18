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

const int max_n = 2e5+10, inf = 1000111222;
const int LOG=31;
const int vertexes = max_n*(LOG+2)+10;

const int root=1;
int last_used=1;

int new_vertex()
{
    return ++last_used;
}

int go[vertexes][2];
int cnt[vertexes];
int dp[vertexes];

void add(int a)
{
    int cur=root;
    for (int i=LOG-1;i>=0;i--){
        int bit=(a>>i)&1;
        if (!go[cur][bit]){
            go[cur][bit]=new_vertex();
        }
        cur=go[cur][bit];
    }
    cnt[cur]++;
}

int comb_dp(int l,int r)
{
    if (l && r){
        return max(l + 1, r + 1);
    }
    else{
        return max(l, r);
    }
}

void dfs(int now)
{
    int left_dp=0;
    int right_dp=0;
    if (go[now][0]){
        dfs(go[now][0]);
        left_dp=dp[go[now][0]];
    }
    if (go[now][1]){
        dfs(go[now][1]);
        right_dp=dp[go[now][1]];
    }
    dp[now]=cnt[now] ? 1 : comb_dp(left_dp,right_dp);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        add(a);
    }
    dfs(root);
    cout<<n-dp[root]<<"\n";
}