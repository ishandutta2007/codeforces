#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
/*#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

typedef long double DOUBLE;
typedef complex<DOUBLE> COMPLEX;
typedef vector<DOUBLE> VD;
typedef vector<COMPLEX> VC;

void print(auto &a)
{
    for (auto s: a) cout<<s<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

const int p = 998244353;


int mul(int a, int b) {
    return (1LL * a%p * b%p) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}

int sub(int a, int b) {
    int s = (a-b);
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



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    
    vector<vector<int>> pos(26);
    for (int i = 0; i<n; i++) pos[s[i]-'a'].push_back(i);

    
    vector<vector<vector<int>>> dp(251, vector<vector<int>>(251, vector<int>(251)));
    vector<char> a;
    vector<char> b;
    vector<char> c;
    dp[0][0][0] = -1;
    
    for (int i = 0; i<q; i++)
    {
        //cout<<dp[0][0][0]<<endl;
        char op; int idx;
        cin>>op>>idx;
        if (op=='-')
        {
            if (idx==1) a.pop_back();
            if (idx==2) b.pop_back();
            if (idx==3) c.pop_back();
            if (dp[a.size()][b.size()][c.size()]<n) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            continue;
        }
        char x;
        cin>>x;
        if (idx==1) a.push_back(x);
        if (idx==2) b.push_back(x);
        if (idx==3) c.push_back(x);
        if (idx==1)
        {
            for (int j = 0; j<=b.size(); j++)
            for (int k = 0; k<=c.size(); k++) 
            {
                
                int temp;
                if (a.size()>0)
                {
                    dp[a.size()][j][k] = n;
                    temp = dp[a.size()-1][j][k];
                    temp = upper_bound(pos[a[a.size()-1]-'a'].begin(), pos[a[a.size()-1]-'a'].end(), temp) - pos[a[a.size()-1]-'a'].begin();
                    if (temp>=pos[a[a.size()-1]-'a'].size()) temp = n;
                    else temp = pos[a[a.size()-1]-'a'][temp];
                
                    dp[a.size()][j][k] = min(dp[a.size()][j][k], temp);
                }
                if (j>0)
                {
                    temp = dp[a.size()][j-1][k];
                    temp = upper_bound(pos[b[j-1]-'a'].begin(), pos[b[j-1]-'a'].end(), temp) - pos[b[j-1]-'a'].begin();
                    if (temp>=pos[b[j-1]-'a'].size()) temp = n;
                    else temp = pos[b[j-1]-'a'][temp];
                    dp[a.size()][j][k] = min(dp[a.size()][j][k], temp);                    
                }
                if (k>0)
                {
                    temp = dp[a.size()][j][k-1];
                    temp = upper_bound(pos[c[k-1]-'a'].begin(), pos[c[k-1]-'a'].end(), temp) - pos[c[k-1]-'a'].begin();
                    if (temp>=pos[c[k-1]-'a'].size()) temp = n;
                    else temp = pos[c[k-1]-'a'][temp];
                    dp[a.size()][j][k] = min(dp[a.size()][j][k], temp);                    
                }
                
            }
        }

        if (idx==2)
        {
            for (int j = 0; j<=a.size(); j++)
            for (int k = 0; k<=c.size(); k++) 
            {
                int temp;
                if (b.size()>0)
                {
                    dp[j][b.size()][k] = n;
                    temp = dp[j][b.size()-1][k];
                    temp = upper_bound(pos[b[b.size()-1]-'a'].begin(), pos[b[b.size()-1]-'a'].end(), temp) - pos[b[b.size()-1]-'a'].begin();
                    if (temp>=pos[b[b.size()-1]-'a'].size()) temp = n;
                    else temp = pos[b[b.size()-1]-'a'][temp];
                
                    dp[j][b.size()][k] = min(dp[j][b.size()][k], temp);
                }
                if (j>0)
                {
                    temp = dp[j-1][b.size()][k];
                    temp = upper_bound(pos[a[j-1]-'a'].begin(), pos[a[j-1]-'a'].end(), temp) - pos[a[j-1]-'a'].begin();
                    if (temp>=pos[a[j-1]-'a'].size()) temp = n;
                    else temp = pos[a[j-1]-'a'][temp];
                    dp[j][b.size()][k] = min(dp[j][b.size()][k], temp);                    
                }
                if (k>0)
                {
                    temp = dp[j][b.size()][k-1];
                    temp = upper_bound(pos[c[k-1]-'a'].begin(), pos[c[k-1]-'a'].end(), temp) - pos[c[k-1]-'a'].begin();
                    if (temp>=pos[c[k-1]-'a'].size()) temp = n;
                    else temp = pos[c[k-1]-'a'][temp];
                    dp[j][b.size()][k] = min(dp[j][b.size()][k], temp);                    
                }
                
            }
        }
        if (idx==3)
        {
            for (int j = 0; j<=a.size(); j++)
            for (int k = 0; k<=b.size(); k++) 
            {
                int temp;
                if (c.size()>0)
                {
                    dp[j][k][c.size()] = n;
                    temp = dp[j][k][c.size()-1];
                    temp = upper_bound(pos[c[c.size()-1]-'a'].begin(), pos[c[c.size()-1]-'a'].end(), temp) - pos[c[c.size()-1]-'a'].begin();
                    if (temp>=pos[c[c.size()-1]-'a'].size()) temp = n;
                    else temp = pos[c[c.size()-1]-'a'][temp];
                
                    dp[j][k][c.size()] = min(dp[j][k][c.size()], temp);
                }
                if (j>0)
                {
                    temp = dp[j-1][k][c.size()];
                    temp = upper_bound(pos[a[j-1]-'a'].begin(), pos[a[j-1]-'a'].end(), temp) - pos[a[j-1]-'a'].begin();
                    if (temp>=pos[a[j-1]-'a'].size()) temp = n;
                    else temp = pos[a[j-1]-'a'][temp];
                    dp[j][k][c.size()] = min(dp[j][k][c.size()], temp);                 
                }
                if (k>0)
                {
                    temp = dp[j][k-1][c.size()];
                    temp = upper_bound(pos[b[k-1]-'a'].begin(), pos[b[k-1]-'a'].end(), temp) - pos[b[k-1]-'a'].begin();
                    if (temp>=pos[b[k-1]-'a'].size()) temp = n;
                    else temp = pos[b[k-1]-'a'][temp];
                    dp[j][k][c.size()] = min(dp[j][k][c.size()], temp);                   
                }
                
            }

        }
        
        if (dp[a.size()][b.size()][c.size()]<n) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    /*cout<<s<<endl;
    print(a);
    print(b);
    print(c);
    for (int i = 0; i<=a.size(); i++)
    for (int j = 0; j<=b.size(); j++)
    for (int k = 0; k<=c.size(); k++) cout<<i<<' '<<j<<' '<<k<<": "<<dp[i][j][k]<<endl;*/
}