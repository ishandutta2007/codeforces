#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define id pair<int, double>
#define ii pair<id, id>
#define di pair<double, ii>

void print(vector<int> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

const ll p = 1e9 + 9;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); 
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    
    if (a[0]==a[1])
    {
        if (a[1]==a[2])
        {
            ll i = 0; 
            while (i+1<n&&a[i+1]==a[0]) i++;
            cout<<(i*(i-1)*(i+1))/6;
            return 0;
        }
        else
        {
            ll i = 2; 
            while (i+1<n&&a[i+1]==a[2]) i++;
            cout<<i-1; return 0;
        }
    }
    else
    {
        if (a[1]==a[2])
        {
            ll i = 1; 
            while (i+1<n&&a[i+1]==a[1]) i++;
            cout<<(i*(i-1))/2;
            return 0;
        }
        else
        {
            ll i = 2; 
            while (i+1<n&&a[i+1]==a[2]) i++;
            cout<<i-1; return 0;
        }
    }
    
}