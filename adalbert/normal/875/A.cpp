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

int sum(int u)
{
    int res=0;
    while (u!=0)
    {
        res+=u%10;
        u/=10;
    }
    return(res);
}

signed main()
{
    int n;
    cin>>n;
    vector<int> vec;

    for (int i=0;i<=500;i++)
    {
        if (n-i>=1)
            if ((sum(n-i))==i)
            {
                vec.pb(n-i);
            }
    }
    sort(vec.begin(),vec.end());
    cout<<vec.size()<<'\n';
    for (int i=0;i<vec.size();i++)
        cout<<vec[i]<<'\n';
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