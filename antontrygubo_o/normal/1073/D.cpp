#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 1e9 + 7;

vector<vector<int>> G;

int main()
{
    ios_base::sync_with_stdio(0);
    ll n, T;
    cin>>n>>T;
    ll a[n];
    ll minn = 1000000000000;
    for (int i = 0; i<n; i++) {cin>>a[i]; minn = min(minn, a[i]);}
    
    ll candies = 0;
    ll pos = 0;
    ll cursum = 0;
    ll curcandies = 0;
    bool top = true;
    
    while (T>=minn)
    {
        cursum = 0; curcandies = 0;
        for (int i = 0; i<n; i++) 
        {
            if (T>=a[i]) {T-=a[i]; cursum+=a[i]; candies++; curcandies++;} 
        }
        ll times = T/cursum;
        T-=cursum*times;
        candies+=times*curcandies;
    }
    
    cout<<candies;
    
}