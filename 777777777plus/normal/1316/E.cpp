#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n,p,k;
int cnt[1<<7];
ll f[N][1<<7];

struct nd{
	int a;
	int s[7];
	friend bool operator < (nd a,nd b){
		return a.a>b.a;
	}
}a[N];

int main(){
	cin>>n>>p>>k;
	for(int i=1;i<=n;++i)cin>>a[i].a;
	for(int i=1;i<=n;++i)
	for(int j=0;j<p;++j){
		cin>>a[i].s[j];
	}
	sort(a+1,a+n+1);
	for(int i=0;i<=n;++i)
	for(int j=0;j<(1<<p);++j)
	f[i][j]=-1e18;
	f[0][0]=0;
	for(int i=1;i<(1<<p);++i)cnt[i]=cnt[i/2]+(i&1);
	for(int i=0;i<n;++i)
	for(int S=0;S<(1<<p);++S)
	if(f[i][S]>=0){
		if(i+1<=cnt[S]+k)f[i+1][S]=max(f[i+1][S],f[i][S]+a[i+1].a);
		else f[i+1][S]=max(f[i+1][S],f[i][S]);
		for(int j=0;j<p;++j)
		if(!(S&1<<j)){
			f[i+1][S|1<<j]=max(f[i+1][S|1<<j],f[i][S]+a[i+1].s[j]);
		}
	}
	cout<<f[n][(1<<p)-1]<<endl;
}