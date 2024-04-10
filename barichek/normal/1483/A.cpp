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

vector<int> kek[max_n];
int cur_cnt[max_n];
int ans[max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    scanf("%d",&test);
    while (test--){
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++){
            cur_cnt[i]=0;
        }
        for (int i=1;i<=m;i++){
            int cur_s;
            scanf("%d",&cur_s);

            kek[i].clear();
            kek[i].resize(cur_s);
            for (int j=0;j<len(kek[i]);j++){
                scanf("%d",&kek[i][j]);
            }
            cur_cnt[kek[i][0]]++;
            ans[i]=kek[i][0];
        }
        int bad=-1;
        for (int i=1;i<=n;i++){
            if (cur_cnt[i]>(m/2+m%2)){
                assert(bad==-1);
                bad=i;
            }
        }

//        cout<<"bad at start :: "<<bad<<"\n";

        if (bad!=-1){
            for (int i=1;cur_cnt[bad]>(m/2+m%2) && i<=m;i++){
                if (kek[i][0]==bad && len(kek[i])>1){
                    cur_cnt[kek[i][0]]--;
                    cur_cnt[kek[i][1]]++;
                    ans[i]=kek[i][1];
                }
            }
        }

        bad=-1;
        for (int i=1;i<=n;i++){
            if (cur_cnt[i]>(m/2+m%2)){
                assert(bad==-1);
                bad=i;
            }
        }

        if (bad!=-1){
            cout<<"NO"<<"\n";
        }
        else{
            cout<<"YES"<<"\n";
            for (int i=1;i<=m;i++){
                cout<<ans[i]<<" ";
            }
            cout<<"\n";
        }
    }
}