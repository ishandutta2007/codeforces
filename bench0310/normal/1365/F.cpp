#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
set<vector<int>> s;

void solve(vector<int> v)
{
    if(s.find(v)!=s.end()) return;
    s.insert(v);
    for(int i=1;i<=n/2;i++)
    {
        vector<int> t=v;
        for(int j=0;j<i;j++) swap(t[j],t[n-i+j]);
        solve(t);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        vector<int> b(n);
        for(int i=0;i<n;i++) cin >> b[i];
        multiset<array<int,2>> one,two;
        for(int i=0;i<n/2;i++) one.insert({min(a[i],a[n-i-1]),max(a[i],a[n-i-1])});
        for(int i=0;i<n/2;i++) two.insert({min(b[i],b[n-i-1]),max(b[i],b[n-i-1])});
        if(one!=two||((n&1)&&a[n/2]!=b[n/2])) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}