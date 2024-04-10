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

ll tree[2][4*max_n];

void upd(int id,int v,int l,int r,int tl,int tr,ll value)
{
    if (l>tr||r<tl){
        return;
    }
    if (l>=tl&&r<=tr){
        tree[id][v]=min(tree[id][v],value);
        return;
    }
    int m=(l+r)/2;
    upd(id,v*2,l,m,tl,tr,value);
    upd(id,v*2+1,m+1,r,tl,tr,value);
}

ll get(int id,int v,int l,int r,int pos)
{
    if (l==r){
        return tree[id][v];
    }
    int m=(l+r)/2;
    ll res=tree[id][v];
    if (pos<=m){
        res=min(res,get(id,v*2,l,m,pos));
    }
    else{
        res=min(res,get(id,v*2+1,m+1,r,pos));
    }
    return res;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d",&n);
    vector<pii> a(n);
    ll sum_c=0;
    for (int i=0;i<n;i++){
        scanf("%d%d",&a[i].fir,&a[i].sec);
        sum_c+=a[i].sec;
    }
    sort(all(a));
    for (int i=0;i<2;i++){
        for (int j=0;j<4*max_n;j++){
            tree[i][j]=1e18;
        }
    }
    upd(0,1,0,n-1,0,0,0);
    for (int i=0;i<n;i++){
        ll cur_dp=min(get(0,1,0,n-1,i), a[i].fir + get(1,1,0,n-1,i));
        if (i==n-1){
            cout<<sum_c+cur_dp<<"\n";
        }
        int right=lower_bound(all(a),mp(a[i].fir+a[i].sec+1,-1))-a.begin()-1;
        upd(0,1,0,n-1,i,right,cur_dp);
        if (right+1<=n-1){
            upd(1,1,0,n-1,right+1,n-1,cur_dp-a[i].fir-a[i].sec);
        }
    }
}