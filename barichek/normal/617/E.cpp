//#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
#include <set>
#include <queue>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <utility>
#include <time.h>
#include <complex>
#include <unordered_set>
#include <unordered_map>

#pragma GCC optimize("O3")
///#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define files_ds(name) name!=""?freopen(name".dat","r",stdin),freopen(name".sol","w",stdout):0
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

///---program start---///

#define arr (int)(2e6+10)

const int bsize=200;

vi vh[arr];
int a[arr];
int pref[arr];
ll ans[arr];
vector<pair<pii,int>> q;
int n,m,k;

bool cmp(const pair<pii,int>& lhs,const pair<pii,int>& rhs)
{
    return lhs.fir.fir/bsize<rhs.fir.fir/bsize||(lhs.fir.fir/bsize==rhs.fir.fir/bsize&&lhs.fir.sec<rhs.fir.sec);
}

int get(int val,int l,int r)
{
//    cout<<"get :: "<<val<<" "<<l<<" "<<r<<" :: "<<upper_bound(all(vh[val]),r)-lower_bound(all(vh[val]),l)<<"\n";
    return upper_bound(all(vh[val]),r)-lower_bound(all(vh[val]),l);
}

void do_sqrt()
{
    sort(all(q),cmp);
    int l=1,r=1;
    ll cur_ans=0;
    for (auto i:q){
        while (l>i.fir.fir){
            l--;
            /// work l
            cur_ans+=get(pref[l-1]^k,l,r-1);
            ///
        }
        while (r<=i.fir.sec){
            /// work r
            cur_ans+=get(pref[r]^k,l-1,r-1);
            ///
            r++;
        }
        while (l<i.fir.fir){
            /// work l
            cur_ans-=get(pref[l-1]^k,l,r-1);
            ///
            l++;
        }
        while (r>i.fir.sec+1){
            r--;
            /// work r
            cur_ans-=get(pref[r]^k,l-1,r-1);
            ///
        }
        ans[i.sec]=cur_ans;
    }
}

int32_t main()
{
    fast;
    cin>>n>>m>>k;
    vh[0].pb(0);
    for (int i=1;i<=n;i++){
        cin>>a[i];
        pref[i]=pref[i-1]^a[i];
        vh[pref[i]].pb(i);
    }
    for (int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        q.pb(mp(mp(l,r),i));
    }
    do_sqrt();
    for (int i=1;i<=m;i++){
        cout<<ans[i]<<"\n";
    }
}