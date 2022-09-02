#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double

void print(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

const ll p = 1e9 + 7;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    for (int i = 0; i<n; i++) cin>>b[i];
    vector<ll> a1(n-1);
    vector<ll> b1(n-1);
    for (int i = 0; i<n-1; i++)
    {
        a1[i] = a[i+1] - a[i];
        b1[i] = b[i+1] - b[i];    
    }
    sort(a1.begin(), a1.end());
    sort(b1.begin(), b1.end());
    
    bool check = true;
    if (a[0]!=b[0]||a[n-1]!=b[n-1]) check = false;
    for (int i= 0; i<n-1; i++) if (a1[i]!=b1[i]) check = false;
    if (check) cout<<"Yes";
    else cout<<"No";
    
}