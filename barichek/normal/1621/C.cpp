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

bool debug=0;

vector<int> hidden={5,7,6,2,3,0,1,4};
vector<int> cur;

int ask(int pos)
{
    cout<<"?"<<" "<<pos+1<<"\n";
    fflush(stdout);
    if (debug){
        int to_return=cur[pos];
        vector<int> new_cur=cur;
        for (int i=0;i<len(cur);i++){
            new_cur[i]=cur[hidden[i]];
        }
        cur=new_cur;
        return to_return;
    }
    else{
        int res;
        cin>>res;
        res--;
        return res;
    }
    assert(0);
}

void solve()
{
    int n;
    cin>>n;

    cur.clear();
    for (int i=0;i<n;i++){
        cur.pb(i);
    }

    vector<int> reversed_p(n,-1);
    int done=0;
    for (int i=0;i<n;i++){
        if (reversed_p[i]==-1){
            int done_before=done;

            done++;
            int cur=ask(i);

            vector<int> v;
            v.pb(cur);
            while (1){
                done++;
                int b=ask(i);

                if (b==cur){
                    break;
                }
                else{
                    v.pb(b);
                }
            }

            for (int j=0;j<len(v);j++){
                reversed_p[v[j]]=(v[(j-1+len(v))%len(v)]);
            }
        }
    }

    vector<int> p(n,-1);
    for (int i=0;i<len(reversed_p);i++){
        p[reversed_p[i]]=i;
    }

    cout<<"!";
    for (auto i:p){
        cout<<" "<<i+1;
    }
    cout<<"\n";
    fflush(stdout);
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