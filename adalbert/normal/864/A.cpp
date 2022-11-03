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

int cnt[1000];

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        cnt[a]++;
    }

    int midle=n/2+n%2;

    vector<int> vec;

    for (int i=1;i<=100;i++)
        if (cnt[i]==midle) vec.pb(i);

if (vec.size()==2)
{
    cout<<"YES"<<'\n';
    cout<<vec[0]<<' '<<vec[1]<<'\n';
} else
cout<<"NO";
}