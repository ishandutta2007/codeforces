#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,mod=1e9+7,inf=1e18;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cnt=0,n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        char ch;
        cin>>ch;
        if (ch=='8') cnt++;
    }
    cout<<min(cnt,n/11);
    return 0;
}