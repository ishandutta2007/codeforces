#include <iostream>
#include <algorithm>

#define M 1000100
#define N 31

using namespace std;

int n,m,a[M],b[N],ans=0;

void read(void){
	cin>>n>>m;
	for (int i=0; i<n; ++i)
	cin>>a[i];
	for (int i=0,x; i<m; ++i){
		cin>>x;
		b[x]++;
	}
}

void solve(int t){
	for (int i=0; i<n; ++i)
	if (t && (a[i]&1)==1){
		a[i]--;
		t--;
		ans++;
	}	
	
	for (int j=n-1; t>0 && j>=0; --j){
		int r=min(t,a[j]);
		t-=r;
		ans+=r;
		a[j]-=r;
		if (a[j]==0)
		n=j;
	}
	
	
	for (int i=0; i<n; ++i)
	a[i]>>=1;
}

void kill(void){
	sort(a,a+n);
	reverse(a,a+n);
	
	for (int i=0; i<N; ++i)
	solve(b[i]);
	
	cout<<ans<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
	kill();
	return 0;
}