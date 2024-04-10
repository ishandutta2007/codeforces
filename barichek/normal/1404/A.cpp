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

const int max_n = 3e5+10, inf = 1000111222;

int val[max_n];
int cnt[2];

void solve()
{
    int n,k;
    string s;
    cin>>n>>k>>s;
    for (int i=0;i<k;i++){
        val[i]=-1;
    }
    for (int i=0;i<n;i++){
        if (s[i]!='?'){
            if (val[i%k]!=-1 && val[i%k]!=s[i]-'0'){
                cout<<"NO"<<"\n";
                return;
            }
            val[i%k]=s[i]-'0';
        }
    }

    cnt[0]=cnt[1]=0;
    for (int i=0;i<k;i++){
        if (val[i]!=-1){
            cnt[val[i]]++;
        }
    }
    for (int i=0;i<2;i++){
        if (cnt[i]>k/2){
            cout<<"NO"<<"\n";
            return;
        }
    }
    cout<<"YES"<<"\n";
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}