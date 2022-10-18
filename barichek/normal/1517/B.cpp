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

const int max_n = 100+10, inf = 1000111222;

int a[max_n][max_n];
int answer[max_n][max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        int n,m;
        cin>>n>>m;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        ll ans=0;
        for (int iter=0;iter<m;iter++){
            int pos=-1;
            int pos_value=inf;
            for (int i=1;i<=n;i++){
                for (int j=1;j<=m;j++){
                    if (a[i][j]!=-1){
                        if (a[i][j]<pos_value){
                            pos_value=a[i][j];
                            pos=i;
                        }
                    }
                }
            }
            for (int i=1;i<=n;i++){
                if (pos!=i){
                    int pos1=-1;
                    int pos1_value=-inf;
                    for (int j=1;j<=m;j++){
                        if (a[i][j]!=-1){
                            if (a[i][j]>pos1_value){
                                pos1_value=a[i][j];
                                pos1=j;
                            }
                        }
                    }
                    answer[i][iter+1]=a[i][pos1];
                    a[i][pos1]=-1;
                }
                else{
                    int pos1=-1;
                    int pos1_value=inf;
                    for (int j=1;j<=m;j++){
                        if (a[i][j]!=-1){
                            if (a[i][j]<pos1_value){
                                pos1_value=a[i][j];
                                pos1=j;
                            }
                        }
                    }
//                    cout<<i<<" "<<pos1<<" :: "<<a[i][pos1]<<"\n";
                    answer[i][iter+1]=a[i][pos1];
                    ans+=a[i][pos1];
                    a[i][pos1]=-1;
                }
            }
        }
//        cout<<ans<<"\n";
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cout<<answer[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}