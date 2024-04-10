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

const int max_n = 100+10, inf = 1000111222;

int n;
int cnt[2][max_n];

ll get_sum(int id,int take)
{
    ll res=0;
    for (int i=100;i>=0;i--){
        if (cnt[id][i]>take){
            res+=1ll*i*take;
            return res;
        }
        else{
            res+=1ll*i*cnt[id][i];
            take-=cnt[id][i];
        }
    }
    return res;
}

bool check(int x)
{
    cnt[0][100]+=x;

    ll sum1=get_sum(0,(n+x)-(n+x)/4);
    ll sum2=get_sum(1,(n+x)-(n+x)/4);

    cnt[0][100]-=x;

    return sum1>=sum2;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        cin>>n;
        memset(cnt,0,sizeof(cnt));
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            cnt[0][a]++;
        }
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            cnt[1][a]++;
        }
        int l=0,r=1e9;
        while (r-l>0){
            int m=(l+r)/2;
            if (check(m)){
                r=m;
            }
            else{
                l=m+1;
            }
        }
        cout<<l<<"\n";
    }
}