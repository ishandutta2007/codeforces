#pragma GCC optimize("Ofast", "unroll-loops")
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
 
const int max_n = 1e5+10, inf = 1000111222;
 
int x[max_n];
int y[max_n];
 
vector<pii> vh;
 
template<typename T>
struct segment_tree {
    vector<pair<T, pair<int, int>>> all[4 * max_n];
 
    void build(int v, int l, int r, T a[]) {
        if (l == r) {
            all[v].push_back({a[l], {-1, -1}});
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        int p1 = 0, p2 = 0;
        all[v].reserve(all[2 * v].size() + all[2 * v + 1].size());
        while (p1 < all[2 * v].size() || p2 < all[2 * v + 1].size()) {
            if (p1 == all[2 * v].size()) {
                all[v].emplace_back(all[2 * v + 1][p2].first, make_pair(p1, p2));
                ++p2;
            } else if (p2 == all[2 * v + 1].size()) {
                all[v].emplace_back(all[2 * v][p1].first, make_pair(p1, p2));
                ++p1;
            } else if (all[2 * v][p1] < all[2 * v + 1][p2]) {
                all[v].emplace_back(all[2 * v][p1].first, make_pair(p1, p2));
                ++p1;
            } else {
                all[v].emplace_back(all[2 * v + 1][p2].first, make_pair(p1, p2));
                ++p2;
            }
        }
    }
 
    int get_cnt_more_equal(int v, int tl, int tr, int l, int r, int pos) {
        if (pos == all[v].size()) {
            return 0;
        }
        if (tl == l && tr == r) {
            return all[v].size() - pos;
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_cnt_more_equal(2 * v, tl, mid, l, r, all[v][pos].second.first);
        } else if (l > mid) {
            return get_cnt_more_equal(2 * v + 1, mid + 1, tr, l, r, all[v][pos].second.second);
        }
        return get_cnt_more_equal(2 * v, tl, mid, l, mid, all[v][pos].second.first) +
               get_cnt_more_equal(2 * v + 1, mid + 1, tr, mid + 1, r, all[v][pos].second.second);
    }
 
    int get_cnt_more_equal(int l, int r, T x) {
        const int pos = lower_bound(all[1].begin(), all[1].end(), make_pair(x, make_pair(-2, -2))) - all[1].begin();
        return get_cnt_more_equal(1, 0, all[1].size() - 1, l, r, pos);
    }
};
 
vector<pair<int,pii> > losers;
//map<int,vector<pii>> losers;
set<pii> losers_default;
 
int to_build_st[max_n];
 
segment_tree<int> st;
 
map<int,int> smallest_Y_for_X;
map<int,int> smallest_X_for_Y;
 
int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
 
    double start = clock();
 
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
        losers_default.insert(mp(x[i],y[i]));
 
        if (smallest_Y_for_X.count(x[i])){
            smallest_Y_for_X[x[i]]=min(smallest_Y_for_X[x[i]],y[i]);
        }
        else{
            smallest_Y_for_X[x[i]]=y[i];
        }
        if (smallest_X_for_Y.count(y[i])){
            smallest_X_for_Y[y[i]]=min(smallest_X_for_Y[y[i]],x[i]);
        }
        else{
            smallest_X_for_Y[y[i]]=x[i];
        }
 
        vh.pb(mp(x[i],y[i]));
    }
    sort(all(vh));
 
    for (int i=0;i<len(vh);i++){
        to_build_st[i]=-vh[i].sec;
    }
    st.build(1,0,len(vh)-1,to_build_st);
 
    auto add_losers=[&](int x,int y,int d)
    {
//        cout<<"add loser :: "<<x<<" "<<y<<" "<<d<<"\n";
        losers.pb(mp(x-y,mp(x,x+d)));
    };
 
    auto have_X=[&](int X,int Y)
    {
        return smallest_Y_for_X.count(X) && smallest_Y_for_X[X]<Y;
    };
 
    auto have_Y=[&](int X,int Y)
    {
        return smallest_X_for_Y.count(Y) && smallest_X_for_Y[Y]<X;
    };
 
    auto get_in_square=[&](int x,int y)
    {
        auto it=lower_bound(all(vh),mp(x+1,int(-2e9)));
        if (it==vh.begin()){
            return 0;
        }
        int l=0,r=(it-vh.begin())-1;
        int res = st.get_cnt_more_equal(l,r,-y);
//        if (x==1 && y==1){
//            cout<<"x y res :: "<<x<<" "<<y<<" "<<res<<"\n";
//        }
//        if (x==0 && y==0){
//            cout<<"x y res :: "<<x<<" "<<y<<" "<<res<<"\n";
//        }
        return res;
    };
 
    auto check=[&](int x,int y,int d,int& rem)
    {
        if (rem==-1){
            rem=get_in_square(x,y);
        }
        assert(d>0);
        return get_in_square(x+d,y+d)==rem;
    };
 
    auto find_max_d=[&](int X,int Y)
    {
        int l=0,r=min(2e9-X,2e9-Y);
        int rem=-1;
        if (check(X,Y,r,rem)){
            return mp(true, r);
        }
        else{
            while (r-l>0){
                int m=(l+r+1)/2;
                if (check(X,Y,m,rem)){
                    l=m;
                }
                else{
                    r=m-1;
                }
            }
            return mp(false,l);
        }
    };
 
    auto precalc=[&]{
        int X=0,Y=0;
        while (1){
//            cout<<"loser :: "<<X<<" "<<Y<<"\n";
            pair<bool,int> d = find_max_d(X,Y);
            add_losers(X,Y,d.sec);
 
            if (d.fir){
                break;
            }
            else{
                X+=d.sec+1;
                Y+=d.sec+1;
                while (1){
                    if (have_X(X,Y)){
                        X++;
                    }
                    else if (have_Y(X,Y)){
                        Y++;
                    }
                    else{
                        break;
                    }
                }
            }
        }
    };
 
    precalc();
 
    sort(all(losers));
 
    if ((clock()-start)/CLOCKS_PER_SEC>1){
        exit(1);
    }
 
    auto is_loser=[&](int a,int b){
        if (losers_default.count(mp(a,b))){
            return true;
        }
 
        auto l = lower_bound(all(losers),mp(a-b,mp(int(-2e9),int(-2e9))));
        auto r = lower_bound(all(losers),mp(a-b+1,mp(int(-2e9),int(-2e9))));
 
        if (l==r){
            return false;
        }
 
        auto it = lower_bound(l,r,mp(a-b,mp(a+1,int(-2e9))));
        if (it==l){
            return false;
        }
 
        it--;
        return (*it).sec.sec>=a;
//return true;
    };
 
    for (int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
 
        if (is_loser(a,b)){
            cout<<"LOSE"<<"\n";
        }
        else{
            cout<<"WIN"<<"\n";
        }
    }
}