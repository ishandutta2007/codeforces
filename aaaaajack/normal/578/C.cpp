#include<cstdio>
#define N 200100
using namespace std;
int a[N],s[N],v1[N],v2[N],sz1,sz2;
int main(){
	double mx=1e20,ans;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	for(int i=0;i<=n;i++){
		while(sz1>=2&&1LL*(s[v1[sz1-1]]-s[v1[sz1-2]])*(i-v1[sz1-2])>=1LL*(s[i]-s[v1[sz1-2]])*(v1[sz1-1]-v1[sz1-2])) sz1--;
		v1[sz1++]=i;
	}
	for(int i=n;i>=0;i--){
		while(sz2>=2&&1LL*(s[v2[sz2-1]]-s[v2[sz2-2]])*(i-v2[sz2-2])>=1LL*(s[i]-s[v2[sz2-2]])*(v2[sz2-1]-v2[sz2-2])) sz2--;
		v2[sz2++]=i;
	}
	for(int i=0,j=0;i<sz1-1||j<sz2-1;){
		double nx1=i<sz1-1?1.0*(s[v1[i+1]]-s[v1[i]])/(v1[i+1]-v1[i]):0;
		double nx2=j<sz2-1?1.0*(s[v2[j+1]]-s[v2[j]])/(v2[j+1]-v2[j]):0;
		double nx;
		if(i<sz1-1&&j<sz2-1&&nx1<nx2||j==sz2-1){
			i++;
			nx=nx1;
		}
		else{
			j++;
			nx=nx2;
		}
		double ny1=s[v1[i]]-nx*v1[i];
		double ny2=s[v2[j]]-nx*v2[j];
		if(ny2-ny1<mx){
			mx=ny2-ny1;
			ans=nx;
		}
	}
	printf("%.8f\n",mx);
	return 0;
}