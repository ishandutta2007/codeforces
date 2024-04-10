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

const int max_n = 500+10, inf = 1000111222;

int a[max_n];
int ans[max_n][max_n];

int new_a[max_n];

int a_start[max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        a_start[i]=a[i];
    }
    for (int i=1;i<=n;i++){
        ans[i][i]=i;
    }
    for (int diff=0;diff<n;diff++){
        for (int j=1;j+diff<=n;j++){
            int i=j+diff;
            a[i]--;
        }
        int pos=-1;
        for (int j=1;j+diff<=n;j++){
            int i=j+diff;
            if (a[i]==0){
                pos=i;
            }
        }
        for (int j=1;j+diff<=n;j++){
            int i=j+diff;
            if (i<pos){
                new_a[i+1]=a[i];
                ans[i+1][j]=ans[i][j];
            }
            else if (i>pos){
                new_a[i]=a[i];
                ans[i][j-1]=ans[i][j];
            }
        }

        for (int i=0;i<max_n;i++){
            a[i]=new_a[i];
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            cout<<a_start[ans[i][j]]<<" ";
        }
        cout<<"\n";
    }
}