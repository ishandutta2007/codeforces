#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,a[100039],s[100039],pus,now,f[100039];
long long ans,tot;
int main(){
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++){
	    tot=a[i];
		pus=a[i];
		for(j=i-1;j>=1;j--){
		    if(a[j]>=pus) tot+=pus;
		    else {
			    tot+=a[j];
			    pus=a[j];
	     	}
	    }
	    pus=a[i];
	    for(j=i+1;j<=n;j++){
		    if(a[j]>=pus) tot+=pus;
		    else {
			    tot+=a[j];
			    pus=a[j];
		    }
	    }
	    ans=max(ans,tot);
	}
	for(i=1;i<=n;i++){
	    tot=a[i];
		pus=a[i];
		f[i]=a[i];
		for(j=i-1;j>=1;j--){
		    if(a[j]>=pus) tot+=pus,f[j]=pus;
		    else {
		    	f[j]=a[j];
			    tot+=a[j];
			    pus=a[j];
	     	}
	    }
	    pus=a[i];
	    for(j=i+1;j<=n;j++){
		    if(a[j]>=pus) tot+=pus,f[j]=pus;
		    else {
		    	f[j]=a[j];
			    tot+=a[j];
			    pus=a[j];
		    }
	    }
	    if(ans==tot){
	    	for(i=1;i<=n;i++) printf("%d ",f[i]);
		    return 0;
	    }
	}
}