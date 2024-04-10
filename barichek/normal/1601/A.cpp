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

const int max_log=30;

bool get_bit(int mask,int bit)
{
    return (mask>>bit)&1;
}

int a[max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    scanf("%d",&test);
    while (test--){
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int g=0;
        for (int b=0;b<max_log;b++){
            int cur=0;
            for (int i=0;i<n;i++){
                cur+=get_bit(a[i],b);
            }
            g=__gcd(g,cur);
        }
        for (int k=1;k<=n;k++){
            if (g%k==0){
                cout<<k<<" ";
            }
        }
        cout<<"\n";
    }
}