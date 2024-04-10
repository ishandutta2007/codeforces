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
int n,d,a[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>d;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=2;i<=n && d>0;i++)
            if (a[i]*(i-1)<=d) a[1]+=a[i],d-=a[i]*(i-1);
            else
            {
                a[1]+=d/(i-1);
                d=0;
            }
        cout<<a[1]<<"\n";
    }
    return 0;
}