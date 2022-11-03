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
const int md=1e9+7;

signed main()
{
    int n;
    cin>>n;
    string st;
    cin>>st;
    int res=n;
    for (int i=1;i+i<=n;i++)
    {
        bool ch=1;
        for (int j=i+1;j<=i+i;j++)
            if (st[j-i-1]!=st[j-1])
            ch=0;
        if (ch)
            res=min(res,n-i+1);
    }


    cout<<res;
}
/*

*/