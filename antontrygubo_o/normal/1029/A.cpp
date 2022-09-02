#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin>>n>>k;
    string t;
    cin>>t;
    int best = n;
    for (int i = n-1; i>0; i--)
    {
        bool check  = true;
        for (int j = 0; j+i<n; j++) if (t[j]!=t[j+i]) check = false;
        if (check) best = i;
    }
    best = n-best;
    for (int i = 0; i<best; i++) cout<<t[i];
    for (int i = 0; i<k; i++)
    {
        for (int j = best; j<n; j++) cout<<t[j];
    }
}