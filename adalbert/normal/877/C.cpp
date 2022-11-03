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
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define vi vector<int>
#define endl "\n"
#define int ll
#define next odtjgodirhg

int pref[10000];

signed main()
{
    vector<int> vec;
    int n;
    cin>>n;

    int now=2;
    while (now<=n)
    {
        vec.pb(now);
        now+=2;
    }

     now=1;

    while (now<=n)
    {
        vec.pb(now);
        now+=2;
    }

     now=2;
    while (now<=n)
    {
        vec.pb(now);
        now+=2;
    }

    cout<<vec.size()<<'\n';
    for (auto i:vec)
        cout<<i<<' ';
}