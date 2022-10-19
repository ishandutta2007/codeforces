#include <iostream>
#include <cstdlib>

using namespace std;

#define M 2013
#define long long long

long n,k,a[M],d[M];

void read(void){
	cin>>n>>k;
	for (int i=0; i<n; ++i)
		cin>>a[i];
}

long abss(long x){
	return x<0 ? -x:x;
}

int din(long m){
	d[0]=0;
	for (long i=1; i<n; ++i){
		d[i]=i;
		for (int j=0; j<i; ++j)
			if (abss(a[i]-a[j])<=(i-j)*m)
				d[i]=min(d[i],d[j]+i-j-1);
	}
	long ans=n;
	for (int i=0; i<n; ++i)
		ans=min(ans,d[i]+n-i-1);
	return ans;
}

void bin(void){
	long l=0,r=20000000000ll,m;
	while (l<r){
		m=(l+r)/2;
		if (din(m)<=k)
			r=m;
		else
			l=m+1;
	}
	cout<<l<<"\n";
}

int main(){
#ifdef BANANA
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif
	read();
	bin();
	return 0;
}