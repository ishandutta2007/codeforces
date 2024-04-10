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

set<string> setik;

int use[700];

signed main()
{
    int n;
    cin>>n;
    string st;
    cin>>st;

    for (int i=0;i<st.size();i++)
        use[st[i]]=1;

    vector<string> vec;
    int m;
    cin>>m;
    while (m--)
    {
        string s;
        cin>>s;
        bool good=1;
        for (int i=0;i<n;i++)
            if (st[i]=='*' && use[s[i]])
            good=0; else
            if (st[i]!='*' && st[i]!=s[i])
            good=0;
        if (good)
        vec.pb(s);
    }

    int ans=0;

    for (int i='a';i<='z';i++)
    {
        bool good=1;

        for (int j=0;j<n;j++)
        {
            if (st[j]==i)
                good=0;

        }
        for (auto s:vec)
        {
            bool ng=0;
            for (int j=0;j<n;j++)
            {

                if (s[j]==i)
                    ng=1;
            }
            good&=ng;
        }
        ans+=good;
    }

    cout<<ans;
}