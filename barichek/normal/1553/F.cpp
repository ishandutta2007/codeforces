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

const int max_n = 3e5+10, inf = 1000111222;

pair<ll,int> operator + (pair<ll,int> a,pair<ll,int> b)
{
    return mp(a.fir+b.fir,a.sec+b.sec);
}

pair<ll,int> operator - (pair<ll,int> a,pair<ll,int> b)
{
    return mp(a.fir-b.fir,a.sec-b.sec);
}

pair<ll,int> f[max_n];

void upd(int pos,pair<ll,int> val)
{
    for (int i=pos;i<max_n;i|=i+1){
        f[i]=f[i]+val;
    }
}

pair<ll,int> get(int pos)
{
    pair<ll,int> res=mp(0,0);
    for (int i=pos;i>=0;i&=i+1,i--){
        res=res+f[i];
    }
    return res;
}

void clear()
{
    for (int i=0;i<max_n;i++){
        f[i]=mp(0,0);
    }
}

int a[max_n];
ll ans[max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    /// i<j
    for (int j=0;j<n;j++){
        for (int L=0;L<max_n;L+=a[j]){
            int R=L+a[j];
            if (R>max_n){
                R=max_n;
            }
            /// [L;R)
            pair<ll,int> cur_res=get(R-1)-get(L-1);
//            if (cur_res.sec){
//                cout<<L<<" "<<R<<" :: "<<j<<" :: "<<cur_res.fir<<" "<<cur_res.sec<<"\n";
//            }
            ans[j]+=cur_res.fir-1ll*L*cur_res.sec;
        }

        upd(a[j],mp(a[j],1));
    }

    /// j<i
    clear();
    for (int i=0;i<n;i++){
        pair<ll,int> cur_res=get(a[i]);
        ans[i]+=1ll*a[i]*cur_res.sec-cur_res.fir;
//        if (cur_res.sec){
//            cout<<i<<" :: "<<cur_res.fir<<" "<<cur_res.sec<<"\n";
//        }

        for (int L=0;L<max_n;L+=a[i]){
            int R=L+a[i];
            if (R>max_n){
                R=max_n;
            }
            /// [L;R)
            upd(L,mp(L,1));
            upd(R,mp(-L,-1));
        }
    }

    for (int i=0;i<n;i++){
        if (i){
            ans[i]+=ans[i-1];
        }
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}