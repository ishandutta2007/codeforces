#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define all(vr) vr.begin(),vr.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
const int N=1e5+10;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin>>n>>s;
    int cnt1=0,cnt0=0;
    for (int i=1;i<=n;i++)
        if (s[i-1]=='z') cnt0++;
        else if (s[i-1]=='n') cnt1++;
    for (int i=1;i<=cnt1;i++) cout<<"1 ";
    for (int i=1;i<=cnt0;i++) cout<<"0 ";
    return 0;
}