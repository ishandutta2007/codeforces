#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define id pair<int, double>
#define ii pair<id, id>
#define di pair<double, ii>

void print(vector<ll> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

const ll p = 1e9 + 9;

ll count(vector<ll> a)
{
    ll n = a.size();
    vector<ll> b(n);
    b[0] = 0;
    for (int i = 1; i<n; i++)
    {
        if (a[i-1]>=a[i]) {b[i] = i; continue;}
        int j = i;
        while (1)
        {
            j = b[j-1];
            if (j==0) {b[i] = 0; break;}
            if (a[j-1]>=a[i]) {b[i] = j; break;}
        }
    }
    
    vector<ll> c(n);
    c[n-1] = n-1;
    for (int i = n-2; i>=0; i--)
    {
        if (a[i+1]>a[i]) {c[i] = i; continue;}
        int j = i;
        while (1)
        {
            j = c[j+1];
            if (j==n-1) {c[i] = n-1; break;}
            if (a[j+1]>a[i]) {c[i] = j; break;}
        }
    }
    ll answer = 0;
    for (int i = 0; i<n; i++) answer+=a[i]*(i-b[i]+1)*(c[i]-i+1);
    //print(b);
    //print(c);
    return answer;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<ll> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    ll res = 0;
    res+=count(a);
    for (int i = 0; i<n; i++) a[i] = -a[i];
    res+=count(a);
    cout<<res;
    
    
    
}