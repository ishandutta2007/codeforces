
#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#pragma GCC optimize ("O3")
#define time pdojegoritg
#define int long long
typedef long long ll;
typedef long double ld;

struct Card
{
    int p,c,lvl;
};

int n,k,a[300][300],use[300],pred[300];
Card card[300];
bool geted;
void clear_(int cnt)
{
    geted=0;
    for (int i=0;i<=cnt;i++)
    {
        use[i]=0;
        pred[i]=0;
    }

}

void dfs(int u, int cnt)
{
    if (u==cnt) geted=1;
    for (int i=0;i<=cnt;i++)
        if (use[i]==0 && a[u][i]!=0 && !geted)
        {
            pred[i]=u;
            use[i]=min(use[u],a[u][i]);
            dfs(i,cnt);
        }
}

int try_(int cnt)
{
    clear_(cnt);
    use[0]=1e9;
    dfs(0,cnt);

    int now=cnt;
    while (now!=0)
    {
        a[pred[now]][now]-=use[cnt];
        a[now][pred[now]]+=use[cnt];
        now=pred[now];
    }
    return(use[cnt]);

}

int mxpotok(int cnt)
{
    int ans=0;
    int now=1;
    do
    {
        now=try_(cnt);
        //cout<<now<<'\n';
        ans+=now;
        /*cout<<'\n';
        for (int i=0;i<=cnt;i++)
        {
            for (int j=0;j<=cnt;j++)
                cout<<a[i][j]<<' ';
            cout<<'\n';
        }*/
    } while (now);
    return(ans);
}

bool simple(int a)
{
    for (int i=2;i<=sqrt(a);i++)
        if (a%i==0) return(0);
    return(1);
}

int getans(vector<Card> vec)
{
    for (int i=0;i<=vec.size()+1;i++)
        for (int j=0;j<vec.size()+1;j++)
        a[i][j]=0;
    for (int i=1;i<=vec.size();i++)
        for (int j=1;j<=vec.size();j++)
            if (simple(vec[i-1].c+vec[j-1].c) && vec[i-1].c%2==0 && vec[j-1].c%2==1)
                a[i][j]=1e9;

    for (int i=1;i<=vec.size();i++)
        if (vec[i-1].c%2==0) a[0][i]=vec[i-1].p;

    for (int i=1;i<=vec.size();i++)
        if (vec[i-1].c%2==1) a[i][vec.size()+1]=vec[i-1].p;
    /*
    cout<<'\n';
    for (int i=0;i<=vec.size()+1;i++)
    {
        for (int j=0;j<=vec.size()+1;j++)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }
    */
    int now=mxpotok(vec.size()+1);
    int sum=0;
    for (int i=0;i<vec.size();i++)
        sum+=vec[i].p;

    return(sum-now);
}

bool check(int mxlvl)
{
    vector<Card> usable;
    for (int i=1;i<=n;i++)
        if (card[i].lvl<=mxlvl && card[i].c!=1) usable.pb(card[i]);
    int mx=0;
    for (int i=1;i<=n;i++)
        if (card[i].lvl<=mxlvl && card[i].c==1)
        mx=max(mx,card[i].p);
    if (mx!=0)
        usable.pb({mx,1,0});
    /*cout<<'\n';
    for (int i=0;i<usable.size();i++)
        cout<<usable[i].p<<' '<<usable[i].c<<' '<<usable[i].lvl<<'\n';*/
    return(getans(usable)>=k);
}

signed main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>card[i].p>>card[i].c>>card[i].lvl;
    //cout<<check(4);
    //return(0);
    for (int i=0;i<=100;i++)
    if (check(i))
    {
        cout<<i<<'\n';
        return(0);
    }
    cout<<-1;
}
/*
*/