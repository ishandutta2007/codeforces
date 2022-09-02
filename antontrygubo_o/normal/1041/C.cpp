#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, d;
    cin>>n>>m>>d;
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    vector<int> b(n);
    for (int i = 0; i<n; i++) b[i] = a[i];
    sort(a.begin(), a.end());
    int maxx = 0;
    int idx = 0;
    for (int i = 0; i<n; i++)
    {
        while (idx<n&&a[idx]<a[i]+d+1) idx++;
        maxx = max(maxx, idx-i);
    }
    cout<<maxx<<endl;
    map<int, int> kek;
    for (int i = 0; i<n; i++) kek[a[i]] = (i%maxx)+1;
    for (int i = 0; i<n; i++) cout<<kek[b[i]]<<' ';

}