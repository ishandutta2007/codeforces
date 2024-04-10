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

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

mt19937 rnd(228);

ll answer(vector<int> a)
{
    ll total = 0;
    ll counter = 1;
    for (int i = 1; i<a.size(); i++)
    {
        if (a[i]==a[i-1]) counter++;
        else {total+=(counter*(counter-1))/2; counter = 1; }
    }
    total+=(counter*(counter-1))/2;
    return total;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> a(n);
    get(a);
    int cur = 0;
    vector<int> even;
    vector<int> odd;
    even.push_back(0);
    for (int i = 1; i<=n; i++)
    {
        cur^=a[i-1];
        if (i%2==1) odd.push_back(cur);
        else even.push_back(cur);
        //cout<<cur<<endl;
    }
    sort(odd.begin(), odd.end());
    //print(odd);
    //print(even);
    sort(even.begin(), even.end());
    cout<<answer(odd) + answer(even);
    
    

}