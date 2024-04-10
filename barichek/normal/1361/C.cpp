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
///#define int long long

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

#define arr (int)(5e5+10)
#ifdef __APPLE__
    const int MAX_VAL=(1ll<<10);
#else
    const int MAX_VAL=(1ll<<20);
#endif

int n;
int a[arr];
int b[arr];

int a1[arr];
int b1[arr];

vector<pii> vh[MAX_VAL];
int pointers[MAX_VAL];

inline int get_rev(const pii& cur)
{
    return (cur.sec==0 ? b[cur.fir] : a[cur.fir]);
}

pii his_pair[arr][2];

void make_merge(pii a1,pii a2)
{
//    cerr<<"make_merge :: "<<a1.fir<<" "<<a1.sec<<" : "<<a2.fir<<" "<<a2.sec<<"\n";
    his_pair[a1.fir][a1.sec]=a2;
    his_pair[a2.fir][a2.sec]=a1;
}

vi reb[arr + MAX_VAL];

bool used[arr];

void recheck_q(int val)
{
    while (pointers[val]<len(vh[val])){
        pii cur=vh[val][pointers[val]];
        if (used[cur.fir]){
//            cerr<<"recheck_q "<<val<<"\n";
            pointers[val]++;
        }
        else{
            break;
        }
    }
}

int p_snm[arr];

int f_snm(int v)
{
    return (p_snm[v]==v?v:p_snm[v]=f_snm(p_snm[v]));
}

bool merge_snm(int u,int v)
{
    u=f_snm(u);
    v=f_snm(v);
    if (u==v){
        return 0;
    }
    else{
        p_snm[u]=p_snm[v];
        return 1;
    }
}

vi indexes_from_value[MAX_VAL];

int get_id(pii a)
{
    return a.fir*2-(a.sec==0?1:0);
}

pii get_guy(int id,int val)
{
    if (a[id]==val){
        return mp(id, 0);
    }
    if (b[id]==val){
        return mp(id, 1);
    }
    assert(0);
}

void merge_cycles(int val,int id1,int id2)
{
    pii guy1=get_guy(id1,val);
    pii guy1_brother=his_pair[guy1.fir][guy1.sec];
    pii guy2=get_guy(id2,val);
    pii guy2_brother=his_pair[guy2.fir][guy2.sec];
    make_merge(guy1, guy2);
    make_merge(guy1_brother, guy2_brother);
}

int get_guy(int id)
{
    return (id%2==1 ? a[(id-1)/2+1] : b[(id-1)/2+1]);
}

bool check(int ans,bool print)
{
//    cerr<<"check :: "<<ans<<"\n";
    for (int i=1;i<=n;i++){
        a[i]=a1[i]&((1ll<<ans)-1);
        b[i]=b1[i]&((1ll<<ans)-1);
        used[i]=0;
        p_snm[i]=i;
//        cerr<<"a["<<i<<"] :: "<<a[i]<<"\n";
//        cerr<<"b["<<i<<"] :: "<<b[i]<<"\n";
    }
//    cerr<<"p1"<<"\n";
    for (int i=0;i<MAX_VAL;i++){
        vh[i].clear();
        pointers[i]=0;
        indexes_from_value[i].clear();
    }
//    cerr<<"p2"<<"\n";
    for (int i=1;i<=n;i++){
        vh[a[i]].pb(mp(i,0));
        vh[b[i]].pb(mp(i,1));
    }
//    cerr<<"p3"<<"\n";
    for (int i=0;i<MAX_VAL;i++){
        while (1){
            recheck_q(i);
            if (pointers[i]==len(vh[i])){
                break;
            }
//            cerr<<"used ? :: "<<used[vh[i][pointers[i]].fir]<<"\n";
//            cerr<<"new cycle :: "<<vh[i][pointers[i]].fir<<" "<<vh[i][pointers[i]].sec<<"\n";
            pii start=vh[i][pointers[i]++];
//            cerr<<"used["<<start.fir<<"] = 1"<<"\n";
            used[start.fir]=1;
            pii cur=start;
            while (1){
                int val=get_rev(cur);
                if (val==i){
                    indexes_from_value[val].pb(cur.fir);
                    make_merge(start,mp(cur.fir,cur.sec^1));
                    break;
                }
                recheck_q(val);
                if (pointers[val]==len(vh[val])){
                    return 0;
                }
                pii to=vh[val][pointers[val]++];
//                cerr<<"used["<<to.fir<<"] = 1"<<"\n";
                used[to.fir]=1;

                indexes_from_value[val].pb(cur.fir);
                make_merge(mp(cur.fir,cur.sec^1),to);
                cur=to;

                assert(merge_snm(start.fir,cur.fir));
            }
        }
    }
    for (int i=0;i<MAX_VAL;i++){
        for (int j=1;j<len(indexes_from_value[i]);j++){
            if (merge_snm(indexes_from_value[i][0],indexes_from_value[i][j])){
                merge_cycles(i, indexes_from_value[i][0], indexes_from_value[i][j]);
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (f_snm(i)!=f_snm(1)){
            return 0;
        }
    }
    if (print){
        vi res(0);
        pii cur=mp(1, 0);
        res.pb(get_id(cur));
        res.pb(get_id(mp(cur.fir,cur.sec^1)));
        while (1){
//            cerr<<"in print :: "<<cur.fir<<" "<<cur.sec<<"\n";
            if (his_pair[cur.fir][cur.sec^1]==mp(1, 0)){
                break;
            }
            cur=his_pair[cur.fir][cur.sec^1];
            res.pb(get_id(cur));
            res.pb(get_id(mp(cur.fir,cur.sec^1)));
        }

        assert(len(res)==2*n);
        for (int i=0;i<len(res);i++){
            if (i%2==1){
                int left = get_guy(res[i]);
                int right = get_guy(res[(i+1)%len(res)]);
                assert((left^right)%(1ll<<ans)==0);
            }
        }

        for (auto i:res){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 1;
}

signed main()
{
    #ifdef __APPLE__
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a1[i]>>b1[i];
    }
    int l=0,r=20;
    while (r-l>0){
        int m=(l+r+1)/2;
        if (check(m, 0)){
            l=m;
        }
        else{
            r=m-1;
        }
    }
    cout<<l<<"\n";
    assert(check(l, 1));
}