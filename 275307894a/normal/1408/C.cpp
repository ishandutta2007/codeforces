#include<cstdio>
using namespace std;
int n,m,k,t,x,y,z,l,r,v1,v2;
double s1,s2,a[100039],ans;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%lf",&a[i]);
		v1=1;v2=1;l=0;r=n+1;s1=0;s2=m;ans=0;
		while(l+1<r){
			if((a[l+1]-s1)/v1<(s2-a[r-1])/v2){
				s2-=(a[l+1]-s1)/v1*v2;
				ans+=(a[l+1]-s1)/v1;
				s1=a[l+1];
				v1++;
				l++;
			}
			else if((a[l+1]-s1)/v1==(s2-a[r-1])/v2){
				ans+=(a[l+1]-s1)/v1;
				s1=a[l+1];s2=a[r-1];
				l++;r--;
				v1++;v2++;
			}
			else{
				s1+=(s2-a[r-1])/v2*v1;
				ans+=(s2-a[r-1])/v2;
				s2=a[r-1];
				r--;v2++;
			}
		}		
		if(l==r) printf("%.15lf\n",ans);
		else printf("%.15lf\n",ans+(s2-s1)/(v1+v2));
	}
}