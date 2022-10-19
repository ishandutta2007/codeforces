#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define long long long

#define M 100100
long n,w[M],m,a[M];

void read(void){
	cin>>n>>m;
	for (long i=0,x; i<m; ++i)
		cin>>x>>w[i];
}

void pre(void){
	for (long i=1; i<M; i+=2)
		a[i]=i*(i-1)/2+1;
	for (long i=2; i<M; i+=2)
		a[i]=i*(i-1)/2+(i/2);
}

void kill(void){
	sort(w,w+m);
	long x=1;
	for (long i=1; i<=m; ++i)
		if (a[i]<=n)
			x=i;
	long ans=0;
	for (long i=m-1; i>=m-x; --i)
		ans+=w[i];
	cout<<ans<<"\n";
}

int main(){
#ifdef TROLL
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#else
	ios_base::sync_with_stdio(0);
#endif

	read();
	pre();
	kill();

	return 0;
}