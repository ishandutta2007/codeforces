
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
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".sol","r",stdin); freopen (name".dat","w",stdout);
#define time pdojegoritg

#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define int ll

typedef long long ll;
typedef long double ld;
const int arr=2*1e6;
const int md=1e9+7;

int a[arr],last[arr];

signed main()
{
    int n;
    cin>>n;
    int cnt=0;
    int all=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt+=2*(i-last[a[i]])*(n-i+1);
        cnt--;
        last[a[i]]=i;
    }
    cout<<fixed<<setprecision(9)<<ld(cnt)/ld(n*n);
}