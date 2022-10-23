#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=2e5+10;
char a[N];
int n,ps[30][N];
int main()
{
    //freopen("ss.inp","r",stdin);
    scanf("%s",(a+1));
    n=strlen(a+1);
    for (int i=1;i<=n;i++)
    {
        ps[a[i]-'a'+1][i]++;
        for (int j=1;j<=26;j++) ps[j][i]+=ps[j][i-1];
    }
    int q;
    cin>>q;
    for (int i=1,l,r;i<=q;i++)
    {
        cin>>l>>r;
        int cnt=0;
        for (int j=1;j<=26;j++)
            if (ps[j][r]-ps[j][l-1]>0) cnt++;
        if ((r==l) || (cnt==2 && a[l]!=a[r]) || (cnt>2)) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}