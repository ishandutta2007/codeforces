#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")

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

#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int max_n = 2e5+10, inf = 1000111222;
const int max_p=15;

int kek[1ll<<max_p];

string s[max_n];

int my_rand()
{
    int res=0;
    for (int i=0;i<30;i++){
        if (rand()&1){
            res|=(1ll<<i);
        }
    }
    return res;
}

void ___main___()
{
    srand(time(0));

    double start=clock();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,p;
    cin>>n>>m>>p;
    for (int i=0;i<n;i++){
        cin>>s[i];
    }

    string ans=string(m,'0');

    auto iter=[&]()
    {
        int k=my_rand()%n;
        vector<int> poses;
        for (int i=0;i<m;i++){
            if (s[k][i]=='1'){
                poses.pb(i);
            }
        }
        if (poses.empty()){
            return;
        }

        memset(kek,0,sizeof(kek));

        for (int i=0;i<n;i++){
            int cur=0;
            for (int j=0;j<len(poses);j++){
                if (s[i][poses[j]]=='1'){
                    cur|=(1ll<<j);
                }
            }
            kek[cur]++;
        }

        for (int i=0;i<len(poses);i++){
            for (int j=0;j<(1ll<<len(poses));j++){
                if (j&(1ll<<i)){
                    kek[j^(1ll<<i)]+=kek[j];
                }
            }
        }
        int cur_ans=0;
        for (int res=0;res<(1ll<<len(poses));res++){
            if (2*kek[res]>=n && __builtin_popcountll(res)>__builtin_popcountll(cur_ans)){
                cur_ans=res;
            }
        }
        string cur_ans_string=string(m,'0');
        for (int i=0;i<len(poses);i++){
            if (cur_ans&(1ll<<i)){
                cur_ans_string[poses[i]]='1';
            }
        }
        auto cnt=[&](string a)
        {
            int res=0;
            for (auto i:a){
                res+=(i=='1');
            }
            return res;
        };
        if (cnt(cur_ans_string)>cnt(ans)){
            ans=cur_ans_string;
        }
    };

    while ((clock()-start)/CLOCKS_PER_SEC<2.4){
        iter();
    }
    cout<<ans<<"\n";
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ___main___();

    exit(0);
}