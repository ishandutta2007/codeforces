//CF 920G
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
int main()
{
	int T,x,p,k;
	int n,m,pr[11],i,j,l,r,s,o,c,f;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&x,&p,&k);
		n=0;
		o=p;
		for(i=2;i*i<=o;i=i+1){
			if(o%i==0)
				pr[n++]=i;
			while(o%i==0){
				o/=i;
			}
		}
		if(o>1)
			pr[n++]=o;
		m=1<<n;
		l=x+1,r=1e9;
		while(l<r){
			o=l+r>>1;
			s=0;
			for(i=0;i<m;i=i+1){
				c=1,f=1;
				for(j=0;j<n;j=j+1)
					if(i&(1<<j))
						c*=pr[j],f=-f;
				s+=(o/c-x/c)*f;
			}
			if(s<k)
				l=o+1;
			else
				r=o;
		}
		printf("%d\n",l);
	}
	return 0;
}