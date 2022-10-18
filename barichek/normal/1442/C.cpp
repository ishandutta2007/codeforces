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

const int MAX_LOG=20;

vector<int> reb[max_n];
vector<int> rreb[max_n];

int n;

int dist1[max_n][MAX_LOG];

pii operator+(pii a,pii b)
{
    return mp(a.fir+b.fir,a.sec+b.sec);
}

pii get_ans_under_log()
{
    for (int i=1;i<=n;i++){
        for (int j=0;j<MAX_LOG;j++){
            dist1[i][j]=1e9;
        }
    }
    queue<pii> q;
    dist1[1][0]=0;
    q.push(mp(1,0));
    while (!q.empty()){
        pii now=q.front();
        q.pop();
        for (auto wh:reb[now.fir]){
            bool need_reverse = now.sec%2;
            if (now.sec+need_reverse>=MAX_LOG){
                continue;
            }

            if (dist1[wh][now.sec+need_reverse]>dist1[now.fir][now.sec]+1){
                dist1[wh][now.sec+need_reverse]=dist1[now.fir][now.sec]+1;
                q.push(mp(wh,now.sec+need_reverse));
            }
        }
        for (auto wh:rreb[now.fir]){
            bool need_reverse = 1-now.sec%2;
            if (now.sec+need_reverse>=MAX_LOG){
                continue;
            }

            if (dist1[wh][now.sec+need_reverse]>dist1[now.fir][now.sec]+1){
                dist1[wh][now.sec+need_reverse]=dist1[now.fir][now.sec]+1;
                q.push(mp(wh,now.sec+need_reverse));
            }
        }
    }
    pair<int,pii> res=mp(1e9,mp(1e9,0));
    for (int i=0;i<MAX_LOG;i++){
        if (dist1[n][i]<1e9){
            res=min(res,mp((1<<i) + dist1[n][i], mp(i,dist1[n][i])));
        }
    }
    return res.sec;
}

pii dist2[max_n][2];

pii get_ans_upper_log()
{
    for (int i=1;i<=n;i++){
        dist2[i][0]=dist2[i][1]=mp(1e9,0);
    }
    dist2[1][0]=mp(0,0);
    set<pair<pii, pii> > q;
    q.insert(mp(dist2[1][0], mp(1,0)));
    while (!q.empty()){
        pii now=(*q.begin()).sec;
        q.erase(q.begin());
        for (auto wh:reb[now.fir]){
            bool need_reverse = now.sec;
            if (dist2[wh][now.sec^need_reverse]>dist2[now.fir][now.sec]+mp(need_reverse,1)){
                q.erase(mp(dist2[wh][now.sec^need_reverse], mp(wh,now.sec^need_reverse)));
                dist2[wh][now.sec^need_reverse]=dist2[now.fir][now.sec]+mp(need_reverse,1);
                q.insert(mp(dist2[wh][now.sec^need_reverse], mp(wh,now.sec^need_reverse)));
            }
        }
        for (auto wh:rreb[now.fir]){
            bool need_reverse = 1-now.sec;
            if (dist2[wh][now.sec^need_reverse]>dist2[now.fir][now.sec]+mp(need_reverse,1)){
                q.erase(mp(dist2[wh][now.sec^need_reverse], mp(wh,now.sec^need_reverse)));
                dist2[wh][now.sec^need_reverse]=dist2[now.fir][now.sec]+mp(need_reverse,1);
                q.insert(mp(dist2[wh][now.sec^need_reverse], mp(wh,now.sec^need_reverse)));
            }
        }
    }
    return min(dist2[n][0],dist2[n][1]);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int m;
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        rreb[v].pb(u);
    }

    pii ans1=get_ans_under_log();
    pii ans2=get_ans_upper_log();

//    cout<<"ans2 :: "<<ans2.fir<<" "<<ans2.sec<<"\n";

    pii ans=ans1.fir<1e9 ? ans1 : ans2;

//    cout<<"ans :: "<<ans.fir<<" "<<ans.sec<<"\n";

    const int md=998244353;

    int ans_value=1;
    for (int i=0;i<ans.fir;i++){
        ans_value=1ll*ans_value*2 % md;
    }
    ans_value+=ans.sec-1;

    cout<<ans_value<<"\n";
}