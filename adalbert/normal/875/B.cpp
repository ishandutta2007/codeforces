#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <complex>
#include <queue>
#include <cstdlib>
#include <ctime>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define time pdojegoritg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define vi vector<int>
#define endl "\n"
#define int ll

bool use[500000];
signed main()
{
    fast;
    int n;
    cin>>n;
    int last=n;
    set<int> setik;
    int ans=1;
    cout<<1<<' ';
    for (int i=1;i<=n;i++)
    {
        int p;
        cin>>p;
        use[p]=1;
        if (p<=last) ans++;
        while (use[last]==1)
        {
            last--;
            ans--;
        }
        cout<<ans<<' ';
    }
}
/*
1
2 1
2 10 100
2 100 10
2 1 10
2 1 5
1 1 2 2
*/