#include<bits/stdc++.h>
#define N 500100
using namespace std;
int a[N],b[N],br[N];
int main(){
	long long s=0;
	int n,k,m=0,tk,l,r,av;
	scanf("%d%d",&n,&k);
	tk=k;
	for(int i=0;i<n;i++) scanf("%d",&a[i]),s+=a[i];
	sort(a,a+n);
	av=s/n;
	l=av,r=av+(s%n>0);
	for(int i=0;i<n;i++){
		if(!m||a[i]!=a[m-1]){
			a[m]=a[i];
			b[m]=1;
			m++;
		}
		else b[m-1]++;
	}
	for(int i=0;i<m;i++) br[i]=b[i];
	for(int i=0;i<m&&a[i]<l;i++){
		int to = min(a[i+1],l)-a[i];
		if(1LL*b[i]*to>k){
			l = a[i]+k/b[i];
			break;
		}
		else k-=1LL*b[i]*to,b[i+1]+=b[i];
	}
	k=tk;
	for(int i=m-1;i>=0&&a[i]>r;i--){
		int to = a[i]-max(a[i-1],r);
		if(1LL*br[i]*to>k){
			r = a[i]-k/br[i];
			break;
		}
		else k-=1LL*br[i]*to,br[i-1]+=br[i];
	}
	printf("%d\n",r-l);
	return 0;
}