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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=2e5+100;
int n,m;

signed main()
{
    map<int,int> mp;

    int n,k;
    cin>>n>>k;

    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        mp[a]=i;
    }

    vector<int> vec;

    for (auto i:mp)
    {
        vec.pb(i.sec);
    }

    if (vec.size()<k)
    {
        cout<<"NO";
    } else
    {
        cout<<"YES\n";
        for (int i=0;i<k;i++)
            cout<<vec[i]<<' ';
    }
}