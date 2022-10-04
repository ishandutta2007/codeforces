#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN=5000005;

ll p,k;
ll q[MAXN],f[MAXN];

ll lbnd(ll x,ll y)
{
	if(x>=0)return x/y;
	x=-x;
	if(x%y)return -(x/y+1);
	return -(x/y);
}

int main()
{
	#ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>p>>k;
    q[0]=-lbnd(p,k);
    f[0]=q[0]*k+p;
    int n=-1;
    for(int i=1;i<=5000000;i++)
    {
    	q[i]=-lbnd(q[i-1],k);
    	f[i]=q[i]*k+q[i-1];
    	if(!q[i])
		{
			f[i+1]=q[i];
			n=i+1;
			break;
		}
    }
    while(!f[n-1])n--;
    if(n<0)printf("-1\n");
    else
	{
		printf("%d\n",n);
		for(int i=0;i<n;i++)
    		cout<<f[i]<<" ";
    }
    return 0;
}