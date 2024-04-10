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

vector<int> z_func(string s)
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

vector<string> bad = {"1111", "0111", "1010", "1100"};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    string s;
    int m;
    cin>>m;
    char temp;
    ll total = 0;
    for (int i = 1; i<=m; i++)
    {
        cin>>temp;
        s = temp+s;
        vector<ll> counter(i+1);
        counter[0] = 1;
        for (int j = 1; j<=i; j++)
        {
            if (j>=1) counter[j] = add(counter[j], counter[j-1]);
            if (j>=2) counter[j] = add(counter[j], counter[j-2]); 
            if (j>=3) counter[j] = add(counter[j], counter[j-3]);
            if (j>=4)
            {
                bool check = true;
                for (auto it: bad) if (it==s.substr(j-4, 4)) check = false;
                if (check) counter[j] = add(counter[j], counter[j-4]);
            }
        }
        
        vector<int> temp_z = z_func(s);
        int maxx = 0;
        for (int j = 0; j<temp_z.size(); j++) maxx = max(maxx, temp_z[j]);
        for (int j = maxx+1; j<=i; j++) total = add(total, counter[j]);
        cout<<total<<endl;
    }

    
    

}