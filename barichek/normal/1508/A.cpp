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
        string s[3];
        cin>>s[0]>>s[1]>>s[2];
        int p[3];
        p[0]=p[1]=p[2]=0;
        string ans="";
        for (int i=0;i<3*n;i++){
            int cnt[2];
            cnt[0]=cnt[1]=0;
            for (int j=0;j<3;j++){
                if (p[j]!=2*n){
                    cnt[s[j][p[j]]-'0']++;
                }
            }
            int cur=0;
            if (cnt[0]+cnt[1]<3){
                int max_dist=-inf;
                for (int j=0;j<3;j++){
                    if (p[j]!=2*n){
                        if (p[j]>max_dist){
                            max_dist=p[j];
                            cur=s[j][p[j]]-'0';
                        }
                    }
                }
            }
            else if (cnt[1]>cnt[0]){
                cur=1;
            }
            for (int j=0;j<3;j++){
                if (p[j]!=2*n && s[j][p[j]]-'0'==cur){
                    p[j]++;
                }
            }
            ans+=char('0'+cur);
        }
//        cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<"\n";
        cout<<ans<<"\n";
    }
}