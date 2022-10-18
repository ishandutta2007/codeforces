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

vector<int> go[10000];

void solve()
{
    for (int i='a';i<='z';i++){
        go[i].clear();
    }
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    bool ok=1;
    for (int i=0;i<n;i++){
        if (s[i]>t[i]){
            ok=0;
        }
        else if (s[i]<t[i]){
            go[s[i]].pb(t[i]);
        }
    }
    if (!ok){
        cout<<-1<<"\n";
        return;
    }
    int ans=0;
    for (int i='a';i<='z';i++){
        if (!go[i].empty()){
            sort(all(go[i]));
            reverse(all(go[i]));
            while (!go[i].empty() && go[i].back()==i){
                go[i].pop_back();
            }
            if (go[i].empty()){
                continue;
            }
            int to=go[i].back();
            while (!go[i].empty() && go[i].back()==to){
                go[i].pop_back();
            }
            reverse(all(go[i]));
            ans++;
            for (auto j:go[i]){
                go[to].pb(j);
            }
        }
    }
    cout<<ans<<"\n";
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}