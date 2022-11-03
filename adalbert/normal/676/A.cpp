#include <bits/stdc++.h>
#define fin freopen("dijkstra.in","r",stdin)
#define fout freopen("dijkstra.out","w",stdout)
using namespace std;
int n,s,f,v[2200],a[2004][2400],t,mn,imn,p1,pn;
const int maxlongint = numeric_limits <int> :: max();
bool use[2200];
int main()
{
//	fin;
//	fout;

    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>t;
    	if (t==1) p1=i;
    	if (t==n) pn=i;
    //	cout<<t;
    };
    cout<<max(max(abs(1-p1),abs(1-pn)),max(abs(n-p1),abs(n-pn)));

     return(0);

}