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

const int max_n = 2e5+10, inf = 1000111222;
const int NNN=1e6+10;
const int md=998244353;

int bpow(int a,int n)
{
    int res=1;
    while (n){
        if (n&1){
            res=1ll*res*a%md;
        }
        n/=2;
        a=1ll*a*a%md;
    }
    return res;
}

int inv(int a)
{
    return bpow(a,md-2);
}

struct item
{
    int prior,size,Lval,Rval;
    int left,right;
    item(int Lval_=0,int Rval_=0)
    {
        prior=rand()^(rand()<<15);
        Lval=Lval_;
        Rval=Rval_;
        size=Rval-Lval+1;
        left=0;
        right=0;
    }
};

const int V=4*max_n+10;
item all_items[V];
int last_item=0;

int new_item(int Lval,int Rval)
{
    all_items[++last_item]=*new item(Lval,Rval);
    assert(last_item<V);
    return last_item;
}

int get_size(int t)
{
    return t?all_items[t].size:0;
}

void recalc(int t)
{
    if (!t) return;
    all_items[t].size=get_size(all_items[t].left)+get_size(all_items[t].right)+(all_items[t].Rval-all_items[t].Lval+1);
}

void split(int t,int& l,int& r,int k)
{
    if (!t)
        return void(l=r=0);
//    cout<<"split :: "<<"["<<t->Lval<<";"<<t->Rval<<"] :: "<<k<<"\n";
    int size_l=get_size(all_items[t].left);
//    cout<<"size_l :: "<<size_l<<"\n";
    if (size_l>=k)
        split(all_items[t].left,l,all_items[t].left,k), r=t;
    else if (size_l+(all_items[t].Rval-all_items[t].Lval+1)>k){
        split(all_items[t].left,l,all_items[t].left,size_l); r=t;
    }
    else
        split(all_items[t].right,all_items[t].right,r,k-size_l-(all_items[t].Rval-all_items[t].Lval+1)), l=t;
    recalc(l);
    recalc(r);
}

void merge(int &t,int l,int r)
{
    if (!l||!r)
        return void(t=l?l:r);
    if (all_items[l].prior>all_items[r].prior)
        merge(all_items[l].right,all_items[l].right,r), t=l;
    else
        merge(all_items[r].left,l,all_items[r].left), t=r;
    recalc(t);
}

//void print(int t)
//{
//    if (!t) return;
//    print(t->left);
//    cout<<"["<<t->Lval<<" "<<t->Rval<<"] ";
//    print(t->right);
//}

//main()
//{
//    int n,m;
//    cin>>n>>m;
//    pitem Tree=null;
//    for (int i=1;i<=n;i++)
//        merge(Tree,Tree,new item(i));
//    while (m--)
//    {
//        int l,r;
//        cin>>l>>r;
//        pitem t1,t2,t3;
//        split(Tree,Tree,t3,r);
//        split(Tree,t1,t2,l-1);
//        merge(Tree,t2,t1);
//        merge(Tree,Tree,t3);
//    }
//    print(Tree);
//}

int buf[max_n];

const bool debug=0;
const bool naive=0;

int f[NNN];
int rf[NNN];

int C(int n,int k)
{
    return 1ll*f[n]*rf[n-k]%md*rf[k]%md;
}

