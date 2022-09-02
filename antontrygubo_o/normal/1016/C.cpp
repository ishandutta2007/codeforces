#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 998244353;
const ll MAX = 100000000000;



int main()
{
ios_base::sync_with_stdio(false);
ll n;
cin>>n;
vector<vector<ll>> M;
for (int i = 0; i<2; i++)
{
    vector<ll> temp(n);
    M.push_back(temp);
}
for (int i = 0; i<n; i++) cin>>M[0][i];
for (int i = 0; i<n; i++) cin>>M[1][i];

vector<ll> back0 (n, 0);
back0[n-1] = M[0][n-1];
for (int i = 2; i<=n; i++) back0[n-i] = back0[n-i+1]+i*M[0][n-i];

vector<ll> back1 (n, 0);
back1[n-1] = M[1][n-1];
for (int i = 2; i<=n; i++) back1[n-i] =  back1[n-i+1]+i*M[1][n-i];

vector<ll> sums0(n, 0);
sums0[n-1] = M[0][n-1];
for (int i = 2; i<=n; i++) sums0[n-i] = sums0[n-i+1]+M[0][n-i];

vector<ll> sums1(n, 0);
sums1[n-1] = M[1][n-1];
for (int i = 2; i<=n; i++) sums1[n-i] = sums1[n-i+1]+M[1][n-i];




ll res = 0;


ll maxres = 0;
for (ll i = 0; i<n; i++)
{
    if (i%2==0)
    {
        ll temp = res+(n+i)*sums0[i]-back0[i];
        temp+=back1[i]+sums1[i]*(n+i-1);
        maxres = max(maxres, temp);
        res+=M[0][i]*(2*i);
        res+=M[1][i]*(2*i+1);
    }
    if (i%2==1)
    {
        ll temp = res+(n+i)*sums1[i]-back1[i];
        temp+=back0[i]+sums0[i]*(n+i-1);
        maxres = max(maxres, temp);
        res+=M[1][i]*(2*i);
        res+=M[0][i]*(2*i+1);
    }
    
}

cout<<maxres;

}