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

signed main()
{
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    if (x1==x2)
    {
        cout<<2*(abs(x1-x2)+abs(y1-y2)+2)+2;
    } else
    if (y1==y2)
    {
        cout<<2*(abs(x1-x2)+abs(y1-y2)+2)+2;
    } else

    cout<<2*(abs(x1-x2)+abs(y1-y2)+2);
}