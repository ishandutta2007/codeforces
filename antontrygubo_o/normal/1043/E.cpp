#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;

struct man
{
    ll x;
    ll y;
    int idx;
};

bool sortman(man a, man b)
{
    if (a.x-a.y==b.x-b.y) return 1;
    return a.x-a.y<b.x-b.y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    vector<man> a(n);
    for (int i = 0; i<n; i++) {cin>>a[i].x>>a[i].y; a[i].idx = i;}
    sort(a.begin(), a.end(), sortman);
    vector<ll> res(n, 0);
    
    vector<ll> sumsx(n+1);
    sumsx[0] = 0;
    for (int i = 1; i<=n; i++) sumsx[i] = sumsx[i-1] + a[i-1].x;
        
    vector<ll> sumsy(n+1);
    sumsy[0] = 0;
    for (int i = 1; i<=n; i++) sumsy[i] = sumsy[i-1] + a[i-1].y;
    
    for (int i = 0; i<n; i++) 
    {
        res[a[i].idx] += (i*a[i].y + sumsx[i]);
        res[a[i].idx] += ((n-1-i)*a[i].x+sumsy[n]-sumsy[i+1]);
    }
    vector<int> p(n);
    for (int i = 0; i<n; i++) p[a[i].idx] = i;
    
    int t1, t2;
    for (int i = 0; i<m; i++)
    {
        cin>>t1>>t2;
        t1--;
        t2--;
        ll lol = min(a[p[t1]].x+a[p[t2]].y, a[p[t1]].y+a[p[t2]].x);
        res[t1]-=lol;
        res[t2]-=lol;
    }
    for (int i = 0; i<n; i++) cout<<res[i]<<' ';
    
}