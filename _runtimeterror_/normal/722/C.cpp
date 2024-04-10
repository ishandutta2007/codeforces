#include<bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 1e5+4;
ll a[N];

int main()
{
    multiset<ll> s;
    set<ll> set;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",a+i);
        a[i] += a[i-1];
    }
    set.insert(0);
    set.insert(n+1);
    s.insert(a[n]); 
    for(int i=1;i<=n;++i)
    {
        int x;
        scanf("%d",&x);
        auto j = set.lower_bound(x);
        auto k = j;
        --k;
        s.erase(s.find(a[(*j)-1]-a[*k]));
        if(x>*k+1)
            s.insert(a[x-1]-a[*k]);
        if(*j>x+1)
            s.insert(a[(*j)-1]-a[x]);
        set.insert(x);
        cout << (s.empty()?0:*s.rbegin()) << "\n";
    }
}