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
        vector<int> b(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        for (int i=0;i<n;i++){
            cin>>b[i];
        }

        string ans(n,'0');
        int m1=max_element(all(a))-a.begin();
        int m2=max_element(all(b))-b.begin();
        ans[m1]='1';
        ans[m2]='1';
        int smallest_a=a[m2];
        int smallest_b=b[m1];
        set<pii> sa;
        set<pii> sb;
        for (int i=0;i<n;i++){
            if (i!=m1 && i!=m2){
                sa.insert(mp(a[i],i));
                sb.insert(mp(b[i],i));
            }
        }
        while (1){
            if (sa.empty()){
                break;
            }

            if (sa.rbegin()->fir > smallest_a){
                int id=sa.rbegin()->sec;
                sa.erase(mp(a[id],id));
                sb.erase(mp(b[id],id));
                smallest_b=min(smallest_b,b[id]);
                ans[id]='1';
            }
            else if (sb.rbegin()->fir > smallest_b){
                int id=sb.rbegin()->sec;
                sa.erase(mp(a[id],id));
                sb.erase(mp(b[id],id));
                smallest_a=min(smallest_a,a[id]);
                ans[id]='1';
            }
            else{
                break;
            }
        }
        cout<<ans<<"\n";
    }
}