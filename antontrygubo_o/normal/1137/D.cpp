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

int p = 1e9 + 7;


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



char interact(vector<int> a)
{
    cout<<"next";
    for (auto it: a) cout<<' '<<it;
    cout<<endl;
    char s;
    cin>>s;
    string lol;
    for (int i = 0; i<(s-'0'); i++) cin>>lol;
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    char kek = '1';
    string s;
    while (kek!='2')
    {
        kek = interact({0, 1});
        kek = interact({0});
    }
    while (kek!='1')
    {
        kek = interact({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    }
    cout<<"done"<<endl;
    
    

}