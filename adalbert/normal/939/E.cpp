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
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[310000];

signed main()
{
    fast;
    multiset<int> good,bad;

    int n;
    cin>>n;
    int sum=0;
    while (n--)
    {
        int type;
        cin>>type;
        if (type==1)
        {
            int a;
            cin>>a;
            if (good.empty() || a>*good.rbegin())
            {
                if (!good.empty())
                {
                    int c=*good.rbegin();
                    sum-=c;
                    good.erase(good.find(c));
                    bad.insert(c);
                }
                good.insert(a);
                sum+=a;
            } else
            bad.insert(a);

            while(!bad.empty())
            {
                ld now=ld(sum)/ld(good.size());
                ld maybe=ld(sum+(*bad.begin()))/ld(good.size()+1);
                if (maybe<now)
                {
                    int c=*bad.begin();
                    bad.erase(bad.find(c));
                    good.insert(c);
                    sum+=c;
                } else
                break;
            }
        } else
        {
            ld now=ld(sum)/ld(good.size());
            cout<<fixed<<setprecision(10)<<(*good.rbegin())-now<<'\n';
        }
    }
}