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

int get_count(const vector<int>& a,int b)
{
    return upper_bound(all(a),b)-lower_bound(all(a),b);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;
    while (test--){
        int n;
        cin>>n;
        vector<int> a(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        int ans=0;
        for (int i=0;i+1<n;i++){
            int cur_ans=get_count(a,a[i]);
            if (a[i+1]!=a[i]){
                int x=a[i+1]-a[i];
                while (1ll*a[i]+1ll*x<1ll*inf){
                    auto it=lower_bound(all(a),a[i]+x);
                    if (it==a.end()){
                        break;
                    }
                    cur_ans++;
                    x=2*(*it-a[i]);
                }
            }
            ans=max(ans,cur_ans);
        }
        cout<<n-ans<<"\n";
    }
}