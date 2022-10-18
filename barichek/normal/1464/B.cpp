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

const int max_n = 1e5+10, inf = 1000111222;

int suf0[max_n];
int suf1[max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    string s;
    cin>>s;
    int a,b;
    cin>>a>>b;
    if (a>b){
        swap(a,b);
        for (auto& i:s){
            if (i!='?'){
                i^='0'^'1';
            }
        }
    }

    string t=s;
    for (auto& i:t){
        if (i=='?'){
            i='1';
        }
    }

    for (int i=len(t)-1;i>=0;i--){
        suf0[i]=suf0[i+1]+(t[i]=='0');
        suf1[i]=suf1[i+1]+(t[i]=='1');
    }

    auto calc=[&](string t)
    {
        ll res=0;
        int cnt0=0;
        int cnt1=0;
        for (auto i:t){
            if (i=='0'){
                res+=1ll*b*cnt1;
                cnt0++;
            }
            else{
                res+=1ll*a*cnt0;
                cnt1++;
            }
        }
        return res;
    };

    ll cur_ans=calc(t);
    ll ans = cur_ans;
    int cnt0=0;
    int cnt1=0;
    for (int i=0;i<len(t);i++){
        if (s[i]=='?'){
            // change 1 to 0 and upd ans
            cur_ans-=1ll*cnt0*a;
            cur_ans-=1ll*suf0[i+1]*b;

            cur_ans+=1ll*suf1[i+1]*a;
            cur_ans+=1ll*cnt1*b;

            ans=min(ans,cur_ans);

            cnt0++;
        }
        else{
            if (t[i]=='0'){
                cnt0++;
            }
            else{
                cnt1++;
            }
        }
    }

    cout<<ans<<"\n";
}