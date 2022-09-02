#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    ll maxx = 0;
    ll minn = 1000000000;
    for (int i = 0; i<n; i++)
    {
        ll temp;
        cin>>temp;
        maxx = max(maxx, temp);
        minn = min(minn, temp);
    }
    cout<<(maxx-minn+1-n);
}