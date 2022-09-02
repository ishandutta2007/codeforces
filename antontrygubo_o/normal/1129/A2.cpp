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

int p = 998244353;


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




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    vector<vector<int>> G(n);
    int a, b;
    for (int i = 0; i<m; i++)
    {
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
    }
    vector<int> timer(n);
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<G[i].size(); j++) G[i][j] = (G[i][j]+n-i)%n;
        if (G[i].size()==0) {timer[i] = 0; continue;}
        int minn = n;
        for (int j = 0; j<G[i].size(); j++) minn = min(G[i][j], minn);
        timer[i] = minn + n*(int(G[i].size())-1);
    }
    
    //print(timer);
    
    vector<int> ans(n);
    for (int i = 0; i<n; i++)
    {
        for (int j = i; j<i+n; j++) if (timer[j%n]!=0)
        {
            ans[i] = max(ans[i], timer[j%n] + j-i);
        }
    }
    
    for (int i = 0; i<n; i++) cout<<ans[i]<<' ';
    

}