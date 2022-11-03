#include <bits/stdc++.h>

using namespace std;

#define fir first
#define sec second
#define pb push_back
#define int ll

typedef long long ll;

int a[200000];

signed main()
{
    int n;
    cin>>n;

    multiset<int> setik;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        setik.insert(a[i]);
    }

    int ans=0;
    for (int i=1;i<=n;i++)
    {
        setik.erase(setik.find(a[i]));
        bool ch=0;

        for (int j=0;j<=40;j++)
            if (setik.count((1ll<<j)-a[i]))
            ch=1;
        ans+=!ch;

        setik.insert(a[i]);
    }

    cout<<ans;
}