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

signed main()
{
    int n;
    cin>>n;
    while (n--)
    {
        string now;
        cin>>now;
        string st;
        st+='!';
        for (auto i:now)
            if (i=='u')
            st+="oo"; else
            if (i=='h')
            {
                while (st.back()=='k')
                    st.pop_back();

                st+=i;
            } else
            st+=i;
        setik.insert(st);
    }

    cout<<setik.size()<<'\n';

}