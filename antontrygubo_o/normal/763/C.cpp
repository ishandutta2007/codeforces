#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(auto &a)
{
    for (auto s: a) cout<<s<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

int p;


int mul(int a, int b) {
    return (1LL * a%p * b%p) % p;
}

int add(int a, int b) {
    ll s = (a+b);
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

int inv(int n)
{
    return po(n, p-2);
}



vector<int> Z(string s)
{
int n = s.length();
vector<int> z(n);
int L = 0, R = 0;
for (int i = 1; i < n; i++) {
  if (i > R) {
    L = R = i;
    while (R < n && s[R-L] == s[R]) R++;
    z[i] = R-L; R--;
  } else {
    int k = i-L;
    if (z[k] < R-i+1) z[i] = z[k];
    else {
      L = i;
      while (R < n && s[R-L] == s[R]) R++;
      z[i] = R-L; R--;
    }
  }
}
return z;
}


bool check(vector<ll> &a, ll x, ll d)
{
    vector<ll> temp;
    int n = a.size();
    for (ll i = 0; i<n; i++) temp.push_back((x + i*d)%p);
    sort(temp.begin(), temp.end());
    return (a==temp);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int m, n;
    cin>>m>>n;
    p = m;
    vector<ll> a(n);
    get(a);
    sort(a.begin(), a.end());
    
    
    if (n==1) {cout<<a[0]<<' '<<0; return 0;}
    
    if (m==2)
    {
        for (int x = 0; x<2; x++)
        for (int d = 0; d<2; d++)
        if (check(a, x, d)) {cout<<x<<' '<<d; return 0;}
    }

    if (m==3)
    {
        for (int x = 0; x<3; x++)
        for (int d = 0; d<3; d++)
        if (check(a, x, d)) {cout<<x<<' '<<d; return 0;}
    }
    
    
    if (n%p==0)
    {
        vector<int> cnt(p);
        for (int i = 0; i<n; i++) cnt[a[i]]++;
        int zero = 0;
        for (int i = 0; i<p; i++) if (cnt[i]==0) zero++;
        if (zero==n-1)
        {
            int idx = 0;
            while (cnt[idx]==0) idx++;
            cout<<idx<<' '<<0; return 0;
        }
        int maxx = 0;
        int minn = n;
        for (int i = 0; i<p; i++)
        {
            maxx = max(maxx, cnt[i]);
            minn = min(minn, cnt[i]);
        }
        if (maxx!=minn) {cout<<-1; return 0;}
        cout<<0<<' '<<1; return 0;
    } 
    
    
    if (n%p==p-1)
    {
        vector<int> cnt(p);
        for (int i = 0; i<n; i++) cnt[a[i]]++;
        int zero = 0;
        for (int i = 0; i<p; i++) if (cnt[i]==0) zero++;
        if (zero==n-1)
        {
            int idx = 0;
            while (cnt[idx]==0) idx++;
            cout<<idx<<' '<<0; return 0;
        }
        int maxx = 0;
        int minn = n;
        for (int i = 0; i<p; i++)
        {
            maxx = max(maxx, cnt[i]);
            minn = min(minn, cnt[i]);
        }
        if (maxx!=minn+1) {cout<<-1; return 0;}
        int idx = 0;
        while (cnt[idx]!=minn) idx++;
        cout<<(idx+1)%p<<' '<<1; return 0;
    }
   
    if (n%p==1)
    {
        vector<int> cnt(p);
        for (int i = 0; i<n; i++) cnt[a[i]]++;
        int zero = 0;
        for (int i = 0; i<p; i++) if (cnt[i]==0) zero++;
        if (zero==n-1)
        {
            int idx = 0;
            while (cnt[idx]==0) idx++;
            cout<<idx<<' '<<0; return 0;
        }
        int maxx = 0;
        int minn = n;
        for (int i = 0; i<p; i++)
        {
            maxx = max(maxx, cnt[i]);
            minn = min(minn, cnt[i]);
        }
        if (maxx!=minn+1) {cout<<-1; return 0;}
        int idx = 0;
        while (cnt[idx]!=maxx) idx++;
        cout<<idx<<' '<<1; return 0;
    } 
    
    
    ll total = 0;
    for (int i = 0; i<n; i++) total = add(total, a[i]);
    total = mul(total, 2);
    int sum = mul(total, inv(n));
    

    
    int one = mul(sum, inv(2));
    for (int i = 0; i<n; i++) a[i] = add(a[i], -one);
    sort(a.begin(), a.end());
    /*cout<<one<<endl;
    print(a);*/
    
    
    ll sq = 0;
    for (int i = 0; i<n; i++) sq = add(sq, mul(a[i], a[i]));
    sq = mul(sq, 4);
    sq = mul(sq, inv(n));
    
    
    //Suppose n!=+-1(mod p);
    
    int dd = mul(sq, mul(3, inv(mul(n, n)-1)));
    //cout<<dd<<endl;
    
    if (n%2==1)
    {
        for (int i = 0; i<n; i++) if (mul(a[i], a[i])==dd)
        {
            int d = abs(a[i]);
            int x = mul(mul(n-1, d), inv(p-2));
            //cout<<d<<' '<<x<<endl;
            if (check(a, x, d)) {cout<<(x+one)%p<<' '<<d; return 0;}
            else {cout<<-1; return 0;}
        }
        cout<<-1; return 0;
    }
    
    if (n%2==0)
    {
        for (int i = 0; i<n; i++) if (mul(mul(a[i], a[i]), 4)==dd)
        {
            int d = abs(mul(2, a[i]));
            int x = mul(mul(n-1, d), inv(p-2));
            //cout<<x<<' '<<d<<endl;
            if (check(a, x, d)) {cout<<(x+one)%p<<' '<<d; return 0;}
            else {cout<<-1; return 0;}
        }
        cout<<-1; return 0;
    }    
    
    
    
    
}