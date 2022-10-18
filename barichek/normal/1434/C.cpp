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

const int max_n = -1, inf = 1000111222;

const bool brute=0;

int get_brute(int a,int b,int c,int d)
{
    ll res=0;
    for (int kk=0;kk<=100;kk++){
        ll k=kk;
        ll ans=-k*a + b*k*(k-1)*d/2;
        res=max(res,-ans);
    }
    return res;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        if (a>b*c){
            cout<<-1<<"\n";
            continue;
        }
        if (d>c){
            cout<<a<<"\n";
            continue;
        }
        if (brute){
            cout<<"brute :: "<<get_brute(a,b,c,d)<<"\n";
        }
//        for (int kk=1;kk<=20;kk++){
//            ll k=kk;
//            ll ans=-k*a + b*k*(k-1)*d/2;
//            cout<<kk<<" "<<-ans<<"\n";
//        }
        ll k=min(a/(d*b)+1, c/d+1);
        ll ans2=2*k*a - b*k*(k-1)*d;
        cout<<ans2/2<<"\n";
    }
}