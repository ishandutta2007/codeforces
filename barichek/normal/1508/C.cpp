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

int n,m;
vector<pii> reb[max_n];
set<int> not_used;
int comp[max_n];

void dfs(int now,int cur_comp)
{
    not_used.erase(now);
    comp[now]=cur_comp;

    sort(all(reb[now]));
    for (int i=0;i<=len(reb[now]);i++){
        int l=(i==0 ? 1 : reb[now][i-1].fir+1);
        int r=(i==len(reb[now]) ? n : reb[now][i].fir-1);
        while (1){
            auto it=not_used.lower_bound(l);
            if (it!=not_used.end() && *it<=r){
                dfs(*it,cur_comp);
            }
            else{
                break;
            }
        }
    }
}

int p[max_n];
int p1[max_n];

int f(int v)
{
    return p[v]==v ? p[v] : p[v]=f(p[v]);
}

int f1(int v)
{
    return p1[v]==v ? p1[v] : p1[v]=f1(p1[v]);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    srand(time(0));

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int xor_all=0;
    for (int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        reb[u].pb(mp(v,c));
        reb[v].pb(mp(u,c));
        xor_all^=c;
    }
    for (int i=1;i<=n;i++){
        not_used.insert(i);
    }
    int cc=0;
    for (int i=1;i<=n;i++){
        if (not_used.count(i)){
            dfs(i,cc++);
        }
    }

    ll want_to_add = (n-1)-(cc-1);
    ll i_will_add = 1ll*n*(n-1)/2-m;

//    if (i_will_add==1){
//        vector<pair<int,pii>> new_reb;
//        for (int i=1;i<=n;i++){
//            for (auto j:reb[i]){
//                if (i>=j.fir){
//                    continue;
//                }
//                if (comp[i]!=comp[j.fir]){
//                    new_reb.pb(mp(j.sec,mp(i,j.fir)));
//                }
//            }
//            if (len(reb[i])==n-2){
//                for (int j=i+1;j<=n;j++){
//                    bool ok=1;
//                    for (auto k:reb[i]){
//                        if (k.fir==j){
//                            ok=0;
//                        }
//                    }
//                    if (ok){
//                        new_reb.pb(mp(xor_all,mp(i,j)));
//                    }
//                }
//            }
//        }
//
//        ll base_ans=0;
//        sort(all(new_reb));
//        for (int i=1;i<=n;i++){
//            p[i]=i;
//        }
//        for (auto q:new_reb){
//            int u=q.sec.fir;
//            int v=q.sec.sec;
//            u=f(u);
//            v=f(v);
//            if (u==v){
//                continue;
//            }
//
//            base_ans+=q.fir;
//            if (rand()&1){
//                swap(u,v);
//            }
//            p[u]=v;
//        }
//
//        cout<<base_ans<<"\n";
//        return 0;
//    }

    int min_in=(1ll<<30);
    vector< pair< int,pair<pii,pii> > > new_reb;
    for (int i=1;i<=n;i++){
        for (auto j:reb[i]){
            if (i>=j.fir){
                continue;
            }
            if (comp[i]!=comp[j.fir]){
                new_reb.pb(mp(j.sec,mp(mp(comp[i],comp[j.fir]),mp(i,j.fir))));
            }
            else{
                min_in=min(min_in,j.sec);
            }
        }
    }

    ll base_ans=0;
    sort(all(new_reb));
    int bad_kek=(1ll<<30);
    for (int i=0;i<cc;i++){
        p[i]=i;
    }
    for (int i=1;i<=n;i++){
        p1[i]=i;
    }
    for (auto q:new_reb){
        int u=q.sec.fir.fir;
        int v=q.sec.fir.sec;
        u=f(u);
        v=f(v);


        int u1=q.sec.sec.fir;
        int v1=q.sec.sec.sec;
        u1=f1(u1);
        v1=f1(v1);
//        cout<<q.sec.sec.fir<<" "<<q.sec.sec.sec<<" :: "<<u1<<" "<<v1<<"\n";
        if (u1!=v1 && u==v){
            if (bad_kek==(1ll<<30)){
                bad_kek=q.fir;
            }
        }


        if (u==v){
            continue;
        }

        base_ans+=q.fir;
        if (rand()&1){
            swap(u,v);
            swap(u1,v1);
        }
        p[u]=v;
        p1[u1]=v1;
    }

    if (want_to_add==i_will_add){
        cout<<base_ans+min({min_in,xor_all,bad_kek})<<"\n";
    }
    else{
        cout<<base_ans<<"\n";
    }
}