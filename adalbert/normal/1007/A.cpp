#include <bits/stdc++.h>
#define pb push_back
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;

int use[200000],a[200000],ans[200000];

signed main()
{
    int n;
    cin>>n;
    multiset<int> set1,set2;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=-a[i];
        set1.insert(a[i]);
        set2.insert(a[i]);
    }

    int an=0;

    while (!set1.empty())
    {
        int now=*set1.begin();

        auto it=set2.upper_bound(now);

        if (it==set2.end())
            break;
        an++;
        set1.erase(set1.find(now));
        set2.erase(set2.find(*it));
    }

    cout<<an;
}
/*
*/