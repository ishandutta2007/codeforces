#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

struct varf
{
    long long int x;
    long long int h;
}v[100005];
int n;
vector<int> graf[100005];
varf stiva[100005];
int stiva2[100005];

bitset<100005> viz;
int hul;
int poz;
int euler[300005];
int first[100005];
int h[300005];

void dfs(int nod)
{
    //cout<<"dfs("<<nod<<")\n";
    euler[poz]=nod;
    first[nod]=poz;
    h[poz++]=hul;
    hul++;

    vector<int>::iterator it;
    for(it=graf[nod].begin();it!=graf[nod].end();it++)
    {
        if(!viz[*it])
        {
            viz[*it]=1;
            dfs(*it);
            euler[poz]=nod;
            h[poz++]=hul-1;
        }
    }
    hul--;
}

int logar[300005];
int din[20][300005];

void prec()
{
    int i;
    for(i=2;i<=(poz+6);i++)
        logar[i]=logar[i/2]+1;

    for(i=1;i<=poz;i++)
        din[0][i]=i;

    int j;
    for(i=1;(1<<i)<=poz;i++)
    {
        for(j=1;(j+(1<<i)-1)<=poz;j++)
        {
            if(h[din[i-1][j]]<h[din[i-1][j+(1<<(i-1))]])
                din[i][j]=din[i-1][j];
            else
                din[i][j]=din[i-1][j+(1<<(i-1))];
        }
    }
}

inline int lca(int x,int y)
{
    x=first[x];
    y=first[y];

    if(x>y)
        swap(x,y);

    int l=logar[(y-x+1)];

    if(h[din[l][x]]<h[din[l][y-(1<<l)+1]])
        return euler[din[l][x]];
    return euler[din[l][y-(1<<l)+1]];
}

int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i].x>>v[i].h;

    reverse(v+1,v+n+1);

    poz=0;
    for(i=1;i<=n;i++)
    {
        //cout<<"da "<<i<<endl;
        while(poz>=2)
        {
            if(((1ll*stiva[poz].x-stiva[poz-1].x)*(1ll*v[i].h-stiva[poz-1].h))<((1ll*stiva[poz].h - 1ll*stiva[poz-1].h)*(1ll*v[i].x-1ll*stiva[poz-1].x)))
            //if(1)
            {
                poz--;
             //   cout<<"pop"<<endl;
            }
            else
                break;
        }

        if(poz>=1)
            graf[stiva2[poz]].push_back(i);

        stiva[++poz]=v[i];
        stiva2[poz]=i;
    }

    /*for(i=1;i<=n;i++)
    {
        vector<int>::iterator it;
        for(it=graf[i].begin();it!=graf[i].end();it++)
            cout<<*it<<' ';
        cout<<endl;
    }*/

    hul=0;
    poz=1;
    dfs(1);
    poz--;
    /*
    cout<<"euler"<<endl;
    for(i=1;i<=poz;i++)
        cout<<h[i]<<' ';
    cout<<"poz este "<<poz<<endl;

    cout<<"euler"<<endl;
    */
    prec();

    int q,a,b;

    cin>>q;

    bool pr=true;
    for(i=0;i<q;i++)
    {
        cin>>a>>b;
        a=n-a+1;
        b=n-b+1;
        //cout<<a<<' '<<b<<" adevarat\n";

        if(pr)
            pr=false;
        else
            cout<<' ';
        cout<<n-lca(a,b)+1;

        //cout<<lca(a,b)<<" atat\n";
    }
    cout<<'\n';

    return 0;
}