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
#define int ll

signed main()
{
    multiset<int> can_be_used,used;
    int ans=0;
    can_be_used.insert(1e9);
    used.insert(1e9);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        int mc=*can_be_used.begin();
        int ug=*used.begin();
        if (a-mc<0 && a-ug<0)
            can_be_used.insert(a); else
            {
                if (a-mc>a-ug)
                {
                    can_be_used.erase(can_be_used.find(*can_be_used.begin()));
                    ans+=a-mc;
                    used.insert(a);
                } else
                {
                    used.erase(used.find(*used.begin()));
                    ans+=a-ug;
                    can_be_used.insert(ug);
                    used.insert(a);
                }
            }
    }
    cout<<ans;
}