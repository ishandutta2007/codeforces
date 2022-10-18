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

int a[max_n];
int b[max_n];

int cnt_in[max_n];

vector<int> vh[max_n];

int dp[max_n];

void solve()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        vh[i].clear();
        dp[i]=-1;
    }
    for (int i=1;i<=n;i++){
        cin>>a[i];
        vh[a[i]].pb(i);
    }

    int ans=n;
    for (int i=1;i<=n;i++){
        if (len(vh[i])){
            ans-=(len(vh[i])-1);
        }
    }
    cout<<ans<<"\n";

    vector<int> problems;
    for (int i=1;i<=n;i++){
        for (int j=1;j<len(vh[i]);j++){
            problems.pb(vh[i][j]);
        }
    }
    function<int(int)> get_up=[&](int now)
    {
        if (dp[now]!=-1){
            return dp[now];
        }
        else if (vh[now].empty()){
            return now;
        }
        else{
            return dp[now]=get_up(vh[now][0]);
        }
    };
    for (int i=1;i<=n;i++){
        b[i]=a[i];
    }
    if (len(problems)==0){

    }
    else if (len(problems)==1){
        for (int i=1;i<=n;i++){
            cnt_in[i]=0;
        }
        for (int i=1;i<=n;i++){
            cnt_in[a[i]]++;
        }
        int guy=-1;
        for (int i=1;i<=n;i++){
            if (cnt_in[i]==0){
                guy=i;
            }
        }
        assert(guy!=-1);
        if (guy==problems[0]){
            b[vh[a[problems[0]]][0]]=guy;
        }
        else{
            b[problems[0]]=guy;
        }
    }
    else{
        for (int i=0;i<len(problems);i++){
            int cur=problems[i];
            int to=get_up(problems[(i+1)%len(problems)]);
            b[cur]=to;
        }
    }
    for (int i=1;i<=n;i++){
        cout<<b[i]<<" ";
    }
    cout<<"\n";
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    scanf("%d",&test);
    while (test--){
        solve();
    }
}