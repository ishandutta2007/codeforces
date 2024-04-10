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

ll pref[2*max_n];
ll get_sum(int l,int r)
{
    if (l>r){
        return 0;
    }
    return pref[r]-(l==0 ? 0 : pref[l-1]);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    srand(time(0)^size_t(new char));

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,q;
    cin>>n>>m>>q;

    vector<pii> v;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        v.pb(mp(a,0));
    }
    for (int i=0;i<m;i++){
        int b;
        cin>>b;
        v.pb(mp(b,1));
    }
    sort(all(v));
    for (int i=0;i<len(v);i++){
        pref[i]=(i==0 ? 0 : pref[i-1]) + v[i].fir;
    }

    vector<pii> req(q);
    for (int i=0;i<q;i++){
        cin>>req[i].fir;
        req[i].sec=i;
    }
    sort(all(req));

    vector<ll> ans(q,-1);

    vector<pii> diffs;
    for (int i=0;i+1<len(v);i++){
        diffs.pb(mp(v[i+1].fir-v[i].fir,i));
    }
    sort(all(diffs));
    reverse(all(diffs));

    ll cur_ans=0;
    set<pii> starts;
    for (int i=0;i<len(v);i++){
        starts.insert(mp(i,v[i].sec==0));
        cur_ans+=(v[i].sec==0 ? v[i].fir : 0);
    }
    starts.insert(mp(len(v),inf));

    for (auto qq:req){
        int k=qq.fir;
        int req_id=qq.sec;
        while (!diffs.empty() && diffs.back().fir<=k){
            auto my_union=[&](int pos)
            {
                auto it2=starts.lower_bound(mp(pos,0));
                assert(it2->fir==pos);

                auto it1=it2;
                it1--;

                auto it3=it2;
                it3++;

                auto local_ans=[&](int l,int r,int cnt)
                {
                    return get_sum(r-cnt+1,r);
                };

                cur_ans-=local_ans(it1->fir,it2->fir-1,it1->sec);
                cur_ans-=local_ans(it2->fir,it3->fir-1,it2->sec);
                int new_start=it1->fir;
                int new_cnt=it1->sec+it2->sec;
                cur_ans+=local_ans(it1->fir,it3->fir-1,new_cnt);
                starts.erase(it1);
                starts.erase(it2);
                starts.insert(mp(new_start,new_cnt));
            };

            my_union(diffs.back().sec+1);
            diffs.pop_back();
        }
        ans[req_id]=cur_ans;
    }

    for (auto i:ans){
        cout<<i<<"\n";
    }
}