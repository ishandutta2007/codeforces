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
/*
const int p = 1e9 + 7;


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

*/

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

vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

bool divide(int n)
{
    cout<<n<<endl;
    string s;
    cin>>s;
    return (s=="yes");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int i = 0;
    vector<bool> d(25);
    for (int i = 0; i<4; i++) d[i] = divide(p[i]);
    
    int cnt = 0;
    for (int i = 0; i<4; i++) cnt+=d[i];
    if (cnt==0) {cout<<"prime"<<endl; return 0;}
    if (cnt>1) {cout<<"composite"<<endl; return 0;}    
    int j = 0;
    while (d[j]==0) j++;
    if (divide(p[j]*p[j])) {cout<<"composite"<<endl; return 0;}
    for (int i = 4; i<16; i++) if (divide(p[i])) {cout<<"composite"<<endl; return 0;}
    cout<<"prime"<<endl; return 0;



    
}