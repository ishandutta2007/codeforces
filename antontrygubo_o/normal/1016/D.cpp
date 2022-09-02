#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 998244353;
const ll MAX = 100000000000;

int main()
{
ios_base::sync_with_stdio(false);
int n, m;
cin>>n>>m;
ll a[n];
ll b[m];
for (int i = 0; i<n; i++) cin>>a[i];
for (int i = 0; i<m; i++) cin>>b[i];
ll res1 = 0;
ll res2 = 0;
for (int i = 0; i<n; i++) res1=res1^a[i];
for (int i = 0; i<m; i++) res2=res2^b[i];
if (res1!=res2) {cout<<"NO"; return 0;}
else
{
    cout<<"YES"<<endl;
    for (int i = 0; i<n-1; i++)
    {
        for (int i = 0; i<m-1; i++) cout<<0<<' ';
        cout<<a[i]<<endl;
    }
    for (int i = 0; i<m-1; i++) cout<<b[i]<<' ';
    cout<<(res1^a[n-1]^b[m-1]);
}
}