#include<bits/stdc++.h>
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
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int arr=2e5;

signed main()
{
    int hh,m;
    cin>>hh>>m;
    m+=hh*60;
    int need=max(ll(0),ll(20*60)-m);
    int h,d,c,n;
    cin>>h>>d>>c>>n;
    ld ans=min(ld(h/n+(h%n!=0))*c,ld(0.8)*c*((h+need*d)/n+((h+need*d)%n!=0)));
    cout<<fixed<<setprecision(9)<<ans;
}