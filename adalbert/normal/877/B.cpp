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
    string st;
    cin>>st;

    for (int i=0;i<st.size();i++)
        pref[i+1]=pref[i]+(st[i]=='b');


    int ans=1e9;
    for (int l=0;l<=st.size();l++)
        for (int r=l+1;r<=st.size()+1;r++)
        {
            ans=min(ans,pref[l]+(r-l-1-(pref[r-1]-pref[l]))+pref[st.size()]-pref[r-1]);
        }
    cout<<st.size()-ans;
}