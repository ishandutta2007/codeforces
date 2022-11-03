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

map<int,pair<int,int> > mp;

signed main()
{
    int n;
    cin>>n;

    for (int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        vector<int> vec;
        int sum=0;
        while (k--)
        {
            int a;
            cin>>a;
            vec.pb(a);
            sum+=a;
        }

        for (int j=1;j<=vec.size();j++)
        {
            if (mp.count(sum-vec[j-1]))
            {
                cout<<"YES\n";
                cout<<i<<' '<<j<<'\n';
                cout<<mp[sum-vec[j-1]].fir<<' '<<mp[sum-vec[j-1]].sec<<'\n';
                return(0);
            }
        }
        for (int j=1;j<=vec.size();j++)
        {
            mp[sum-vec[j-1]]={i,j};
        }
    }

    cout<<"NO";
}