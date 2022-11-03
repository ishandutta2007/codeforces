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

int cnt[2000];

signed main()
{
    string s;
    cin>>s;
    for (auto i:s)
        cnt[i]++;
    vector<int> vec;
    for (int i=0;i<=1000;i++)
        if (cnt[i]!=0)
        vec.pb(cnt[i]);

    if (vec.size()==1 || vec.size()>4)
    {
        cout<<"No";
        return(0);
    }

    if (vec.size()==2)
    {
        if (min(vec[0],vec[1])==1)
            cout<<"No\n"; else
            cout<<"Yes\n";
        return(0);
    }
    if (vec.size()==3)
    {
        if (max({vec[0],vec[1],vec[2]})==1)
            cout<<"No\n"; else
            cout<<"Yes\n";
        return(0);
    }

    cout<<"Yes\n";

}