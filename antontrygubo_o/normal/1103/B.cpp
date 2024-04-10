#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void print(vector<int> &a)
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

bool ask(ll x, ll y)
{
    cout<<"? "<<x<<' '<<y<<endl;
    cout.flush();
    char t;
    cin>>t;
    if (t=='x') return true;
    else return false;
}

void answer(ll a)
{
    cout<<"! "<<a<<endl;
    cout.flush();
}

void solve()
{
    bool t = ask(0, 1);
    if (t) {answer(1); return;}
    if (ask(1, 2)) {answer(2); return;}
    ll x = 2;
    ll y = 4;
    while (!ask(x, y)) {x*=2; y*=2;}
    ll l = x;
    ll r = y;
    while (r-l>1)
    {
        ll mid = (l+r)/2;
        if (ask(mid, x)) l = mid;
        else r = mid;
    }
    answer(r); return;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    string state;
    while (cin>>state)
    {
        if (state=="start") solve();
        if (state=="end") return 0;
    }

}