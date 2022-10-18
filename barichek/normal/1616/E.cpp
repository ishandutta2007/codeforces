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

int N;
int F[max_n];

void F_upd(int pos,int val)
{
    for (int i=pos;i<N;i|=i+1){
        F[i]+=val;
    }
}

int F_get(int pos)
{
    int res=0;
    for (int i=pos;i>=0;i&=i+1,i--){
        res+=F[i];
    }
    return res;
}

const int alphabet='z'-'a'+1;
vector<int> poses[alphabet];

void solve()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    N=n+5;
    for (int i=0;i<N;i++){
        F[i]=0;
    }
    for (int i=0;i<alphabet;i++){
        poses[i].clear();
    }
    for (int i=0;i<n;i++){
        poses[s[i]-'a'].pb(i);
    }
    for (int i=0;i<alphabet;i++){
        reverse(all(poses[i]));
    }

    int all_upds=0;
    auto my_F_get=[&](int pos)
    {
        return all_upds-F_get(pos);
    };

    ll ans=1ll*inf*inf;
    ll cur_base=0;
    for (int i=0;i<n;i++){
        for (char j='a';j<t[i];j++){
            if (!poses[j-'a'].empty()){
                ans=min(ans,cur_base + (poses[j-'a'].back() + my_F_get(poses[j-'a'].back())) - i);
            }
        }
        if (poses[t[i]-'a'].empty()){
            break;
        }
        cur_base += (poses[t[i]-'a'].back() + my_F_get(poses[t[i]-'a'].back())) - i;
        F_upd(poses[t[i]-'a'].back(),+1);
        all_upds+=1;
        poses[t[i]-'a'].pop_back();
    }

    if (ans==1ll*inf*inf){
        ans=-1;
    }
    cout<<ans<<"\n";
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}