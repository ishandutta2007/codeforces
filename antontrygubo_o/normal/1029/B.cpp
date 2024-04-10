#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    vector<int> take(n);
    int idx = n-1;
    for (int i = n-1; i>=0; i--)
    {
        while ((idx>=1) && (2*a[idx]>=a[i])) idx--;
        if (2*a[idx]<a[i]) idx++;
        take[i] = idx;
    }
    /*for (int i = 0; i<n; i++) cout<<a[i]<<' ';
    cout<<endl;
    for (int i = 0; i<n; i++) cout<<take[i]<<' ';
    cout<<endl;*/
    
    vector<int> ans(n);
    int maxx = 0;
    for (int i = 0; i<n; i++)
    {
        if (take[i] == i) ans[i] = 1;
        else ans[i] = ans[take[i]]+(i-take[i]);
        maxx = max(maxx, ans[i]);
    }
    cout<<maxx;
    
}