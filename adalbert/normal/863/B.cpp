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
#define time pdojegoritg
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);

#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")

typedef long long ll;

#define int ll

int w[2000],use[2000];

signed main()
{
    int n;
    cin>>n;
    n*=2;
    for (int i=1;i<=n;i++)
    {
        cin>>w[i];
    }

    sort(w+1,w+1+n);
    int ans=1e9;
    for (int f=1;f<=n;f++)
        for (int s=f+1;s<=n;s++)
        {
            vector<int> vec;
            use[f]=1;
            use[s]=1;
            for (int i=1;i<=n;i++)
                if (!use[i])
                    vec.pb(w[i]);
            int now=0;
            for (int i=0;i<vec.size();i+=2)
                now+=vec[i+1]-vec[i];
            ans=min(ans,now);
            use[f]=0;
            use[s]=0;
        }
    cout<<ans;
}