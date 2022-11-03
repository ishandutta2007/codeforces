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
const int arr=2e5+100;

int x[arr];

signed main()
{
    map<int,int> mp;

    int n;
    cin>>n;

    for (int i=1;i<=n;i++)
    {
        cin>>x[i];
        mp[x[i]]=i;
    }

    vector<int> ans;

    ans.pb(x[1]);

    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=35;j++)
        {
            int pl=(1ll<<j);
            if (mp.count(x[i]+pl) && mp.count(x[i]+pl*2))
                ans={x[i],x[i]+pl,x[i]+pl*2};
            if (ans.size()==1)
                if (mp.count(x[i]+pl))
            ans={x[i],x[i]+pl};
        }
    }

    cout<<ans.size()<<'\n';
    for (auto i:ans)
        cout<<i<<' ';
}