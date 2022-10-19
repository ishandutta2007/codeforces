#include <iostream>
#include <string>

using namespace std;

#define M 4040
#define N 40400
#define long long long

string s;
long n,a[N],b[M],x;

int main(){
#ifdef HOMEMOD
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#else
	ios_base::sync_with_stdio(0);
#endif

	cin>>x>>s;
	n=s.length();

	for (int i=1; i<=n; ++i){
		b[i]=b[i-1]+s[i-1]-'0';
		//cout<<b[i]<<" ";
	}
	//cout<<"\n";

	for (int i=0; i<=n; ++i)
		for (int j=i+1; j<=n; ++j)
			a[b[j]-b[i]]++;

	long ans=0;
	long m=n*(n+1)/2;

	if (x==0){
		ans=a[0]*m+a[0]*m-a[0]*a[0];
	}
	else
		for (int i=1; i<N; ++i)
			if (x%i==0 && x/i<N)
				ans=ans+a[i]*a[x/i];

	cout<<ans<<"\n";

	return 0;
}