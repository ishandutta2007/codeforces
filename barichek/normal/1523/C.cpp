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

const int max_n = 1e3+10, inf = 1000111222;

#define to_integer wegrefgew

int a[max_n];
int dp[max_n][max_n];
string ans[max_n];
string to_integer[max_n];

const bool gen=0;

void rec(int l,int r)
{
    if (l>r){
        return;
    }
    assert(dp[l][r]!=-1);

    int k=dp[l][r];
//    cout<<"rec :: "<<l<<" "<<r<<" :: "<<k<<"\n";
    if (k==l){
        for (int i=l;i<=r;i++){
            if (!ans[i].empty()){
                ans[i]+=".";
            }
            ans[i]+=to_integer[a[l]];
        }
        rec(l+1,r);
    }
    else{
        for (int i=l;i<k;i++){
            if (!ans[i].empty()){
                ans[i]+=".";
            }
            ans[i]+=to_integer[a[l]];
        }
        rec(l+1,k-1);
        rec(k,r);
    }
}

void solve()
{
    memset(dp,-1,sizeof(dp));
    int n;
    if (gen){
        n=1e3;
    }
    else{
        cin>>n;
    }
    for (int i=0;i<n;i++){
        if (gen){
            a[i]=i+1;
        }
        else{
            cin>>a[i];
        }
    }

    for (int i=0;i<n;i++){
        dp[i][i]=i;
    }
    for (int ll=2;ll<=n;ll++){
        for (int l=0;l+ll-1<n;l++){
            int r=l+ll-1;

            if (a[l+1]==1 && dp[l+1][r]!=-1){
                dp[l][r]=l;
            }
            for (int k=l+1;k<=r;k++){
                if (a[k]==a[l]+1 && (l+1>k-1 || (a[l+1]==1 && dp[l+1][k-1]!=-1)) && dp[k][r]!=-1){
                    dp[l][r]=k;
                    break;
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        ans[i].clear();
    }
    rec(0,n-1);
    for (int i=0;i<n;i++){
        cout<<ans[i]<<"\n";
    }
}

void ___main___()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i=1;i<max_n;i++){
        stringstream stt;
        stt<<i;
        stt>>to_integer[i];
    }

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ___main___();

    exit(0);
}