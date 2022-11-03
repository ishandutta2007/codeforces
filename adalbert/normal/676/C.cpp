#include <bits/stdc++.h>
#define fin freopen("dijkstra.in","r",stdin)
#define fout freopen("dijkstra.out","w",stdout)
using namespace std;
int k,l,n,s,f,b[2000000],a[2004][2400],t,mn,imn,p1,pn,mx,liv;
string st;
int main()
{
	cin>>n>>l;
	cin>>st;
	liv=0;
    for(int i=0;i<n;i++)
    {
         if (st[i]=='b') t++;
         if (t>l)
    {
            while (st[liv]!='b') liv++;
            t--;
            if (st[liv]='b') liv++;'\n';
    }

        //cout<<liv<<' '<<i<<' '<<t<<' '<<'\n';
    if (i-liv+1>mx) mx=i-liv+1;
    }
    liv=0;
    t=0;
    for(int i=0;i<n;i++)
    {
         if (st[i]=='a') t++;
         if (t>l)
    {
            while (st[liv]!='a') liv++;
            t--;
            if (st[liv]='a') liv++;'\n';
    }

        //cout<<liv<<' '<<i<<' '<<t<<' '<<'\n';
    if (i-liv+1>mx) mx=i-liv+1;
    }
    cout<<mx;
    return(0);

}