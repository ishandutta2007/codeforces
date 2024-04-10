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

int f_T;

pair<ll,int> f[2][8*max_n];

void f_normalize(pair<ll,int>& ff)
{
    if (ff.sec<f_T){
        ff=mp(0,f_T);
    }
}

void f_upd(int id,int pos,ll val)
{
    for (int i=pos;i<8*max_n;i|=i+1){
        f_normalize(f[id][i]);
        f[id][i].fir+=val;
    }
}

ll f_get(int id,int pos)
{
    ll res=0;
    for (int i=pos;i>=0;i&=i+1,i--){
        f_normalize(f[id][i]);
        res+=f[id][i].fir;
    }
    return res;
}

ll f_get(int id,int l,int r)
{
    if (l>r){
        return 0;
    }
    return f_get(id,r)-f_get(id,l-1);
}

int x[max_n];
int p[max_n];

int ans_fixed[max_n];
ll real_ans[3*max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;
    while (test--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,pii>> poses;
        for (int i=0;i<n;i++){
            cin>>x[i]>>p[i];
            poses.pb(mp(x[i]-p[i],mp(i,-1)));
            poses.pb(mp(x[i],mp(i,0)));
            poses.pb(mp(x[i]+p[i],mp(i,+1)));
        }
        sort(all(poses));

        vector<int> vh;
        for (auto i:poses){
            vh.pb(i.fir);
        }
        sort(all(vh));
        vh.resize(unique(all(vh))-vh.begin());
        auto get_vh_id=[&](int val)
        {
            return lower_bound(all(vh),val)-vh.begin();
        };

        for (int i=0;i<n;i++){
            ans_fixed[i]=0;
        }
        for (int i=0;i<3*n;i++){
            real_ans[i]=0;
        }
        {
            f_T++;
            for (int i=0;i<len(poses);){
                int j=i;
                while (j<len(poses) && poses[j].fir==poses[i].fir){
                    j++;
                }
                /// [i;j)

                for (int k=i;k<j;k++){
                    if (1){
                        int cnt=f_get(0,get_vh_id(poses[k].fir),len(vh)-1);
                        ll sum=f_get(1,get_vh_id(poses[k].fir),len(vh)-1);
//                        cerr<<poses[k].fir<<" :: "<<cnt<<" "<<sum<<"\n";
                        real_ans[k]+=sum-1ll*poses[k].fir*cnt;
                    }
                }
                for (int k=i;k<j;k++){
                    if (poses[k].sec.sec==0){
                        f_upd(0,get_vh_id(p[poses[k].sec.fir]+poses[k].fir),+1);
                        f_upd(1,get_vh_id(p[poses[k].sec.fir]+poses[k].fir),p[poses[k].sec.fir]+poses[k].fir);
                    }
                }

                i=j;
            }
        }
        {
            f_T++;
            for (int i=len(poses)-1;i>=0;){
                int j=i;
                while (j>=0 && poses[j].fir==poses[i].fir){
                    j--;
                }
                /// (j;i]

                for (int k=i;k>j;k--){
                    if (poses[k].sec.sec==0){
//                        cerr<<"upd :: "<<poses[k].fir<<" "<<get_vh_id(poses[k].fir-p[poses[k].sec.fir])<<"\n";
                        f_upd(0,get_vh_id(poses[k].fir-p[poses[k].sec.fir]),+1);
                        f_upd(1,get_vh_id(poses[k].fir-p[poses[k].sec.fir]),p[poses[k].sec.fir]-poses[k].fir);
                    }
                }
                for (int k=i;k>j;k--){
                    if (1){
                        int cnt=f_get(0,0,get_vh_id(poses[k].fir));
                        ll sum=f_get(1,0,get_vh_id(poses[k].fir));
                        real_ans[k]+=sum+1ll*poses[k].fir*cnt;
//                        cerr<<"kek :: "<<poses[k].fir<<" "<<cnt<<" "<<sum<<"\n";
//                        cerr<<"getted :: "<<get_vh_id(poses[k].fir)<<"\n";
                    }
                }

                i=j;
            }
        }
//        D{
//            cerr<<"real_ans :: ";
//            for (int i=0;i<len(poses);i++){
//                cerr<<poses[i].fir<<" "<<poses[i].sec.fir<<" "<<poses[i].sec.sec<<" with rea_ans :: "<<real_ans[i]<<"\n";
//            }
//        };
        int all_bad=0;
        for (int i=0;i<len(poses);i++){
            if (real_ans[i]>m){
                all_bad++;
            }
        }


        vector<ll> vh2;
        for (int i=0;i<len(poses);i++){
            if (real_ans[i]>m){
                vh2.pb((real_ans[i]-m)-poses[i].fir);
                vh2.pb((real_ans[i]-m)+poses[i].fir);
            }
            if (poses[i].sec.sec==0){
                vh2.pb(p[poses[i].sec.fir]-poses[i].fir);
                vh2.pb(p[poses[i].sec.fir]+poses[i].fir);
            }
        }
        sort(all(vh2));
        vh2.resize(unique(all(vh2))-vh2.begin());
        auto get_vh2_id=[&](ll val)
        {
            return lower_bound(all(vh2),val)-vh2.begin();
        };
        {
            f_T++;
            for (int i=0;i<len(poses);){
                int j=i;
                while (j<len(poses) && poses[j].fir==poses[i].fir){
                    j++;
                }
                /// [i;j)

                for (int k=i;k<j;k++){
                    if (real_ans[k]>m){
//                        cerr<<"upd :: "<<poses[k].fir<<" "<<(real_ans[k]-m)-poses[k].fir<<"\n";
                        f_upd(0,get_vh2_id((real_ans[k]-m)-poses[k].fir),+1);
                    }
                }
                for (int k=i;k<j;k++){
                    if (poses[k].sec.sec==0){
//                        cerr<<"get :: "<<poses[k].fir<<" "<<p[poses[k].sec.fir]-poses[k].fir<<"\n";
                        int cnt=f_get(0,0,get_vh2_id(p[poses[k].sec.fir]-poses[k].fir));
                        ans_fixed[poses[k].sec.fir]+=cnt;
                    }
                }

                i=j;
            }
        }
        {
            f_T++;
            for (int i=len(poses)-1;i>=0;){
                int j=i;
                while (j>=0 && poses[j].fir==poses[i].fir){
                    j--;
                }
                /// (j;i]

                for (int k=i;k>j;k--){
                    if (poses[k].sec.sec==0){
                        int cnt=f_get(0,0,get_vh2_id(p[poses[k].sec.fir]+poses[k].fir));
                        ans_fixed[poses[k].sec.fir]+=cnt;
                    }
                }
                for (int k=i;k>j;k--){
                    if (real_ans[k]>m){
                        f_upd(0,get_vh2_id((real_ans[k]-m)+poses[k].fir),+1);
                    }
                }

                i=j;
            }
        }

//        LOG(all_bad);
        for (int i=0;i<n;i++){
//            LOG(i,ans_fixed[i]);
            assert(ans_fixed[i]<=all_bad);
            if (ans_fixed[i]==all_bad){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
        cout<<"\n";
    }
}