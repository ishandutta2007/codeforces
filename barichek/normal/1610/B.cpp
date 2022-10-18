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

bool check(vector<int> a,int x)
{
    vector<int> aa;
    for (auto i:a){
        if (i!=x){
            aa.pb(i);
        }
    }
    int l=0,r=len(aa)-1;
    while (l<=r){
        if (aa[l]!=aa[r]){
            return 0;
        }
        l++;
        r--;
    }
    return 1;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        int n;
        cin>>n;
        vector<int> a(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        int l=0,r=n-1;
        while (l<=r){
            if (a[l]!=a[r]){
                break;
            }
            l++;
            r--;
        }
        if (l>r){
            cout<<"YES"<<"\n";
            continue;
        }
        bool ans=0;
        ans|=check(a,a[l]);
        ans|=check(a,a[r]);
        cout<<(ans ? "YES" : "NO")<<"\n";
    }
}