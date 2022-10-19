#include <iostream>
#include <cstdlib>

using namespace std;

#define M 5013
#define long long long
#define INF 1000000000ll

long n,k,a[M],l[M],r[M],t[M],m[M],c[M];

void read(void){
	cin>>n>>k;
	for (int i=0; i<k; ++i)
		cin>>t[i]>>l[i]>>r[i]>>m[i];
}


void kill(void){
	for (int i=1; i<=n; ++i)
		a[i]=INF;
	for (int i=k-1; i>=0; --i){
		if (t[i]==1)
			for (int j=l[i]; j<=r[i]; ++j)
				a[j]-=m[i];
		else
			for (int j=l[i]; j<=r[i]; ++j)
				a[j]=min(a[j],m[i]);

		for (int j=1; j<=n; ++j)
			if (a[j]>=INF)
				a[j]=INF;
	}
	

	for (int i=1; i<=n; ++i)
		c[i]=a[i];

	for (int i=0; i<k; ++i)
		if (t[i]==1)
			for (int j=l[i]; j<=r[i]; ++j)
				a[j]+=m[i];
		else{
			long ans=-INF;
			for (int j=l[i]; j<=r[i]; ++j)
				ans=max(a[j],ans);
			if (ans!=m[i]){
				cout<<"NO\n";
				return;
			}
		}
		

	cout<<"YES\n";
	for (int i=1; i<=n; ++i,cout<<" ")
		cout<<c[i];
	cout<<"\n";
}

int main(){
#ifdef BANANA
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif
	read();
	kill();
	return 0;
}