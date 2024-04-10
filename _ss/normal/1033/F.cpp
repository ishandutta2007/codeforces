#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll maxn=6e5+1,mod=1e9+7,inf=1e18;

int w,n,m,pow3[13];
string s;
ll cnt[maxn],res;

void read()
{
    cin>>w>>n>>m;
    pow3[0]=1;
    for (int i=1;i<=w;i++) pow3[i]=pow3[i-1]*3;
    int x;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        int y=0,bit=0;
        while (x)
        {
            y+=(x&1)*pow3[bit];
            bit++;
            x>>=1;
        }
        cnt[y]++;
    }
}

void dfs(int dth,int val,int lastbit2)
{
    if (dth==w)
    {
        if (lastbit2!=-1) cnt[val]=cnt[val-pow3[lastbit2]]+cnt[val-pow3[lastbit2]*2];
        return;
    }
    for (int i=0;i<2;i++) dfs(dth+1,val+pow3[dth]*i,lastbit2);
    dfs(dth+1,val+pow3[dth]*2,dth);
}

void query(int dth,int val1,int val2)
{
    if (dth==w)
    {
        res+=cnt[val1]*cnt[val2];
        return;
    }
    if (s[dth]=='A')
    {
        query(dth+1,val1,val2+pow3[dth]*2);
        query(dth+1,val1+pow3[dth],val2);
    }
    else if (s[dth]=='O') query(dth+1,val1,val2);
    else if (s[dth]=='X')
    {
        query(dth+1,val1,val2);
        query(dth+1,val1+pow3[dth],val2+pow3[dth]);
    }
    else if (s[dth]=='a') query(dth+1,val1+pow3[dth],val2+pow3[dth]);
    else if (s[dth]=='o')
    {
        query(dth+1,val1+pow3[dth],val2+pow3[dth]*2);
        query(dth+1,val1,val2+pow3[dth]);
    }
    else
    {
        query(dth+1,val1,val2+pow3[dth]);
        query(dth+1,val1+pow3[dth],val2);
    }
}

string inverse(string st)
{
    string ans="";
    for (int i=st.size()-1;i+1;i--) ans+=s[i];
    return ans;
}

void process()
{
    dfs(0,0,-1);
    for (int i=1;i<=m;i++)
    {
        cin>>s;
        s=inverse(s);
        res=0;
        query(0,0,0);
        printf("%I64d\n",res);
    }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    process();
    return 0;
}