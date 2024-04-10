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

const int MASKS=32;

struct node
{
    int cost[MASKS];

    node()
    {
        for (int i=0;i<MASKS;i++){
            cost[i]=inf;
        }
    }

    void upd_node(char c)
    {
        for (int i=0;i<MASKS;i++){
            cost[i]=inf;
        }
//        cout<<"lol1"<<"\n";
        for (char cc='a';cc<='c';cc++){
            if (cc==c){
                cost[1ll<<(cc-'a')]=0;
            }
            else{
                cost[1ll<<(cc-'a')]=1;
            }
        }
//        cout<<"lol2"<<"\n";
    }
};

int to_mask[MASKS][MASKS];

bool get_bit(int mask,int bit)
{
    return (mask>>bit)&1;
}

void fullfill(int& a)
{
    if (get_bit(a,3)){
        a|=(1ll<<0);
        a|=(1ll<<1);
    }
    if (get_bit(a,4)){
        a|=(1ll<<1);
        a|=(1ll<<2);
    }
}

void close_bit(int &a,int b)
{
    if (get_bit(a,b)){
        a^=(1ll<<b);
    }
}

void fill_to_mask()
{
    for (int m1=0;m1<MASKS;m1++){
        for (int m2=0;m2<MASKS;m2++){
            int mm1=m1;
            int mm2=m2;
            fullfill(mm1);
            fullfill(mm2);
            int res=0;
            bool bad=0;
            for (int bit2=0;bit2<5;bit2++){
                if (get_bit(mm2,bit2)){
                    res|=(1ll<<bit2);
                }
            }
            for (int bit1=0;bit1<5;bit1++){
                if (get_bit(mm1,bit1)){
                    res|=(1ll<<bit1);

                    for (int bit2=0;bit2<5;bit2++){
                        if (get_bit(mm2,bit2)){
                            int b1=bit1;
                            int b2=bit2;

                            if (b1==0 && b2==1){
                                res|=(1ll<<3);
                            }
                            if (b1==1 && b2==2){
                                res|=(1ll<<4);
                            }

                            if (b1==0 && b2==4){
                                bad=1;
                            }
                            if (b1==3 && b2==2){
                                bad=1;
                            }
                            if (b1==3 && b2==4){
                                bad=1;
                            }
                        }
                    }
                }
            }

            if (bad){
                res=-1;
            }
            else{
                if (get_bit(res,3)){
                    close_bit(res,0);
                    close_bit(res,1);
                }
                if (get_bit(res,4)){
                    close_bit(res,1);
                    close_bit(res,2);
                }
            }

            to_mask[m1][m2]=res;
        }
    }
}

inline int get_to_mask(int m1,int m2)
{
    return to_mask[m1][m2];
}

void minimize(int& a,int b)
{
    if (a>b){
        a=b;
    }
}

bool to_skip[MASKS];

void merge(node& res,const node& l,const node& r)
{
    for (int i=0;i<MASKS;i++){
        res.cost[i]=inf;
    }
    for (int i=0;i<MASKS;i++){
        if (to_skip[i]){
            continue;
        }
        for (int j=0;j<MASKS;j++){
            if (to_skip[j]){
                continue;
            }
            int to=get_to_mask(i,j);
            if (to!=-1){
                minimize(res.cost[to],l.cost[i]+r.cost[j]);
            }
        }
    }
}

struct segment_tree {
    node sum[4 * max_n];

    void update(int v, int l, int r, int x, char value) {
//        cout<<l<<" "<<r<<"\n";
        if (l == r) {
            sum[v].upd_node(value);
//            cout<<"on l r :: "<<" ["<<l<<";"<<r<<"] "<<"\n";
//            for (int i=0;i<MASKS;i++){
//                cout<<bitset<5>(i)<<" :: "<<sum[v].cost[i]<<"\n";
//            }
//            cout<<"\n";
//            cout<<"\n";
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        merge(sum[v], sum[2 * v], sum[2 * v + 1]);
//        cout<<"on l r :: "<<" ["<<l<<";"<<r<<"] "<<"\n";
//        for (int i=0;i<MASKS;i++){
//            cout<<bitset<5>(i)<<" :: "<<sum[v].cost[i]<<"\n";
//        }
//        cout<<"\n";
//        cout<<"\n";
    }
};

segment_tree st;

const bool debug=0;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill_to_mask();
    for (int i=0;i<MASKS;i++){
        if (get_bit(i,3) && (get_bit(i,0) || get_bit(i,1))){
            to_skip[i]=1;
        }
        if (get_bit(i,4) && (get_bit(i,1) || get_bit(i,2))){
            to_skip[i]=1;
        }
    }

//    cout<<"kek :: "<<bitset<5>(to_mask[1ll<<1][1<<0])<<"\n";

    int n,q;
    string s;
    if (debug){
        n=1e5;
        q=1e5;
        for (int i=0;i<n;i++){
            s+=char('a'+(rand()%3));
        }
    }
    else{
        cin>>n>>q;
        cin>>s;
    }
    for (int i=0;i<n;i++){
//        cout<<"update :: "<<i<<"\n";
        st.update(1,0,n-1,i,s[i]);
    }
//    cout<<"start ans :: "<<*min_element(st.sum[1].cost,st.sum[1].cost+MASKS)<<"\n";
    while (q--){
        int pos;
        char c;
        if (debug){
            pos=rand()%n;
            c=char('a'+(rand()%3));
        }
        else{
            cin>>pos>>c;
            pos--;
        }
        st.update(1,0,n-1,pos,c);

        cout<<*min_element(st.sum[1].cost,st.sum[1].cost+MASKS)<<"\n";
    }
}