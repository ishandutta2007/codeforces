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
const int N=1e6+10;
char s[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>(s+1);
    int n=strlen(s+1),mn=100;
    for (int i=1;i<=n;i++)
    {
        int val=s[i]-'a'+1;
        if (val<=mn) cout<<"Mike\n";
        else cout<<"Ann\n";
        mn=min(mn,val);
    }
    return 0;
}