//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")

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

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;
const ll inf=1e18+10;

///---program start---///

vi reb[arr];

int dfs1(int now,int pred,int deep=0)
{
    if (len(reb[now])==1&&deep%2==1){
        return 1;
    }
    int res=0;
    for (auto wh:reb[now]){
        if (wh!=pred){
            res|=dfs1(wh,now,deep+1);
        }
    }
    return res;
}

int dfs2(int now,int pred)
{
    int res=0;
    int cur=0;
    for (auto wh:reb[now]){
        if (wh!=pred){
            res+=dfs2(wh,now);
            if (len(reb[wh])==1){
                cur++;
            }
        }
    }
    return res+(cur==0?0:cur-1);
}

signed main()
{
    #ifdef __APPLE__
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    int any_leaf=-1;
    int any_not_leaf=-1;
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    for (int i=1;i<=n;i++){
        if (len(reb[i])==1){
            any_leaf=i;
        }
        else{
            any_not_leaf=i;
        }
    }
    assert(any_leaf!=-1);
    assert(any_not_leaf!=-1);

    int ans1=1+2*dfs1(any_leaf,-1);
    int ans2=(n-1)-dfs2(any_not_leaf,-1);

    cout<<ans1<<" "<<ans2<<"\n";
}