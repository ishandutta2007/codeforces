#pragma GCC optimize("Ofast", "unroll-loops")
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

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    const bool debug=0;

    int test;
    scanf("%d",&test);
    while (test--){
        int x,y;
        if (debug){
            x=2*(rand()%int(1e2))+2;
            y=2*(rand()%int(1e2))+2;
        }
        else{
            scanf("%d%d",&x,&y);
        }
        int n=-1;
        if (y<x){
            n=x+y;
        }
        else if (y==x){
            n=x;
        }
        else if (y>x){
            n=((y-y%x)+y)/2;
        }
        else{
            assert(0);
        }
        cout<<n<<"\n";
        assert(n%x==y%n);
    }
}