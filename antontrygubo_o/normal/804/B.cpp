#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void print(vector<ll> &a)
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
    string s;
    cin>>s;
    int n = s.length();
    ll cur = 0;
    ll answer = 0;
    for (int i = n-1; i>=0; i--)
    {
        if (s[i]=='b') cur = add(cur, 1);
        else {answer = add(answer, cur); cur = mul(cur, 2);}
    }
    cout<<answer;
}