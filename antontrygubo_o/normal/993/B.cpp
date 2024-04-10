#include <bits/stdc++.h>

#define ll long long

using namespace std;

int check (pair<int, int> a, pair<int, int> b)
{
    if (a.first==b.first&&a.second!=b.second) return a.first;
    if (a.first==b.second&&a.second!=b.first) return a.first;
    if (a.second==b.first&&a.first!=b.second) return a.second;
    if (a.second==b.second&&a.first!=b.first) return a.second;
    return 0;
}

int main()
{
    int n, m;
    cin>>n>>m;
    pair<int, int> a[n];
    pair<int, int> b[m];
    for (int i = 0; i<n; i++) cin>>a[i].first>>a[i].second;
    for (int i = 0; i<m; i++) cin>>b[i].first>>b[i].second;
    
    set<int> maybe;
    for (int i = 0; i<n; i++)
    for (int j = 0; j<m; j++)
    {
        if (check(a[i], b[j])) maybe.insert(check(a[i], b[j]));
    }
    
    if (maybe.size()==1) 
    {
        auto it = maybe.begin(); cout<<*it; return 0;
    }
    maybe.clear();
    bool checker = true;
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j <m; j++)
        if (check(a[i], b[j])) maybe.insert(check(a[i], b[j]));
        if (maybe.size()>=2) checker = false;
        maybe.clear();
    }
    for (int j = 0; j<m; j++)
    {
        for (int i = 0; i <n; i++)
        if (check(a[i], b[j])) maybe.insert(check(a[i], b[j]));
        if (maybe.size()>=2) checker = false;
        maybe.clear();
    }
    if (checker) cout<<0;
    else cout<<-1;

}