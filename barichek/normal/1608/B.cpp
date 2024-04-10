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
        int n,a,b;
        cin>>n>>a>>b;
        if (abs(a-b)>1 || a+b>n-2){
            cout<<-1<<"\n";
            continue;
        }

        if (a==b){
            cout<<n<<" ";
            int l=1,r=n-1;
            for (int i=0;i<a;i++){
                cout<<l<<" "<<r<<" ";
                l++;
                r--;
            }
            for (int i=r;i>=l;i--){
                cout<<i<<" ";
            }
            cout<<"\n";
        }
        else{
            bool flag=0;
            if (a==b+1){
                swap(a,b);
                flag=1;
            }

            vector<int> ans;
            ans.pb(n);
            int l=1,r=n-1;
            for (int i=0;i<a;i++){
                ans.pb(l);
                ans.pb(r);
                l++;
                r--;
            }
            ans.pb(l);
            l++;
            for (int i=l;i<=r;i++){
                ans.pb(i);
            }


            if (flag){
                for (auto& i:ans){
                    i=n-i+1;
                }
            }
            for (auto i:ans){
                cout<<i<<" ";
            }
            cout<<"\n";
        }
    }
}