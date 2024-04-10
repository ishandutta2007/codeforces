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

template<typename T>
struct segment_tree1 {
    pair<T, int> mx[4 * max_n];
    pair<T, int> mn[4 * max_n];

    void build(int v, int l, int r) {
        if (l == r) {
            mx[v] = {-inf, l};
            mn[v] = {inf, l};
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    void update(int v, int l, int r, int pos, T value1, T value2) {
        if (l == r) {
            mx[v] = {value1, l};
            mn[v] = {value2, l};
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(2 * v, l, mid, pos, value1, value2);
        } else {
            update(2 * v + 1, mid + 1, r, pos, value1, value2);
        }
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    int find_first_bigger_equal(int v,int l,int r,int value){
        assert(mx[v].fir>=value);
        if (l == r) {
            return l;
        }
        int mid = (l + r) / 2;
        if (mx[v*2].fir >= value) {
            return find_first_bigger_equal(2 * v, l, mid, value);
        } else {
            return find_first_bigger_equal(2 * v + 1, mid + 1, r, value);
        }
    }

    pair<T, int> get_max(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mx[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_max(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_max(2 * v + 1, mid + 1, tr, l, r);
        }
        return max(get_max(2 * v, tl, mid, l, mid), get_max(2 * v + 1, mid + 1, tr, mid + 1, r));
    }

    pair<T, int> get_min(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mn[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r);
        }
        return min(get_min(2 * v, tl, mid, l, mid), get_min(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

segment_tree1<int> st1;

template<typename T>
struct segment_tree2 {
    T f[4 * max_n];
    T mn[4 * max_n];

    void build(int v, int l, int r) {
        f[v] = 0;
        if (l == r) {
            mn[v] = inf;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    void push(int v, int l, int r, int mid) {
        if (f[v]) {
            mn[2 * v] += f[v];
            mn[2 * v + 1] += f[v];
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, T value) {
        if (tl == l && tr == r) {
            f[v] += value;
            mn[v] += value;
            return;
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    T get_min(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mn[v];
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r);
        }
        return min(get_min(2 * v, tl, mid, l, mid), get_min(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

segment_tree2<int> st2;

template<typename T>
struct segment_tree3 {
    T sum[4 * max_n];

    void build(int v, int l, int r) {
        if (l == r) {
            sum[v] = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    void update(int v, int l, int r, int x, T value) {
        if (l == r) {
            sum[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    T get_sum(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return sum[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return get_sum(2 * v, tl, mid, l, mid) + get_sum(2 * v + 1, mid + 1, tr, mid + 1, r);
    }
};

segment_tree3<int> st3;

int N,q;

int type[max_n];

int l[max_n];
int r[max_n];
int x[max_n];

int pos_in_v[max_n];

vector<int> get_naive()
{
    vector<int> res;
    vector<bool> NOS(N,0);
    vector<pii> v;
    for (int i=0;i<q;i++){
        if (type[i]==0){
            if (x[i]==0){
                for (int j=l[i];j<=r[i];j++){
                    NOS[j]=1;
                }
            }
            else{
                v.pb(mp(l[i],r[i]));
            }
        }
        else{
            int j=l[i];
            bool any_YES=0;
            for (auto s:v){
                if (s.fir<=j && j<=s.sec && accumulate(NOS.begin()+s.fir,NOS.begin()+s.sec+1,0)==(s.sec-s.fir+1)-1){
                    any_YES=1;
                }
            }
            if (NOS[j]){
                res.pb(0);
            }
            else if (any_YES){
                res.pb(1);
            }
            else{
                res.pb(2);
            }
        }
    }
    return res;
}

const bool naive=0;
const bool gen=0;
const bool stress=0;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    start_of_program:;

    if (gen){
        N=10;
        q=10;
        cout<<N<<" "<<q<<"\n";
    }
    else{
        cin>>N>>q;
    }
    vector<pair<pii,int>> v;
    vector<bool> for_gen(N);
    for (int i=0;i<N;i++){
        for_gen[i]=rand()%2;
    }
    for (int i=0;i<q;i++){
        if (gen){
            type[i]=rand()%2;
            cout<<type[i]<<" ";
            if (type[i]==0){
                l[i]=rand()%N;
                r[i]=rand()%N;
                if (l[i]>r[i]){
                    swap(l[i],r[i]);
                }
                x[i]=(accumulate(for_gen.begin()+l[i],for_gen.begin()+r[i]+1,0)>0 ? 1 : 0);
                if (x[i]==1){
                    v.pb(mp(mp(l[i],r[i]),i));
                }
                cout<<l[i]+1<<" "<<r[i]+1<<" "<<x[i]<<"\n";
            }
            else{
                l[i]=rand()%N;
                cout<<l[i]+1<<"\n";
            }
        }
        else{
            cin>>type[i];
            if (type[i]==0){
                cin>>l[i]>>r[i]>>x[i];
                l[i]--;
                r[i]--;
                if (x[i]==1){
                    v.pb(mp(mp(l[i],r[i]),i));
                }
            }
            else{
                cin>>l[i];
                l[i]--;
            }
        }
    }
    if (!v.empty()){
        sort(all(v),[&](const auto A,const auto B){
            if (A.fir.fir!=B.fir.fir){
                return A.fir.fir<B.fir.fir;
            }
            if (A.fir.sec!=B.fir.sec){
                return A.fir.sec>B.fir.sec;
            }
            return A.sec<B.sec;
        });
        st1.build(1,0,len(v)-1);
        st2.build(1,0,len(v)-1);
        for (int i=0;i<len(v);i++){
            pos_in_v[v[i].sec]=i;
        }
    }

    st3.build(1,0,N-1);

    vector<int> for_open_for_zero(N);
    for (int i=0;i<N;i++){
        for_open_for_zero[i]=i;
    }
    set<int> open_for_zero(all(for_open_for_zero));

    set<pair<pii,int>> active_segments;
    auto get_cover_segment=[&](int pos_in_N)
    {
        if (v.empty()){
            return mp(-1,-1);
        }
        if (st1.mx[1].fir<pos_in_N){
            return mp(-1,-1);
        }
        int L=st1.find_first_bigger_equal(1,0,len(v)-1,pos_in_N);
        if (v[L].fir.fir>pos_in_N){
            return mp(-1,-1);
        }

        auto it_R=active_segments.lower_bound(mp(mp(pos_in_N+1,-inf),-1));
        it_R--;
        return mp(L,it_R->sec);
    };

    auto set_zero=[&](int pos_in_N)
    {
        LOG("set_zero", pos_in_N);
        st3.update(1,0,N-1,pos_in_N,1);
        pii cover_segment=get_cover_segment(pos_in_N);
        if (cover_segment!=mp(-1,-1)){
            st2.update(1,0,len(v)-1,cover_segment.fir,cover_segment.sec,-1);
        }
    };
    vector<int> my_ans;
    for (int i=0;i<q;i++){
        LOG("request", i);
        if (type[i]==0){
            if (x[i]==0){
                LOG("cover zero",l[i],r[i]);
                auto it=open_for_zero.lower_bound(l[i]);
                while (it!=open_for_zero.end() && *it<=r[i]){
                    set_zero(*it);
                    auto it_next=it;
                    it_next++;
                    open_for_zero.erase(it);
                    it=it_next;
                }
            }
            else{
                bool to_skip=0;
                int itttt=lower_bound(all(v),mp(mp(l[i],-inf),-1))-v.begin();
                LOG(st1.get_min(1,0,len(v)-1,itttt,len(v)-1).fir);
                if (st1.get_min(1,0,len(v)-1,itttt,len(v)-1).fir<=r[i]){
                    to_skip=1;
                }
                LOG(to_skip);
                if (!to_skip){
                    int p_in_v=pos_in_v[i];
                    while (1){
                        auto res_st1=st1.get_max(1,0,len(v)-1,0,p_in_v);
                        if (res_st1.fir<r[i]){
                            break;
                        }
                        st1.update(1,0,len(v)-1,res_st1.sec,-inf,+inf);
                        st2.update(1,0,len(v)-1,res_st1.sec,res_st1.sec,inf);
                        LOG("do unactive", v[res_st1.sec].fir.fir, v[res_st1.sec].fir.sec);
                        active_segments.erase(mp(v[res_st1.sec].fir,res_st1.sec));
                    }

                    st1.update(1,0,len(v)-1,p_in_v,r[i],r[i]);
                    active_segments.insert(mp(mp(l[i],r[i]),p_in_v));

                    {
                        int real_new_value=(r[i]-l[i]+1)-st3.get_sum(1,0,N-1,l[i],r[i]);
                        int val_before=st2.get_min(1,0,len(v)-1,p_in_v,p_in_v);
                        st2.update(1,0,len(v)-1,p_in_v,p_in_v,-val_before + real_new_value);
                    }
                }
            }
        }
        else{
            int j=l[i];

            if (st3.get_sum(1,0,N-1,j,j)==1){
                my_ans.pb(0);
                cout<<"NO"<<"\n";
            }
            else{
                pii cover_segment=get_cover_segment(j);
                if (cover_segment!=mp(-1,-1) && st2.get_min(1,0,len(v)-1,cover_segment.fir,cover_segment.sec)==1){
                    my_ans.pb(1);
                    cout<<"YES"<<"\n";
                }
                else{
                    my_ans.pb(2);
                    cout<<"N/A"<<"\n";
                }
            }
        }
    }

    if (naive){
        vector<int> naive_ans=get_naive();
        if (my_ans!=naive_ans){
            cout<<"my_ans :: ";
            for (auto i:my_ans){
                cout<<i<<(i==0 ? "(NO)" : i==1 ? "(YES)" : "(N/A)")<<" ";
            }
            cout<<"\n";
            cout<<"naive_ans :: ";
            for (auto i:naive_ans){
                cout<<i<<(i==0 ? "(NO)" : i==1 ? "(YES)" : "(N/A)")<<" ";
            }
            cout<<"\n";
            cout<<"VERY_BAD"<<"\n";
            exit(123);
        }
        else{
            cout<<"ALL IS GOOD"<<"\n";
        }
    }

    if (gen && naive && stress){
        goto start_of_program;
    }
}