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

vector<pii> reb[max_n];

string ans;

bool used[max_n];
pii p[max_n];
int d[max_n];

void dfs(int now,pii pred,int dd)
{
    used[now]=1;
    p[now]=pred;
    d[now]=dd;

    for (auto wh:reb[now]){
        if (!used[wh.fir]){
            dfs(wh.fir,mp(now,wh.sec),dd+1);
        }
    }
}

int uu[max_n];
int vv[max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;
    while (test--){
        int n,m;
        cin>>n>>m;
        for (int i=1;i<=n;i++){
            reb[i].clear();
            used[i]=0;
        }
        for (int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            reb[u].pb(mp(v,i));
            reb[v].pb(mp(u,i));

            uu[i]=u;
            vv[i]=v;
        }
        ans=string(m,'0');
        dfs(1,mp(-1,-1),0);
        for (int i=2;i<=n;i++){
            ans[p[i].sec]='1';
        }
        set<int> s;
        for (int i=0;i<m;i++){
            if (ans[i]=='0'){
                LOG("free edge",uu[i],vv[i]);
                s.insert(uu[i]);
                s.insert(vv[i]);
            }
        }
        LOG(n,m,len(s));
        if (m!=n+2 || len(s)>=4){
            cout<<ans<<"\n";
        }
        else{
            int mx=-1;
            for (auto i:s){
                if (mx==-1 || d[mx]<d[i]){
                    mx=i;
                }
            }
            assert(mx!=-1);

            int edge_with_mx_to_1=-1;
            for (int i=0;i<m;i++){
                if (ans[i]=='0' && (uu[i]==mx || vv[i]==mx)){
                    edge_with_mx_to_1=i;
                }
            }
            assert(edge_with_mx_to_1!=-1);

            assert(mx!=1);
            while (!s.count(p[mx].fir)){
                mx=p[mx].fir;
                assert(mx!=1);
            }
            ans[p[mx].sec]='0';
            ans[edge_with_mx_to_1]='1';
            cout<<ans<<"\n";
        }
    }
}