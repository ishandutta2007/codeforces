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

int a[max_n];

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
        string s1,s2;
        cin>>n>>s1>>s2;
        for (int i=0;i<n;i++){
            if (s1[i]==s2[i]){
                a[i]=s1[i]-'0';
            }
            else{
                a[i]=-1;
            }
        }
        int ans=0;
        for (int i=0;i<n;){
            if (a[i]==-1){
                ans+=2;
                i++;
            }
            else if (a[i]==0){
                if (i+1<n && a[i+1]==1){
                    ans+=2;
                    i+=2;
                }
                else{
                    ans+=1;
                    i+=1;
                }
            }
            else if (a[i]==1){
                if (i+1<n && a[i+1]==0){
                    ans+=2;
                    i+=2;
                }
                else{
                    i+=1;
                }
            }
            else{
                assert(0);
            }
        }

        cout<<ans<<"\n";
    }
}