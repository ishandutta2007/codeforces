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

const int max_n = 1e5+10, inf = 1000111222;

int n,m;
int a[max_n];
int b[max_n];

bool check1(int l,int r)
{
    int p=0;
    for (int i=0;p<m && i<n;i++){
        if (b[p]<a[i]+l){
            return 0;
        }
        p=upper_bound(b+p,b+m,a[i]+r)-b;
    }
    return p==m;
}

bool check(int x)
{
//    cout<<"check :: "<<x<<" !!\n";
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            {
                int l=b[j]-a[i];
                int r=l+x;

                if (check1(l,r)){
                    return 1;
                }
            }
            {
                int r=b[j]-a[i];
                int l=r-x;

                if (check1(l,r)){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    n=6;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    m;
    cin>>m;
    for (int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(b,b+m);
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