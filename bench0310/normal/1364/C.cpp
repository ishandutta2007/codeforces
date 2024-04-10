#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> s;
    for(int i=0;i<=n;i++) s.insert(i);
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(s.find(a[i])!=s.end()) s.erase(a[i]);
    }
    vector<int> b(n,-1);
    for(int i=0;i<n-1;i++) if(a[i]<a[i+1]) b[i+1]=a[i];
    for(int i=0;i<n;i++)
    {
        if(b[i]!=-1) continue;
        b[i]=*s.begin();
        s.erase(s.begin());
    }
    for(int i=0;i<n;i++) cout << b[i] << " \n"[i==n-1];
    return 0;
}