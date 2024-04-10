#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

const ll p = 78294349;

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
    ll n, m, k;
    cin>>n>>m>>k;
    vector<ll> b(n);
    get(b);
    ll Sum = b[n-1] - b[0] + 1;
    vector<ll> diff;
    for (int i = 0; i<n-1; i++) diff.push_back(b[i+1]-b[i]-1);
    sort(diff.begin(), diff.end());
    //print(diff);
    for (int i = 0; i<k-1; i++) Sum-=diff[n-2-i];
    cout<<Sum;
}