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
#define files(name) freopen("input.txt","r",stdin); freopen ("output.txt","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define vi vector<int>
#define int ll
#define endl "\n"

map<int,int> mp;

signed main()
{
    int n;
    string st;
    cin>>n>>st;
    int now=0;
    mp[0]=-1;

    int ans=0;
    for (int i=0;i<st.size();i++)
    {
        //cout<<now<<'\n';
        if (st[i]=='0')
            now++; else
            now--;
        if (mp.count(now))
            ans=max(ans,i-mp[now]);
        else
            mp[now]=i;
    }
    cout<<ans;
}
/*
15 3
1 2
2 3
1 7
*/