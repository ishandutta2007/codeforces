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

const int max_n = 200+10, inf = 1000111222;

bool closed[max_n];

bool is_in(int l,int r,int x)
{
    return l<=x && x<=r;
}

bool is_ok1(const pii& a,const pii& b)
{
    if (a.fir<a.sec){
        return ((is_in(a.fir,a.sec,b.fir) && !is_in(a.fir,a.sec,b.sec)) || (is_in(a.fir,a.sec,b.sec) && !is_in(a.fir,a.sec,b.fir)));
    }
    else{
        return ((is_in(a.sec,a.fir,b.fir) && !is_in(a.sec,a.fir,b.sec)) || (is_in(a.sec,a.fir,b.sec) && !is_in(a.sec,a.fir,b.fir)));
    }
}

bool is_ok(const pii& a,const pii& b)
{
    return is_ok1(a,b) || is_ok1(b,a);
}

int get(const vector<pii>& a)
{
    int res=0;
    for (int i=0;i<len(a);i++){
        for (int j=i+1;j<len(a);j++){
            res+=is_ok(a[i],a[j]);
        }
    }
    return res;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        memset(closed,0,sizeof(closed));
        int n,k;
        cin>>n>>k;
        vector<pii> a;
        for (int i=0;i<k;i++){
            int x,y;
            cin>>x>>y;
            closed[x]=1;
            closed[y]=1;
            a.pb(mp(x,y));
        }
        vector<int> open;
        for (int i=1;i<=2*n;i++){
            if (!closed[i]){
                open.pb(i);
            }
        }

        int ans=0;
        if (len(open)==0){
            ans=get(a);
        }
        else{
            int iter=len(open);
            for (int i=0;i<iter;i++){
                vector<pii> cur_a=a;
                for (int j=0;j<len(open)/2;j++){
                    cur_a.pb(mp(open[j],open[len(open)/2+j]));
                }
                ans=max(ans,get(cur_a));

                open.pb(open[0]);
                open.erase(open.begin());
            }
        }
        cout<<ans<<"\n";
    }
}