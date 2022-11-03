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

#define int ll

int a[300000],cnt[300000],use[300000];

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }

    queue<int> q;

    for (int i=1;i<=n;i++)
        if (cnt[i]==0) q.push(i);

    int ans=q.size();

    for (int i=1;i<=n;i++)
    {
        if (cnt[a[i]]!=1)
        {
            if (use[a[i]])
            {cnt[a[i]]--;
                a[i]=q.front();
                q.pop();

            } else
            {
                if (a[i]>q.front())
                {cnt[a[i]]--;
                    a[i]=q.front();
                    q.pop();

                } else
                {
                    use[a[i]]=1;
                }
            }
        }
    }
    cout<<ans<<'\n';
    for (int i=1;i<=n;i++)
        cout<<a[i]<<' ';
}