//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")

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

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

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
const ll inf=1e18+10;

///---program start---///

int n[3];
vi v[3];
int p[3];

int sqr(int a)
{
    return a*a;
}

int cost(int a,int b,int c)
{
    return sqr(a-b)+sqr(a-c)+sqr(b-c);
}

void upd(int& ans,int a,int b,int c)
{
    int cur_cost=cost(a,b,c);
    if (cur_cost<ans){
        ans=cur_cost;
    }
}

void solve()
{
    for (int i=0;i<3;i++){
        cin>>n[i];
    }
    for (int i=0;i<3;i++){
        v[i].resize(n[i]);
        for (int j=0;j<n[i];j++){
            cin>>v[i][j];
        }
        sort(all(v[i]));
    }
    int ans=cost(v[0][0],v[1][0],v[2][0]);
    p[0]=0;
    p[1]=1;
    p[2]=2;
    do{
        int a=p[0];
        int b=p[1];
        int c=p[2];
        int pp=0;
        for (int j=0;j<n[a];j++){
            while (pp<n[b] && v[b][pp]<v[a][j]){
                pp++;
            }
            if (pp!=n[b]){
                int A=v[a][j];
                int B=v[b][pp];
                int id = lower_bound(all(v[c]),(A+B)/2)-v[c].begin();
                if (id!=len(v[c])){
                    upd(ans,A,B,v[c][id]);
                }
                if (id!=0){
                    upd(ans,A,B,v[c][id-1]);
                }
            }
        }
    }
    while (next_permutation(p,p+3));
    cout<<ans<<"\n";
}

signed main()
{
    #ifdef __APPLE__
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}