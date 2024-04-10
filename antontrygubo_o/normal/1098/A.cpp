#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long



int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> prev(n);
    vector<int> h(n);
    h[0] = 1;
    for (int i = 1; i<n; i++) {cin>>prev[i]; prev[i]--; h[i] = h[prev[i]]+1;}
    
    vector<ll> s(n);
    
    for (int i = 0; i<n; i++)
    {
        cin>>s[i];
    }
    
    vector<ll> weight(n, 1000000000);
    weight[0] = s[0];
    for (int i = 1; i<n; i++)
    {
        if (h[i]%2==1) weight[prev[i]] = min(weight[prev[i]], s[i]-s[prev[prev[i]]]); 
    }
    
    for (int i = 1; i<n; i++)
    {
        if (weight[i]<0) {cout<<-1; return 0;}
        if (weight[i]==1000000000) weight[i] = 0;
        if (h[i]%2==1) weight[i] = s[i]-weight[prev[i]] - s[prev[prev[i]]];
    }
    
   /* for (int i = 0; i<n; i++) cout<<weight[i]<<' ';
    cout<<endl;
    */
    ll summ = 0;
    for (int i = 0; i<n; i++) summ+=weight[i];
    cout<<summ;
}