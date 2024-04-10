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


vector<int> cnt(string s)
{
    vector<int> res(2);
    for (int i = 0; i<int(s.length()); i++)
    {
        if (s[i] == '1') res[1]++;
        else res[0]++;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s, t;
    cin>>s>>t;
    vector<int> answer = Z(t);
    //print(answer);
    int idx = -1;
    for (int i = int(t.length())-1; i>=1; i--)
    {
        if (answer[i]>=int(t.length())-i) idx = i;
    }
    string adder;
    if (idx==-1) adder = t;
    else adder = t.substr(t.length()-idx, idx);
    auto S = cnt(s);
    auto T = cnt(t);
    auto ADDER = cnt(adder);
    if (S[0]<T[0]||S[1]<T[1]) 
    {
        cout<<s; return 0;
    }
    int cur0 = T[0];
    int cur1 = T[1];
    string cur = t;
    while (cur0+ADDER[0]<=S[0]&&cur1+ADDER[1]<=S[1])
    {
        cur0+=ADDER[0];
        cur1+=ADDER[1];
        cur+=adder;
    }
    for (int i = 0; i<S[0]-cur0; i++) cur+='0';
    for (int i = 0; i<S[1]-cur1; i++) cur+='1';
    cout<<cur;
     

}