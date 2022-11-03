#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=2e5+100;


int last_root1=0;
int last_root2=0;

int root1[arr],root2[arr];

struct Node
{
    int s, l, r;

    Node()
    {
        s=0;
        l=0;
        r=0;
    }
};

Node v1[40*arr],v2[40*arr];

int get1(int i, int tl, int tr, int l, int r)
{
    if (tl>=l && tr<=r)
        return(v1[i].s);
    if (tl>r || tr<l)
        return(0);

    int d=(tl+tr)/2;
    return(get1(v1[i].l,tl,d,l,r)+get1(v1[i].r,d+1,tr,l,r));
}

int get2(int i, int tl, int tr, int l, int r)
{
    if (tl>=l && tr<=r)
        return(v2[i].s);
    if (tl>r || tr<l)
        return(0);

    int d=(tl+tr)/2;
    return(get2(v2[i].l,tl,d,l,r)+get2(v2[i].r,d+1,tr,l,r));
}

void change1(int i1, int i2, int tl, int tr, int x, int y)
{
    v1[i2]=v1[i1];

    if (tl==tr)
    {
        v1[i2].s=y;
        return;
    }

    int d=(tl+tr)/2;
    if (x<=d)
    {
        v1[i2].l=++last_root1;
        change1(v1[i1].l,v1[i2].l,tl,d,x,y);
    } else
    {
        v1[i2].r=++last_root1;
        change1(v1[i1].r,v1[i2].r,d+1,tr,x,y);
    }

    v1[i2].s=v1[v1[i2].l].s+v1[v1[i2].r].s;
}

void pluss2(int i1, int i2, int tl, int tr, int x, int y)
{
    v2[i2]=v2[i1];

    if (tl==tr)
    {
        v2[i2].s+=y;
        return;
    }

    int d=(tl+tr)/2;

    if (x<=d)
    {
        v2[i2].l=++last_root2;
        pluss2(v2[i1].l,v2[i2].l,tl,d,x,y);
    } else
    {
        v2[i2].r=++last_root2;
        pluss2(v2[i1].r,v2[i2].r,d+1,tr,x,y);
    }

    v2[i2].s=v2[v2[i2].l].s+v2[v2[i2].r].s;
}



signed main()
{
    int q;
    cin>>q;
    map<string,int> name;
    int last=0;
    int now_root1=0;
    int now_root2=0;

    for (int i=1;i<=q;i++)
    {
        string todo;
        cin>>todo;
        if (todo=="set")
        {
            string s;
            int x;
            cin>>s>>x;
            if (!name.count(s))
                name[s]=++last;
            int a=name[s];
            //cout<<a<<'\n';
            if (get1(now_root1,1,1e9,a,a)!=0)
            {
                int nn=++last_root2;
                pluss2(now_root2,nn,1,1e9,get1(now_root1,1,1e9,a,a),-1);
                now_root2=nn;
            }

            int nn=++last_root2;
            pluss2(now_root2,nn,1,1e9,x,1);
            now_root2=nn;

            nn=++last_root1;
            change1(now_root1,nn,1,1e9,a,x);
            now_root1=nn;
        } else
        if (todo=="remove")
        {
            string s;
            cin>>s;
            if (!name.count(s))
                name[s]=++last;
            int a=name[s];
            if (get1(now_root1,1,1e9,a,a)!=0)
            {
                int nn=++last_root2;
                pluss2(now_root2,nn,1,1e9,get1(now_root1,1,1e9,a,a),-1);
                now_root2=nn;

                nn=++last_root1;
                change1(now_root1,nn,1,1e9,a,0);
                now_root1=nn;
            }


        } else
        if (todo=="query")
        {
            string s;
            cin>>s;
            if (!name.count(s))
                name[s]=++last;
            int a=name[s];
            //cout<<a<<'@'<<get1(now_root1,1,1e9,a,a)<<'\n';
            if (get1(now_root1,1,1e9,a,a)==0)
            {
                cout<<-1<<'\n';
            } else
            {
                cout<<get2(now_root2,1,1e9,1,get1(now_root1,1,1e9,a,a)-1)<<'\n';
            }
        } else
        if (todo=="undo")
        {
            int d;
            cin>>d;
            now_root1=root1[i-d-1];
            now_root2=root2[i-d-1];
        }

        root1[i]=now_root1;
        root2[i]=now_root2;
        //cout<<"!!!"<<get1(now_root1,1,1e9,2,2)<<'\n';
    }
}
/*
2
set physicsexercise 2
query physicsexercise
*/