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
    if (deg%2==1) return mul(po(a, deg-1), a);
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}

vector<int> fac(10000);
vector<int> invfac(10000);

void init()
{
    fac[0] = 1;
    for (int i = 1; i<10000; i++) fac[i] = mul(fac[i-1], i);
    for (int i = 0; i<10000; i++) invfac[i] = inv(fac[i]);
}

int C(int n, int k)
{
    if (n<k) return 0;
    return mul( mul(invfac[k], invfac[n-k]), fac[n]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    int n;
    string s;
    cin>>n>>s;
    vector<vector<int>> pos(26);
    for (int i = 0; i<n; i++) pos[s[i]-'a'].push_back(i);
    vector<vector<ll>> answer(n, vector<ll>(n+1));
    for (int i = n-1; i>=0; i--)
    {
        answer[i][1] = 1;
        for (int j = 0; j<26; j++) if ((s[i]-'a')!=j)
        {
            if (pos[j].size()==0) continue;
            if (pos[j][(int)(pos[j].size())-1] < i) continue;
            int k = lower_bound(pos[j].begin(), pos[j].end(), i) - pos[j].begin();
            for (int l = 1; l<n; l++) answer[i][l+1] = add(answer[i][l+1], answer[pos[j][k]][l]);
        }
    }
    
    vector<ll> total(n+1);
    for (int i = 0; i<26; i++) if (pos[i].size()!=0)
    {
        int t = pos[i][0];
        for (int j = 0; j<=n; j++) total[j] = add(total[j], answer[t][j]);
    }

    //print(total);

    int result = 0;
    for (int i = 1; i<=n; i++) result = add(result, mul(total[i], C(n-1, i-1)));
    
    cout<<result;
}