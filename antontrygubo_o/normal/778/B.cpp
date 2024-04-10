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

const int p =  1e9 + 7;


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

const int N = 1000;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    map<string, bitset<N>> dp1;
    map<string, bitset<N>> dp2;
    bitset<N> zero;
    bitset<N> one;
    for (int i = 0; i<N; i++) one[i] = 1;
    dp1["?"] = zero;
    dp2["?"] = one;

    
    string a, op, b;
    
    vector<string> guys;

    for (int i = 0; i<n; i++)
    {
        string param;
        cin>>param;
        guys.push_back(param);
        cin>>a>>a;
        if (a[0]=='0'||a[0]=='1')
        {
            dp1[param] = bitset<N>(a);
            dp2[param] = bitset<N>(a);
        }
        else
        {
            cin>>op>>b;
            if (op=="AND") 
            {
                dp1[param] = dp1[a]&dp1[b];
                dp2[param] = dp2[a]&dp2[b];
            }
            if (op=="OR") 
            {
                dp1[param] = dp1[a]|dp1[b];
                dp2[param] = dp2[a]|dp2[b];
            }
            if (op=="XOR") 
            {
                dp1[param] = dp1[a]^dp1[b];
                dp2[param] = dp2[a]^dp2[b];
            }
        }
    }
    vector<int> cnt1(m);
    vector<int> cnt2(m);
    for (auto it: guys)
    {
        for (int i = 0; i<m; i++) {cnt1[i]+=dp1[it][i]; cnt2[i]+=dp2[it][i];}
    }
    
    string ans1, ans2;
    for (int i = m-1; i>=0; i--)
    {
        if (cnt1[i]<cnt2[i])
        {
            ans1+='0';
            ans2+='1';
        }
        else if (cnt1[i]==cnt2[i])
        {
            ans1+='0';
            ans2+='0';
        }
        else
        {
            ans1+='1';
            ans2+='0';
        }
    }
    
    cout<<ans1<<endl<<ans2<<endl;
    /*print(cnt1);
    print(cnt2);
    cout<<"?"<<endl<<dp1["?"]<<endl<<dp2["?"]<<endl;
    for (auto it: guys) cout<<it<<endl<<dp1[it]<<endl<<dp2[it]<<endl;*/
       
}