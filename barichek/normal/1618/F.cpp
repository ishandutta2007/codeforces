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

ll reversed_bits(ll a)
{
    int bit=0;
    for (int i=0;i<62;i++){
        if (a&(1ll<<i)){
            bit=i;
        }
    }
    ll res=0;
    for (int i=0;i<=bit;i++){
        if (a&(1ll<<i)){
            res|=(1ll<<(bit-i));
        }
    }
    return res;
}

string ll_as_bit_string(ll x)
{
    int bit=0;
    for (int i=0;i<62;i++){
        if (x&(1ll<<i)){
            bit=i;
        }
    }
    string s(bit+1,'0');
    for (int i=0;i<=bit;i++){
        if (x&(1ll<<i)){
            s[i]='1';
        }
    }
    return s;
}

bool check(ll x,ll y)
{
    assert(x%2==1);

    auto internal_check=[&](ll x,ll y)
    {
        assert(x%2==1);

        string s=ll_as_bit_string(x);
        string t=ll_as_bit_string(y);
        for (int i=0;i+len(s)-1<len(t);i++){
            bool ok_pref=1;
            bool ok_suf=1;
            for (int j=0;j<i;j++){
                ok_pref&=(t[j]=='1');
            }
            for (int j=i+len(s);j<len(t);j++){
                ok_suf&=(t[j]=='1');
            }
            if (t.substr(i,len(s))==s && ok_pref && ok_suf){
                return 1;
            }
        }
        return 0;
    };
    return internal_check(x,y) || internal_check(reversed_bits(x),y);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ll x,y;
    cin>>x>>y;
    ll xx=x;
    while (xx%2==0){
        xx/=2;
    }
    bool ans=0;
    ans|=(x==y);
    ans|=(check(reversed_bits(x*2+1),y));
    ans|=(check(reversed_bits(xx),y));
    if (ans){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }
}