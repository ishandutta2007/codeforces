#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=200000;
    int n,q;
    cin >> n >> q;
    vector<int> x(N+1,0);
    vector<int> c(N+1,0);
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        x[a[i]]=i;
        c[a[i]]++;
    }
    int res=0;
    int l=1;
    while(l<=n)
    {
        int r=l;
        int lim=l;
        while(r<=lim)
        {
            lim=max(lim,x[a[r]]);
            r++;
        }
        int m=0;
        for(int i=l;i<r;i++) m=max(m,c[a[i]]);
        res+=(r-l-m);
        l=r;
    }
    cout << res << "\n";
    return 0;
}