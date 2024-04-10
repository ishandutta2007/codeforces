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

    int test;
    cin>>test;
    while (test--){
        int n;
        cin>>n;
        vector<int> b(n);
        ll sum_b=0;
        for (int i=0;i<n;i++){
            cin>>b[i];
            sum_b+=b[i];
        }
        if (sum_b%(n*(n+1)/2)!=0){
            cout<<"NO"<<"\n";
            continue;
        }
        ll sum_a=sum_b/(n*(n+1)/2);
        vector<int> ans(n);
        bool flag=0;
        for (int i=0;i<n;i++){
            ll diff = b[i]-b[i==0 ? n-1 : i-1];
            ll na=sum_a-diff;
            if (na%n!=0 || na/n<=0 || na/n>1000*1000*1000){
                cout<<"NO"<<"\n";
                flag=1;
                break;
            }
            ans[i]=na/n;
        }
        if (!flag){
            cout<<"YES"<<"\n";
            for (auto i:ans){
                cout<<i<<" ";
            }
            cout<<"\n";
        }
    }
}