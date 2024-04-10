
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <complex>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".sol","r",stdin); freopen (name".dat","w",stdout);
#define time pdojegoritg

#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")

typedef long long ll;
typedef long double ld;
const int arr=4*1e5;
const int md=1e9+7;

string parse(int u)
{
    string res="";
    while (u!=0)
    {
        res+=u%10+'0';
        u/=10;
    }
    if (res.empty()) res+='0';
    reverse(res.begin(),res.end());
    return(res);
}

int get(int u, int i)
{
    return((u&(1<<i))!=0);
}

int sum(string st)
{
    int res=0;
    for (int i=0;i<st.size();i++)
        res+=st[i]-'0';
    return(res);
}

bool check(int go, string st)
{
    int now=0;
    for (int i=0;i<st.size();i+=go)
    {
        int tep=0;
        for (int j=i;j<min(i+go,int(st.size()));j++)
        {
            tep*=10;
            tep+=st[j]-'0';
        }
        now+=tep;
    }
    st=parse(now);

    int mx=(1<<int(st.size()-1));

    int mn=1e9;
    int imn=0;
    for (int i=0;i<mx;i++)
    {
        int res=0;
        int now=st[0]-'0';
        for (int j=1;j<st.size();j++)
            if (get(i,j-1))
            {
                res+=now;
                now=st[j]-'0';
            } else
            {
                now*=10;
                now+=st[j]-'0';
            }
        res+=now;
        string tep=parse(res);
        if (sum(tep)<mn)
        {
            mn=sum(tep);
            imn=i;
        }

    }
    return(mn<10);
}

signed main()
{
    int a;
    cin>>a;
    string st;
    cin>>st;



    int now=0;

    int go=1;
    while (!check(go,st)) go++;

    for (int i=0;i<st.size();i+=go)
    {
        if (i!=0)
            cout<<'+';
        int tep=0;
        for (int j=i;j<min(i+go,int(st.size()));j++)
        {
            cout<<st[j];
            tep*=10;
            tep+=st[j]-'0';
        }
        now+=tep;
    }
    st=parse(now);
    cout<<'\n';
    //cout<<st<<'\n';

    int mx=(1<<int(st.size()-1));

    int mn=1e9;
    int imn=0;
    for (int i=0;i<mx;i++)
    {
        int res=0;
        int now=st[0]-'0';
        for (int j=1;j<st.size();j++)
            if (get(i,j-1))
            {
                res+=now;
                now=st[j]-'0';
            } else
            {
                now*=10;
                now+=st[j]-'0';
            }
        res+=now;
        string tep=parse(res);
        if (sum(tep)<mn)
        {
            mn=sum(tep);
            imn=i;
        }

    }
    if (mn>=10) exit(1);
    cout<<st[0];
    int res=0;
    now=st[0]-'0';
    for (int i=1;i<st.size();i++)
    {
        if (get(imn,i-1))
        {
            res+=now;
            cout<<'+';
            now=0;
        }

        cout<<st[i];
        now*=10;
        now+=st[i]-'0';
    }
    cout<<'\n';
    res+=now;
    st=parse(res);
    now=0;
    cout<<st[0];
    now+=st[0]-'0';
    for (int j=1;j<st.size();j++)
    {
        cout<<'+'<<st[j];
        now+=st[j]-'0';
    }
    cout<<'\n';



}