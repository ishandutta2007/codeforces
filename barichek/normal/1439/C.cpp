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

const bool debug=0;
const bool naive=0;

ll sum[4*max_n];
int push[4*max_n];
int t_min[4*max_n];
int t_max[4*max_n];
int a[max_n];
int n,q;

void upd_info(int v)
{
    sum[v]=sum[v*2]+sum[v*2+1];
    t_min[v]=min(t_min[v*2],t_min[v*2+1]);
    t_max[v]=max(t_max[v*2],t_max[v*2+1]);
}

void build(int v,int l,int r)
{
    if (l==r){
        sum[v]=a[l];
        t_min[v]=a[l];
        t_max[v]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(2*v,l,m);
    build(2*v+1,m+1,r);
    upd_info(v);
}

void make_push(int v,int l,int m,int r)
{
    if (push[v]==0){
        return;
    }

    sum[v*2]=1ll*(m-l+1)*push[v];
    push[v*2]=push[v];
    t_min[v*2]=push[v];
    t_max[v*2]=push[v];

    sum[v*2+1]=1ll*(r-(m+1)+1)*push[v];
    push[v*2+1]=push[v];
    t_min[v*2+1]=push[v];
    t_max[v*2+1]=push[v];

    push[v]=0;
}

int first_smaller_or_equal(int v,int l,int r,int val)
{
    if (l==r){
        return l;
    }

    int m=(l+r)/2;
    make_push(v,l,m,r);
    upd_info(v);

    if (t_min[v*2]<=val){
        return first_smaller_or_equal(v*2,l,m,val);
    }
    else{
        return first_smaller_or_equal(v*2+1,m+1,r,val);
    }
}

void upd(int v,int l,int r,int tl,int tr,int val)
{
    if (l>tr||r<tl){
        return;
    }
    if (l>=tl&&r<=tr){
        sum[v]=1ll*(r-l+1)*val;
        push[v]=val;
        t_min[v]=val;
        t_max[v]=val;
        return;
    }

    int m=(l+r)/2;
    make_push(v,l,m,r);

    upd(v*2,l,m,tl,tr,val);
    upd(v*2+1,m+1,r,tl,tr,val);

    upd_info(v);
}

void do_pref_max_equal(int x,int y)
{
    if (t_min[1]>y){
        return;
    }
    int from = first_smaller_or_equal(1,1,n,y);
    if (from>x){
        return;
    }
    int to=x;

    upd(1,1,n,from,to,y);
}

pair<int,pii> buf[1000];
int buf_sz=0;

void cover_segment(int v,int l,int r,int tl,int tr)
{
    if (l>tr||r<tl){
        return;
    }
    if (l>=tl&&r<=tr){
        buf[buf_sz++]=mp(v,mp(l,r));
        return;
    }

    int m=(l+r)/2;
    make_push(v,l,m,r);

    cover_segment(v*2,l,m,tl,tr);
    cover_segment(v*2+1,m+1,r,tl,tr);

    upd_info(v);
}

int get_ans(int x,int y)
{
    int res=0;
    while (1){
//        cout<<t_min[1]<<" !!!!\n";
        if (t_min[1]>y){
            return res;
        }
        int from = first_smaller_or_equal(1,1,n,y);
        if (from<x){
            from=x;
        }

//        cout<<"from :: "<<from<<"\n";
//        cout<<y<<" !!\n";

        buf_sz=0;
        cover_segment(1,1,n,from,n);
        bool flag=0;
        for (int i=0;i<buf_sz;i++){
            int v=buf[i].fir;
            if (sum[v]<=y){
                res+=buf[i].sec.sec-buf[i].sec.fir+1;
                y-=sum[v];
            }
            else{
                int l=buf[i].sec.fir;
                int r=buf[i].sec.sec;
                while (l!=r){
                    int m=(l+r)/2;
                    make_push(v,l,m,r);
                    upd_info(v);

                    if (sum[v*2]<=y){
                        res+=(m-l+1);
                        y-=sum[v*2];

                        l=m+1;
                        v=v*2+1;
                    }
                    else{
                        r=m;
                        v=v*2;
                    }
                }
                if (sum[v]<=y){
                    y-=sum[v];
                    res++;
                }

                flag=1;

                break;
            }
        }

        if (!flag){
            break;
        }
    }
    return res;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    if (debug){
        n=100;
        q=1000;
        for (int i=n;i>=1;i--){
            a[i]=a[i+1]+rand()%5+1;
        }
    }
    else{
        scanf("%d%d",&n,&q);
        for (int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
    }
    build(1,1,n);
    while (q--){
        int t,x,y;
        if (debug){
            t=rand()%2+1;
            x=rand()%n+1;
            y=rand()%10000+1;
        }
        else{
            scanf("%d%d%d",&t,&x,&y);
        }
        if (t==1){
            if (naive){
                for (int i=1;i<=x;i++){
                    a[i]=max(a[i],y);
                }
            }
            do_pref_max_equal(x,y);
        }
        else{
            int ans=get_ans(x,y);
            if (naive){
                int naive_ans=0;
                int yy=y;
                for (int i=x;i<=n;i++){
                    if (a[i]<=yy){
                        yy-=a[i];
                        naive_ans++;
                    }
                }
                assert(naive_ans==ans);
            }
            cout<<ans<<"\n";
        }
    }
}