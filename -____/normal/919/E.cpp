//CF 919E
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
const int N = 1e6+16;
int a,b,p;
int fpow(int x,int y){
	if(!y)
		return 1;
	LL z=fpow(x,y>>1);
	z=z*z%p;
	if(y&1)
		z=z*x%p;
	return z;
}
int pw[N];
int main()
{
	int i,j;
	LL x,pp,ans=0,k;
	cin>>a>>b>>p>>x;
	pp=(LL)p*(p-1);
	pw[0]=1;
	for(i=1;i<p-1;i=i+1)
		pw[i]=(LL)pw[i-1]*a%p;
	for(i=0;i<p-1;i=i+1){
		j=(LL)b*fpow(pw[i],p-2)%p;
		k=(LL)j*(p-1)*(p-1)%pp+(LL)i*p;
		k=k%pp;
		ans+=x/pp;
		if(k<=x%pp)
			ans++;
	}
	cout<<ans;
	return 0;
}