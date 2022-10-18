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

const int max_n = 3e5+10, inf = 1000111222;

vector<int> vh[max_n];
int ans[max_n];

void solve()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        vh[i].clear();
    }
    for (int i=1;i<=n;i++){
        int a;
        cin>>a;
        vh[a].pb(i);
    }
    int last_ans=n+1;
    for (int i=1;i<=n;i++){
        if (!vh[i].empty()){
            int cur_max_d=vh[i][0];
            for (int j=1;j<len(vh[i]);j++){
                cur_max_d=max(cur_max_d,vh[i][j]-vh[i][j-1]);
            }
            cur_max_d=max(cur_max_d,n-vh[i].back()+1);
            while (last_ans>cur_max_d){
                ans[last_ans-1]=i;
                last_ans--;
            }
        }
    }
    while (last_ans>1){
        ans[last_ans-1]=-1;
        last_ans--;
    }
    for (int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
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