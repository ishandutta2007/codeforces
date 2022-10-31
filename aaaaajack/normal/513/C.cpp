#include<cstdio>
#include<algorithm>
using namespace std;
inline double prob(double a){
	if(a<0) return 0;
	if(a>1) return 1;
	return a;
}
inline double mul(double *t,int n){
	double r=1;
	for(int i=0;i<n;i++) r*=t[i];
	return r;
}
int main(){
	int i,j,k,l[10],r[10],n;
	double ans=0,p=0,t[10],a;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&l[i],&r[i]);
	}
	for(i=1;i<=10000;i++){
		p=0;
		for(j=0;j<n;j++){
			t[j]=prob(1.0*(r[j]-i)/(r[j]-l[j]+1));
			for(k=0;k<n;k++){
				if(k==j) continue;
				else{
					t[k]=prob(1.0*(i-l[k]+1)/(r[k]-l[k]+1));
				}
			}
			p+=mul(t,n);
			for(k=0;k<n;k++){
				if(k==j) continue;
				else t[k]=prob(1.0*(i-l[k])/(r[k]-l[k]+1));
			}
			p-=mul(t,n);
		}
		for(j=0;j<n;j++){
			t[j]=prob(1.0*(i-l[j]+1)/(r[j]-l[j]+1));
		}
		p+=mul(t,n);
		for(j=0;j<n;j++){
			t[j]=prob(1.0*(i-l[j])/(r[j]-l[j]+1));
		}
		p-=mul(t,n);
		for(j=0;j<n;j++){
			if(i>=l[j]&&i<=r[j]){
				t[j]=1.0/(r[j]-l[j]+1);
				p-=mul(t,n);
				t[j]=prob(1.0*(i-l[j])/(r[j]-l[j]+1));
			}
		}
		ans+=p*i;
	}
	printf("%.12f\n",ans);
	return 0;
}