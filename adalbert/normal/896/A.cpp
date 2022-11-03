#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int arr=3e5+100;
const int base=31;

string st1,st2,st3,st0;
int len[arr];

char getans(int x, int y)
{
    if (len[x]<y)
        return('.');
    if (x==0)
        return(st0[y-1]);

    if (y<=st1.size())
        return(st1[y-1]);
    y-=st1.size();
    if (y<=len[x-1])
        return(getans(x-1,y));
    y-=len[x-1];
    if (y<=st2.size())
        return(st2[y-1]);
    y-=st2.size();
    if (y<=len[x-1])
        return(getans(x-1,y));
    y-=len[x-1];

    return(st2[y-1]);
}

signed main()
{
    fast;
    st0="What are you doing at the end of the world? Are you busy? Will you save us?";
    st1="What are you doing while sending \"";
    st2="\"? Are you busy? Will you send \"";
    st3="\"?";

    len[0]=st0.size();
    for (int i=1;i<=1e5;i++)
    {
        len[i]=min(2*len[i-1],int(2e18))+int(st1.size()+st2.size()+st3.size());
        len[i]=min(len[i],int(2e18));
    }

    int q;
    cin>>q;
    while (q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<getans(x,y);
    }
}