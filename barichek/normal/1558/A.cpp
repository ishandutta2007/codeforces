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
    scanf("%d",&test);
    while (test--){
        int a,b;
        scanf("%d%d",&a,&b);
        vector<bool> ans(a+b+1,0);


        for (int first=0;first<2;first++){
            int a1=0;
            int a2=0;
            if (first==0){
                a1=(a+b+1)/2;
                a2=(a+b)-a1;
            }
            else{
                a1=(a+b)/2;
                a2=(a+b)-a1;
            }

//            cout<<"a1 a2 :: "<<a1<<" "<<a2<<"\n";1

            for (int c1=0;c1<=a1;c1++){
                int c2=a-a1+c1;
//                cout<<c1<<" "<<c2<<"\n";
                if (c2>=0 && c2<=a2){
                    if (a2-c2+c1==b){
                        ans[c1+c2]=1;
                    }
                }
            }
        }


        vector<int> ans1;
        for (int i=0;i<len(ans);i++){
            if (ans[i]){
                ans1.pb(i);
            }
        }
        cout<<len(ans1)<<"\n";
        for (auto i:ans1){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}