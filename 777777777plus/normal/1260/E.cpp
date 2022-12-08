#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
const ll inf = 1e18;

int n,a[N],b[N],spare[19];
int p;
ll f[N][19];

int main(){
	scanf("%d",&n);
	spare[1]=n/2;
	for(int i=2;i<=18;++i)spare[i]=spare[i-1]/2;
	for(int i=1;i<=18;++i)spare[i]+=spare[i-1];
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]==-1)p=i;
	}
	int c=0;
	for(int i=n;i>p;--i)b[++c]=a[i];
	n=c;
	for(int i=0;i<=n;++i)
	for(int j=0;j<=18;++j)
	f[i][j]=inf;
	f[0][0]=0;
	for(int i=0;i<n;++i)
	for(int j=0;j<=18;++j)
	if(f[i][j]!=inf){
		if(spare[j]>=i+1)f[i+1][j]=min(f[i+1][j],f[i][j]);
		if(j<18)f[i+1][j+1]=min(f[i+1][j+1],f[i][j]+b[i+1]);
	}
	cout<<*min_element(f[n],f[n]+19)<<endl;
}