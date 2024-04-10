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

bool edge[1000][1000];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int q;
    scanf("%d",&q);
    while (q--){
        int a,b;
        scanf("%d%d",&a,&b);
        if (b<a){
            cout<<"NO"<<"\n";
        }
        else{
            bool my_criteria=0;
            for (int bit=1;bit<=35;bit++){
                ll full_mask=(1ll<<bit)-1;
                my_criteria|=(__builtin_popcountll(b&full_mask)>__builtin_popcountll(a&full_mask));
            }
            if (my_criteria){
                cout<<"NO"<<"\n";
            }
            else{
                cout<<"YES"<<"\n";
            }
        }
    }

    return 0;

    for (int i=1;i<(1ll<<7);i++){
        for (int j=1;j<=i;j++){
            if ((i&j)==j){
                edge[i][i+j]=1;
                cout<<bitset<4>(i)<<"->"<<bitset<4>(i+j)<<"\n";
                cout<<i<<"->"<<i+j<<"\n";
            }
        }
    }
        for (int i=0;i<1000;i++){
            for (int j=0;j<1000;j++){
                for (int k=0;k<1000;k++){
                    if (edge[j][i]&&edge[i][k]){
                        edge[j][k]=1;
                    }
                }
            }
        }
    for (int i=1;i<(1ll<<7);i++){
        for (int j=i+1;j<(1ll<<7);j++){
            cout<<i<<" "<<j<<" !!\n";
            bool my_criteria=0;
            for (int bit=1;bit<=10;bit++){
                int full_mask=(1ll<<bit)-1;
                my_criteria|=(__builtin_popcountll(j&full_mask)>__builtin_popcountll(i&full_mask));
            }
            assert(!edge[i][j] == my_criteria);
            if (!edge[i][j]){
                cout<<"bad :: "<<i<<" "<<j<<"\n";
                cout<<"bad :: "<<bitset<4>(i)<<" "<<bitset<4>(j)<<"\n";
            }
        }
    }
}