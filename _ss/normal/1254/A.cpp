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
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;
char typ[65],a[110][110],b[110][110];
int m,n,k,sl[65];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i=1;i<=10;i++) typ[i]=(char)((int)('0')+i-1);
    for (int i=11;i<=36;i++) typ[i]=(char)((int)('A')+i-11);
    for (int i=37;i<=62;i++) typ[i]=(char)((int)('a')+i-37);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>m>>n>>k;
        int cnt=0;
        for (int i=1;i<=m;i++)
            for (int j=1;j<=n;j++)
            {
                cin>>a[i][j];
                if (a[i][j]=='R') cnt++;
            }
        for (int i=1;i<=k;i++) sl[i]=cnt/k;
        for (int i=1;i<=cnt%k;i++) sl[i]++;
        int l=1;
        cnt=0;
        for (int i=1;i<=m;i++)
        {
            if (i&1) {
            for (int j=1;j<=n;j++)
            {
                if (a[i][j]=='R') cnt++;
                if (cnt>sl[l]) l++,cnt=1;
                b[i][j]=typ[l];
            } }
            else {
                for (int j=n;j>0;j--)
            {
                if (a[i][j]=='R') cnt++;
                if (cnt>sl[l]) l++,cnt=1;
                 b[i][j]=typ[l];
            }
            }
        }
        for (int i=1;i<=m;i++)
        {
            for (int j=1;j<=n;j++) cout<<b[i][j];
            cout<<"\n";
        }
    }
    return 0;
}