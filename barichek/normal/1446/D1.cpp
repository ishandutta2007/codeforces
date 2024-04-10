#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")

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
const int maxA=101;

void maximize(int& a,int b)
{
    if (a<b){
        a=b;
    }
}

int a[max_n];
int cnt[maxA+10];

int buf[2*max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int M=max_element(cnt,cnt+maxA)-cnt;

    int ans=0;

    auto get=[&](int j)
    {
        for (int i=0;i<2*max_n;i++){
            buf[i]=-1e9;
        }

        int res=0;

        int pref_M=0;
        int pref_j=0;

        for (int i=1;i<=n;i++){
            // as l
            maximize(buf[max_n+(pref_M-pref_j)], -i);

            if (a[i]==M){
                pref_M++;
            }
            if (a[i]==j){
                pref_j++;
            }

            // as r
            maximize(res,i+1 + buf[max_n+(pref_M-pref_j)]);
        }

        return res;
    };

    for (int i=1;i<=maxA;i++){
        if (i!=M){
            ans=max(ans,get(i));
        }
    }
    cout<<ans<<"\n";
}