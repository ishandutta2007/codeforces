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

const int max_n = 1e5+10, inf = 1000111222;

int n;
int x[max_n];
int y[max_n];
int c[max_n];

int xx[max_n];
int yy[max_n];
int cc[max_n];

int to_build_2[max_n];
int to_build_3[max_n];

namespace segment_tree {
    int cnt2[4 * max_n];
    int cnt3[4 * max_n];

    void build(int v, int l, int r, int a[], int b[]) {
        if (l == r) {
            cnt2[v] = a[l];
            cnt3[v] = b[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a, b);
        build(2 * v + 1, mid + 1, r, a, b);
        cnt2[v]=cnt2[v*2]+cnt2[v*2+1];
        cnt3[v]=cnt3[v*2]+cnt3[v*2+1];
    }

    void update(int v, int l, int r, int x, int value) {
        if (l == r) {
            cnt2[v]+=(value==+2);
            cnt2[v]-=(value==-2);
            cnt3[v]+=(value==+3);
            cnt3[v]-=(value==-3);
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        cnt2[v]=cnt2[v*2]+cnt2[v*2+1];
        cnt3[v]=cnt3[v*2]+cnt3[v*2+1];
    }

    int get_ans(int v,int l,int r,int input_left2=0,int input_right_3=0)
    {
        if (l==r){
            return max(min(input_left2+cnt2[v],input_right_3) , min(input_left2,cnt3[v]+input_right_3));
        }

        int m=(l+r)/2;
        if (input_left2+cnt2[v*2] > cnt3[v*2+1]+input_right_3){
            return get_ans(v*2,l,m,input_left2,cnt3[v*2+1]+input_right_3);
        }
        else{
            return get_ans(v*2+1,m+1,r,input_left2+cnt2[v*2],input_right_3);
        }
    }
}

int remember1[max_n];
vector<int> remember_2[max_n];
vector<int> remember_3[max_n];

int get_ans_kek()
{
    memset(to_build_2,0,sizeof(to_build_2));
    memset(to_build_3,0,sizeof(to_build_3));
    for (int i=0;i<max_n;i++){
        remember1[i]=0;
        remember_2[i].clear();
        remember_3[i].clear();
    }
    for (int i=0;i<4*max_n;i++){
        segment_tree::cnt2[i]=0;
        segment_tree::cnt3[i]=0;
    }

    for (int i=0;i<n;i++){
        if (cc[i]==0){
            remember1[xx[i]]++;
        }
        if (cc[i]==1){
//            segment_tree::update(1,0,max_n-1,yy[i],+2);
            to_build_2[yy[i]]++;
            remember_2[xx[i]].pb(i);
        }
        if (cc[i]==2){
//            segment_tree::update(1,0,max_n-1,yy[i],+3);
            to_build_3[yy[i]]++;
            remember_3[xx[i]].pb(i);
        }
    }

    segment_tree::build(1,0,max_n-1,to_build_2,to_build_3);

    int res=0;

    int cur1=0;
    for (int i=0;i<max_n;i++){
        cur1+=remember1[i];
        for (auto q:remember_2[i]){
            segment_tree::update(1,0,max_n-1,yy[q],-2);
        }
        for (auto q:remember_3[i]){
            segment_tree::update(1,0,max_n-1,yy[q],-3);
        }

        res=max(res,min(cur1,segment_tree::get_ans(1,0,max_n-1)));
    }

    return res;
}

int get_ans_lol()
{
    memset(to_build_2,0,sizeof(to_build_2));
    memset(to_build_3,0,sizeof(to_build_3));
    for (int i=0;i<max_n;i++){
        remember1[i]=0;
        remember_2[i].clear();
        remember_3[i].clear();
    }
    for (int i=0;i<4*max_n;i++){
        segment_tree::cnt2[i]=0;
        segment_tree::cnt3[i]=0;
    }

    for (int i=0;i<n;i++){
        if (cc[i]==0){
            remember1[xx[i]]++;
        }
        if (cc[i]==1){
//            segment_tree::update(1,0,max_n-1,xx[i],+2);
            to_build_2[xx[i]]++;
            remember_2[xx[i]].pb(i);
        }
        if (cc[i]==2){
//            segment_tree::update(1,0,max_n-1,xx[i],+3);
            to_build_3[xx[i]]++;
            remember_3[xx[i]].pb(i);
        }
    }

    segment_tree::build(1,0,max_n-1,to_build_2,to_build_3);

    int res=0;

    int cur1=0;
    for (int i=0;i<max_n;i++){
        cur1+=remember1[i];
        for (auto q:remember_2[i]){
            segment_tree::update(1,0,max_n-1,xx[q],-2);
        }
        for (auto q:remember_3[i]){
            segment_tree::update(1,0,max_n-1,xx[q],-3);
        }

        res=max(res,min(cur1,segment_tree::get_ans(1,0,max_n-1)));
    }

    return res;
}

const bool debug=0;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (debug){
        n=1e5;
        for (int i=0;i<n;i++){
            x[i]=rand();
            y[i]=rand();
            c[i]=rand()%3;
        }
    }
    else{
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>x[i]>>y[i]>>c[i];
            c[i]--;
        }
    }
    vector<int> vh_x;
    vector<int> vh_y;
    for (int i=0;i<n;i++){
        vh_x.pb(x[i]);
        vh_y.pb(y[i]);
    }
    sort(all(vh_x));
    sort(all(vh_y));
    for (int i=0;i<n;i++){
        x[i]=lower_bound(all(vh_x),x[i])-vh_x.begin();
        y[i]=lower_bound(all(vh_y),y[i])-vh_y.begin();
    }

    int ans=0;
    for (int iter=0;iter<4;iter++){
        vector<int> vh_x;
        vector<int> vh_y;
        for (int i=0;i<n;i++){
            vh_x.pb(x[i]);
            vh_y.pb(y[i]);
        }
        sort(all(vh_x));
        sort(all(vh_y));
        for (int i=0;i<n;i++){
            xx[i]=lower_bound(all(vh_x),x[i])-vh_x.begin();
            yy[i]=lower_bound(all(vh_y),y[i])-vh_y.begin();
        }

        vector<int> p(3);
        p[0]=0;
        p[1]=1;
        p[2]=2;
        do{
            for (int i=0;i<n;i++){
                cc[i]=p[c[i]];
            }
            ans=max(ans,get_ans_kek());
        }
        while (next_permutation(all(p)));

        for (int i=0;i<n;i++){
            swap(x[i],y[i]);
            y[i]*=-1;
        }
    }
    for (int iter=0;iter<2;iter++){
        vector<int> vh_x;
        vector<int> vh_y;
        for (int i=0;i<n;i++){
            vh_x.pb(x[i]);
            vh_y.pb(y[i]);
        }
        sort(all(vh_x));
        sort(all(vh_y));
        for (int i=0;i<n;i++){
            xx[i]=lower_bound(all(vh_x),x[i])-vh_x.begin();
            yy[i]=lower_bound(all(vh_y),y[i])-vh_y.begin();
        }

        vector<int> p(3);
        p[0]=0;
        p[1]=1;
        p[2]=2;
        do{
            
            
            
            for (int i=0;i<n;i++){
                cc[i]=p[c[i]];
            }
            ans=max(ans,get_ans_lol());
        }
        while (next_permutation(all(p)));

        for (int i=0;i<n;i++){
            swap(x[i],y[i]);
        }
    }

    cout<<ans*3<<"\n";
}