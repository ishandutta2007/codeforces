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

int F[max_n];

void f_upd(int pos,int val)
{
    for (int i=pos;i<max_n;i|=i+1){
        F[i]+=val;
    }
}

int f_get(int pos)
{
    int res=0;
    for (int i=pos;i>=0;i&=i+1,i--){
        res+=F[i];
    }
    return res;
}

const int max_lev=19;

template<typename T>
struct sparse_table {
    T mn[max_lev][max_n];

    void init(int n, T a[]) {
        for (int i = 0; i < n; ++i) {
            mn[0][i] = a[i];
        }
        for (int i = 1; i < max_lev; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                mn[i][j] = max(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T get_max(int l, int r) const {
        const int lev = 31 - __builtin_clz(r - l + 1);
        return max(mn[lev][l], mn[lev][r - (1 << lev) + 1]);
    }
};

template<typename T>
struct sparse_table_min {
    T mn[max_lev][max_n];

    void init(int n, T a[]) {
        for (int i = 0; i < n; ++i) {
            mn[0][i] = a[i];
        }
        for (int i = 1; i < max_lev; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T get_min(int l, int r) const {
        const int lev = 31 - __builtin_clz(r - l + 1);
        return min(mn[lev][l], mn[lev][r - (1 << lev) + 1]);
    }
};

int PPP[max_n];
int MMM[max_n];

int f_p(int v)
{
    return PPP[v]==v ? v : PPP[v]=f_p(PPP[v]);
}


int n,m,x;
int a[max_n];
int b[max_n];
int l[max_n];

pii to_build_st_rec[max_n];
sparse_table_min<pii> st_rec;

sparse_table<int> static_st;

vector<pii> to_add_ans[max_n];

void add_to_ans_internal(int pref_len,int persistent_max_state,int kf) /// [0;pref_len)
{
//    cout<<"add_to_ans_internal :: "<<pref_len-1<<" "<<persistent_max_state<<" "<<kf<<"\n";
    to_add_ans[persistent_max_state].pb(mp(pref_len-1,kf));
}

void add_to_ans(int l_val,int r_val,int persistent_max_state) /// [l_val;r_val)
{
    add_to_ans_internal(r_val,persistent_max_state,+1);
    add_to_ans_internal(l_val,persistent_max_state,-1);
}

void rec(int l,int r,int last_seen) /// i've seen from [0;last_seen)
{
//    cout<<"rec :: "<<l<<" "<<r<<" "<<last_seen<<"\n";
    if (l>r){
        return;
    }


    vector<int> min_poses;
    int min_val = st_rec.get_min(l,r).fir;
//    cerr<<"base get from "<<l<<" "<<r<<" gets :: "<<st_rec.get_min(l,r).fir<<" "<<st_rec.get_min(l,r).sec<<"\n";
//    cerr<<"min_val :: "<<min_val<<"\n";
    int cur=l;
    while (cur<=r){
        pii cur_res = st_rec.get_min(cur,r);
//        cerr<<"get from "<<cur<<" "<<r<<" gets :: "<<cur_res.fir<<" "<<cur_res.sec<<"\n";
        if (cur_res.fir!=min_val){
            break;
        }
        min_poses.pb(cur_res.sec);
        cur=cur_res.sec+1;
//        cerr<<"new_cur :: "<<cur<<"\n";
//        getchar();
    }

//    cout<<"l r min_poses :: "<<l<<" "<<r<<" ";
//    for (auto i:min_poses){
//        cout<<i<<",";
//    }
//    cout<<"\n";


    int state=static_st.get_max(l,r)-1;
    if (state>=0){
        add_to_ans(last_seen,min_val,state);
    }


    int last=l;
    for (auto i:min_poses){
        rec(last,i-1,min_val);
        last=i+1;
    }
    rec(last,r,min_val);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    srand(time(0) + size_t(new char));

    scanf("%d%d%d",&n,&m,&x);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    vector<pii> bb;
    for (int i=0;i<m;i++){
        scanf("%d",&b[i]);
        bb.pb(mp(b[i],i));
    }
    sort(all(bb));
    for (int i=0;i<n;i++){
        l[i]=lower_bound(all(bb),mp(x-a[i],inf))-bb.begin();
        /// [0;l[i])
        to_build_st_rec[i]=mp(l[i],i);
//        cout<<"l["<<i<<"] :: "<<l[i]<<"\n";
    }

    vector<int> pos_in_l(m);
    for (int i=0;i<len(bb);i++){
        pos_in_l[bb[i].sec]=i;
    }

    static_st.init(n,l);
    st_rec.init(n,to_build_st_rec);
    rec(0,n-1,0);

    ll ans=0;
    for (int i=0;i<m;i++){
        PPP[i]=i;
        MMM[i]=pos_in_l[i];
        f_upd(i,+1);
//        cout<<"f_upd :: "<<i<<" +1"<<"\n";
    }

    vector<bool> already_added(m,0);

    auto try_union=[&](int u,int v)
    {
        u=f_p(u);
        v=f_p(v);
        if (u==v){
            return;
        }

//        cout<<"f_upd :: "<<max(MMM[u],MMM[v])<<" -1"<<"\n";
        f_upd(max(MMM[u],MMM[v]),-1);

        if (rand()&1){
            swap(u,v);
        }

        MMM[u]=min(MMM[u],MMM[v]);
        PPP[v]=u;
    };

    auto add_pos_to_struct=[&](int pos)
    {
        if (pos!=0 && already_added[pos-1]){
            try_union(pos-1,pos);
        }
        if (pos!=m-1 && already_added[pos+1]){
            try_union(pos,pos+1);
        }

        already_added[pos]=1;
    };

    for (int i=0;i<len(bb);i++){
//        cout<<"in ans :: "<<i<<"\n";
        int pos=bb[i].sec;
        add_pos_to_struct(pos);
        for (auto q:to_add_ans[i]){
//            cout<<"req :: "<<q.fir<<" "<<q.sec<<"\n";
            ans+=q.sec*f_get(q.fir);
        }
    }

    cout<<ans<<"\n";
}