int my_preds[max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    f[0]=1;
    for (int i=1;i<NNN;i++){
        f[i]=1ll*f[i-1]*i%md;
    }
    rf[NNN-1]=inv(f[NNN-1]);
    for (int i=NNN-2;i>=0;i--){
        rf[i]=1ll*rf[i+1]*(i+1)%md;
    }

    srand(time(0)^ll(new char));
//    srand(127);

    int test;
    if (debug){
        test=1;
    }
    else{
        scanf("%d",&test);
    }
    while (test--){
        vector<int> naive_vec;

        int n,m;
        if (debug){
            n=2e5;
            m=n-1;
        }
        else{
            scanf("%d%d",&n,&m);
        }
//        cout<<"n m :: "<<n<<" "<<m<<"\n";
        int tree=0;
        vector<int> to_clear;

        int last_seen=0;

        for (int iter=1;iter<=m;iter++){
            int x,y;
            if (debug){
                x=iter+1;
                y=rand()%iter+1;
            }
            else{
                scanf("%d%d",&x,&y);
            }
            swap(x,y);
//            cout<<"tree at start x y :: "<<x<<" "<<y<<"\n";
//            print(tree);
//            cout<<"\n";

            if (last_seen+1<=y-1){
                if (naive){
                    for (int i=last_seen+1;i<=y-1;i++){
                        naive_vec.pb(i);
                    }
                }
                merge(tree,tree,new_item(last_seen+1,y-1));
            }
            last_seen=y;

//            cout<<"after small merge x y :: "<<x<<" "<<y<<"\n";
//            print(tree);
//            cout<<"\n";

            int t1,t2;
            split(tree,t1,t2,x-1);
//            cout<<"split x :: "<<x<<"\n";
//            print(t1);
//            cout<<"\n";
//            print(t2);
//            cout<<"\n";
//            cout<<"------"<<"\n";
            int LL = t2;
            int predLL=0;
            int sz1=0;
            while (all_items[LL].left){
                my_preds[sz1++]=LL;
                predLL=LL;
                LL=all_items[LL].left;
            }
            int here_index = x-get_size(t1);
            int here_value = all_items[LL].Lval+here_index-1;
//            cout<<"here_value :: "<<here_value<<"\n";
            int before_here_value=0;
            if (here_index > 1){
                before_here_value = here_value-1;
            }
            else{
                int RR = t1;
                while (RR && all_items[RR].right){
                    RR=all_items[RR].right;
                }
                if (RR){
                    before_here_value = all_items[RR].Rval;
                }
            }
//            cout<<"before_here_value :: "<<before_here_value<<"\n";
            if (naive){
                int naive_here_value = naive_vec[x-1];
                int naive_before_here_value = 0;
                if (x!=1){
                    naive_before_here_value=naive_vec[x-2];
                }
                if (naive_here_value!=here_value){
                    cout<<"bad here_value :: "<<here_value<<" "<<naive_here_value<<"\n";
                    return 1;
                }
                if (naive_before_here_value!=before_here_value){
                    cout<<"bad before_here_value :: "<<before_here_value<<" "<<naive_before_here_value<<"\n";
                    return 1;
                }
                naive_vec.insert(naive_vec.begin()+x-1,y);
            }

            if (predLL){
                all_items[predLL].left=all_items[LL].right;
                reverse(my_preds,my_preds+sz1);
                for (int i=0;i<sz1;i++){
                    recalc(my_preds[i]);
                }

                if (all_items[LL].Lval<=here_value-1){
                    merge(tree,t1,new_item(all_items[LL].Lval,here_value-1));
                }
                else{
                    tree=t1;
                }
                merge(tree,tree,new_item(y,y));
                merge(tree,tree,new_item(here_value,all_items[LL].Rval));
                merge(tree,tree,t2);
            }
            else{
                t2=all_items[LL].right;
                if (all_items[LL].Lval<=here_value-1){
                    merge(tree,t1,new_item(all_items[LL].Lval,here_value-1));
                }
                else{
                    tree=t1;
                }
                merge(tree,tree,new_item(y,y));
                merge(tree,tree,new_item(here_value,all_items[LL].Rval));
                merge(tree,tree,t2);
            }

            buf[y]=1;
            buf[before_here_value]=0;

            to_clear.pb(y);
        }

        int sum=0;
        for (auto i:to_clear){
            sum+=buf[i];
            buf[i]=0;
        }
//        cout<<"sum :: "<<sum<<"\n";

        auto PEREGORODKI=[&](int edinichki,int peregorodki){
            return C(edinichki+peregorodki,peregorodki);
        };

        cout<<PEREGORODKI(n-1-sum,n)<<"\n";
    }
}