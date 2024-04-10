#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
const ll maxn=(1<<9)+5,maxint=2e9+1;
int a[maxn],mark[10],cal[maxn];
pii b[maxn],min1,min2,mc[maxn],mark_ans,ans;

int enc()
{
    int d,x;
    cin>>d;
    for (int j=1;j<=9;j++) mark[j]=0;
        for (int j=1;j<=d;j++)
        {
            cin>>x;
            mark[x]=1;
        }
    int k=0;
    for (int j=1;j<=9;j++)
        if (mark[j]) k+=1<<(j-1);
    return k;
}

bool ss(pii t1,pii t2)
{
    if (t1.fi!=t2.fi) return (t1.fi>t2.fi);
    return (t1.se<t2.se);
}
int main()
{
    //freopen("ss.inp","r",stdin);
    ans.se=maxint;
    min1={maxint,0};
    min2=min1;
    int n,m,c;
    pii tmp;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        int k=enc();
        a[k]++;
    }
    for (int i=1;i<=m;i++)
    {
        cin>>c;
        tmp={c,i};
        int k=enc();
        if (b[k].fi) b[k]=min(b[k],tmp); else b[k]={c,i};
        if (tmp<min1)
        {
            min2=min1;
            min1=tmp;
        }
        else if (tmp<min2) min2=tmp;
    }
    for (int i=1;i<(1<<9);i++)
        for (int j=1;j<(1<<9);j++)
            if ((i & j)==j) cal[i]+=a[j];
    pii msl,sl;
    for (int i=1;i<(1<<9);i++)
    if (b[i].fi)
    {
        msl.fi=b[i].se;
        sl={cal[i],b[i].fi};
        if (b[i].se!=min1.se) msl.se=min1.se,sl.se+=min1.fi;
        else msl.se=min2.se,sl.se+=min2.fi;
        if (ss(sl,ans)) ans=sl,mark_ans=msl;
    }

    for (int i=1;i<(1<<9);i++)
        for (int j=i+1;j<(1<<9);j++)
            if (b[i].fi && b[j].fi)
            {
                sl={cal[i | j],b[i].fi+b[j].fi};
                msl={b[i].se,b[j].se};
                if (ss(sl,ans)) ans=sl,mark_ans=msl;
            }
    cout<<mark_ans.fi<<" "<<mark_ans.se;
    //cout<<cal[374];
    //cout<<ans.fi;
    //cout<<min2.fi<<" "<<min2.se;
    return 0;
}