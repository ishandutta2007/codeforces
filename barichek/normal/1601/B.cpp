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

int last=0;
int t[4*max_n];

bool is_leaf[5*max_n];
int leaf_value[5*max_n];

int a[max_n];
int b[max_n];

vector<pii> reb[5*max_n];

void build(int v,int l,int r)
{
    t[v]=++last;
//    cout<<t[v]<<" for ["<<l<<";"<<r<<"]"<<"\n";
    if (l==r){
        is_leaf[t[v]]=1;
        leaf_value[t[v]]=l;
        reb[t[v]].pb(mp(l+b[l],0));
        return;
    }
    int m=(l+r)/2;
    build(v*2,l,m);
    build(v*2+1,m+1,r);
    reb[t[v]].pb(mp(t[v*2],0));
    reb[t[v]].pb(mp(t[v*2+1],0));
}

void get(int v,int l,int r,int tl,int tr,vector<int>& cur)
{
    if (l>tr||r<tl){
        return;
    }
    if (l>=tl&&r<=tr){
        cur.pb(t[v]);
        return;
    }
    int m=(l+r)/2;
    get(v*2,l,m,tl,tr,cur);
    get(v*2+1,m+1,r,tl,tr,cur);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }

    last=n;
    build(1,0,n);
    {
        vector<int> cur;
        for (int i=1;i<=n;i++){
            cur.clear();
            get(1,0,n,i-a[i],i,cur);

//            cout<<"for i :: "<<i<<" :: ";
//            for (auto j:cur){
//                cout<<j<<" ";
//            }
//            cout<<"\n";

            for (auto v:cur){
                reb[i].pb(mp(v,1));
            }
        }
    }

    auto bfs=[&](int s,int t)
    {
        vector<int> dist(last+1,inf);
        vector<int> pred(last+1,-1);

        dist[s]=0;
        deque<int> q;
        q.push_back(s);
        while (!q.empty()){
            int now=q.front();
            q.pop_front();
            for (auto wh:reb[now]){
                if (dist[wh.fir]>dist[now]+wh.sec){
                    dist[wh.fir]=dist[now]+wh.sec;
                    pred[wh.fir]=now;
                    if (wh.sec==0){
                        q.push_front(wh.fir);
                    }
                    else{
                        q.push_back(wh.fir);
                    }
                }
            }
        }

        if (dist[t]==inf){
            return mp(false,vector<int>{});
        }

        vector<int> res;
        int cur=t;
        while (cur!=-1){
            res.pb(cur);
            cur=pred[cur];
        }
        reverse(all(res));

        return mp(true,res);
    };

    auto res=bfs(n,0);
    if (res.fir){
        vector<int> path;
        for (auto i:res.sec){
            if (is_leaf[i]){
                path.pb(leaf_value[i]);
            }
        }

//        cout<<"all paht :: ";
//        for (auto i:res.sec){
//            cout<<i<<" ";
//        }
//        cout<<"\n";

        cout<<len(path)<<"\n";
        for (auto i:path){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    else{
        cout<<-1<<"\n";
    }
}