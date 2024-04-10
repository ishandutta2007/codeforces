#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n, m;
    cin>>n>>m;
    int a[n];
    int b[m];
    for (int i = 0; i<n; i++) cin>>a[i];
    for (int j = 0; j<m; j++) cin>>b[j];
    int idx = 0;
    for (int i = 0; i<n; i++)
    {
        if (idx<m)
        {
            if (b[idx]>=a[i]) idx++;
        }
    }
    cout<<idx;
}