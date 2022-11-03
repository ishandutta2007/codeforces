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

signed main()
{
    string st;
    cin>>st;

    int cnt=0;

    string s="Danil";

    for (int i=0;i+s.size()-1<st.size();i++)
    {
        bool ch=1;
        for (int j=0;j<s.size();j++)
            if (st[i+j]!=s[j])
            ch=0;
        cnt+=ch;
    }
     s="Olya";

    for (int i=0;i+s.size()-1<st.size();i++)
    {
        bool ch=1;
        for (int j=0;j<s.size();j++)
            if (st[i+j]!=s[j])
            ch=0;
        cnt+=ch;
    }
     s="Slava";

    for (int i=0;i+s.size()-1<st.size();i++)
    {
        bool ch=1;
        for (int j=0;j<s.size();j++)
            if (st[i+j]!=s[j])
            ch=0;
        cnt+=ch;
    }
     s="Ann";

    for (int i=0;i+s.size()-1<st.size();i++)
    {
        bool ch=1;
        for (int j=0;j<s.size();j++)
            if (st[i+j]!=s[j])
            ch=0;
        cnt+=ch;
    }
     s="Nikita";

    for (int i=0;i+s.size()-1<st.size();i++)
    {
        bool ch=1;
        for (int j=0;j<s.size();j++)
            if (st[i+j]!=s[j])
            ch=0;
        cnt+=ch;
    }
    if (cnt==1)
    {
        cout<<"YES";
    } else
    cout<<"NO";

}