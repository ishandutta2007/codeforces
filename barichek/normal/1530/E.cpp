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

const int max_n = 2e5+10, inf = 1000111222;

int cnt[1000];

void solve()
{
    string s;
    cin>>s;
    memset(cnt,0,sizeof(cnt));
    for (auto i:s){
        cnt[i]++;
    }
    for (int i='a';i<='z';i++){
        if (cnt[i]==1){
            string ans=s;
            for (int j=0;j<len(ans);j++){
                if (ans[j]==i){
                    swap(ans[0],ans[j]);
                }
            }
            sort(ans.begin()+1,ans.end());
            cout<<ans<<"\n";
            return;
        }
    }
    if (*min_element(all(s))==*max_element(all(s))){
        cout<<s<<"\n";
        return;
    }
    vector<pair<int,char>> v;
    for (int i='a';i<='z';i++){
        if (cnt[i]){
            v.pb(mp(cnt[i],i));
        }
    }

    // bbdbdbebfbfb...
    if (2*(v[0].fir-2)<=(len(s)-2)){
        string ans="";
        ans+=v[0].sec;
        ans+=v[0].sec;
        v[0].fir-=2;
        for (int j=1;j<len(v);j++){
            for (int k=0;k<v[j].fir;k++){
                ans+=v[j].sec;
                if (v[0].fir){
                    ans+=v[0].sec;
                    v[0].fir-=1;
                }
            }
        }
        cout<<ans<<"\n";
        return;
    }

    // bdbbbbbbbbeddddeeeefffff
    if (len(v)>=3){
        string ans="";
        ans+=v[0].sec;
        ans+=v[1].sec;
        v[0].fir-=1;
        v[1].fir-=1;
        while (v[0].fir){
            v[0].fir--;
            ans+=v[0].sec;
        }
        ans+=v[2].sec;
        v[2].fir-=1;
        for (int j=1;j<len(v);j++){
            for (int k=0;k<v[j].fir;k++){
                ans+=v[j].sec;
            }
        }
        cout<<ans<<"\n";
        return;
    }

    // bdddddddbbbbb
    if (1){
        string ans="";
        ans+=v[0].sec;
        ans+=v[1].sec;
        v[0].fir-=1;
        v[1].fir-=1;
        while (v[1].fir){
            v[1].fir--;
            ans+=v[1].sec;
        }
        while (v[0].fir){
            v[0].fir--;
            ans+=v[0].sec;
        }
        cout<<ans<<"\n";
        return;
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    scanf("%d",&test);
    while (test--){
        solve();
    }
}