#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=4e5+10,mod=1e9+7,inf=1e18;
int a[N],n;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        a[n+1]=-1;
        int g=0,s=0,b=0,check=1;
        for (int i=1;i<=n;i++)
            if (a[i]!=a[i+1])
            {
                g=i;
                break;
            }
        if (g*2+1>n) check=0;
        for (int i=g*2+1;i<=n;i++)
            if (a[i]!=a[i+1])
            {
                s=i-g;
                break;
            }
        if (g+s+g+1>n) check=0;
        for (int i=g*2+s+1;i<=n;i++)
            if (a[i]!=a[i+1])
            {
                b=i-s-g;
                break;
            }
        if (g+s+b>n/2) check=0;
        int tmp=0;
        for (int i=g+s+b+1;i<=n;i++)
            if (a[i]==a[i+1]) tmp++;
            else
            {
                tmp++;
                if (g+s+b+tmp<=n/2) b+=tmp;
                else break;
                tmp=0;
            }
        if (check) cout<<g<<" "<<s<<" "<<b<<"\n";
        else cout<<"0 0 0\n";
    }
    return 0;
}