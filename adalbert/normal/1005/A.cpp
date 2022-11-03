#include <bits/stdc++.h>

using namespace std;

#define fir first
#define sec second
#define pb push_back
#define int ll

typedef long long ll;

int a[100000];

signed main()
{
    int n;
    cin>>n;

    vector<int> vec;

    for (int i=1;i<=n;i++)
        cin>>a[i];
    a[n+1]=1;

    for (int i=2;i<=n+1;i++)
        if (a[i]==1)
        vec.pb(a[i-1]);

    cout<<vec.size()<<'\n';

    for (auto i:vec)
        cout<<i<<' ';
}