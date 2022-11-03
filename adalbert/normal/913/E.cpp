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
typedef unsigned long long ll;
typedef long double ld;
const int arr=5e5+100;
const int md=1e9+7;
const int base=1e9+7;
///magic
/*
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/
///


int len[500][10];
string st[500][10],sto[500],sta[500];

set<pair<int,pair<int,int> > > setik;

string getmin(string st1,string st2)
{
    if (st1.size()==st2.size())
        return(min(st1,st2));
    if (st1.size()>st2.size())
        return(st2);
    return(st1);
}

void update(string s, int i, int j)
{
    if (len[i][j]>s.size())
    {
        len[i][j]=s.size();
        st[i][j]=s;
        setik.insert({len[i][j],{i,j}});
    } else
    {
        if (getmin(st[i][j],s)!=st[i][j])
        {
            st[i][j]=getmin(st[i][j],s);
            setik.insert({len[i][j],{i,j}});
        }

    }

}

signed main()
{
    for (int i=0;i<256;i++)
        for (int j=0;j<=5;j++)
        len[i][j]=1e9;
    len[240][0]=1;
    st[240][0]="x";
    len[204][0]=1;
    st[204][0]="y";
    len[170][0]=1;
    st[170][0]="z";



    setik.insert({1,{204,0}});
    setik.insert({1,{240,0}});
    setik.insert({1,{170,0}});

    while (!setik.empty())
    {
        pair<int,pair<int,int> > now=*setik.begin();
        setik.erase(now);

        pair<int,int> u=now.sec;

        if (u.sec!=0)
        {
            string now=st[u.fir][u.sec];
            now+=')';
            reverse(now.begin(),now.end());
            now+='(';
            reverse(now.begin(),now.end());

            update(now,u.fir,0);
        }

        if (u.sec==0)
        {
            string now=st[u.fir][u.sec];
            reverse(now.begin(),now.end());
            now+='!';
            reverse(now.begin(),now.end());
            update(now,255-u.fir,0);
        }

        if (u.sec<=1)
        {
            for (int i=0;i<256;i++)
                if (len[i][0]!=1e9)
                {
                    string now="";
                    now=st[u.fir][u.sec];
                    now+='&';
                    now+=st[i][0];
                    update(now,(u.fir&i),1);
                }
        }

        if (u.sec==0)
        {
            for (int i=0;i<256;i++)
                if (len[i][0]!=1e9)
                {
                    string now="";
                    now+=st[i][0];
                    now+='&';
                    now+=st[u.fir][u.sec];
                    update(now,(u.fir&i),1);
                }
            for (int i=0;i<256;i++)
                if (len[i][1]!=1e9)
                {
                    string now="";
                    now+=st[i][1];
                    now+='&';
                    now+=st[u.fir][u.sec];
                    update(now,(u.fir&i),1);
                }
        }

        if (u.sec<=2)
        {
            for (int i=0;i<256;i++)
                for (int j=0;j<=1;j++)
                if (len[i][j]!=1e9)
                {
                    string now="";
                    now+=st[u.fir][u.sec];
                    now+='|';
                    now+=st[i][j];
                    update(now,(u.fir|i),2);
                }
        }

        if (u.sec<=1)
        {
            for (int i=0;i<256;i++)
                for (int j=0;j<=2;j++)
                if (len[i][j]!=1e9)
                {
                    string now="";
                    now+=st[i][j];
                    now+='|';
                    now+=st[u.fir][u.sec];
                    update(now,(u.fir|i),2);
                }
        }
    }

    for (int i=0;i<256;i++)
        cerr<<i<<' '<<st[i][0]<<' '<<len[i][0]<<'\n';

    int n;
    cin>>n;
    while (n--)
    {
        string s;
        cin>>s;
        int res=0;
        for (int i=0;i<8;i++)
            if (s[i]=='1')
            res+=(1<<i);
        cout<<getmin(st[res][0],getmin(st[res][1],st[res][2]))<<'\n';
    }
}