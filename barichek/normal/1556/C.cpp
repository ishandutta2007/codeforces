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

ll len_of_intersection(ll l1,ll r1,ll l2,ll r2)
{
    return max(0ll,min(r1,r2)-max(l1,l2)+1);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    cin>>n;
    vector<int> a(n,0);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0;
    for (int i=0;i<n;i+=2){
        ll l=1;
        ll r=a[i];
        for (int j=i+1;j<n;j++){
            if ((j-i)%2==1){
                ans+=len_of_intersection(l,r,1,a[j]);
                l-=a[j];
                r-=a[j];
                l=max(l,0ll);
            }
            else{
                l+=a[j];
                r+=a[j];
            }
        }
    }
    cout<<ans<<"\n";
}