#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n,x;
    cin>>t;
    while (t--)
    {
        cin>>n>>x;
        int m=0,flag=0;
        for (int i=1,y;i<=n;i++)
        {
            cin>>y,m=max(m,y);
            if (y==x) flag=1;
        }
        if (flag==1) cout<<"1\n";
        else cout<<max(2,(x-1)/m+1)<<"\n";
    }
    return 0;
}