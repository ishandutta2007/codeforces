#include<cstdio>
using namespace std;
int t,n,a[39],flag,now,s,ans;
int main(){
	register int i,j,k;
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++){
			flag=0;
			for(j=1;j<=n;j++) if(j!=i&&a[i]==a[j]){flag=1;break;}
			if(flag){
				ans++;
				for(j=0;j<=9;j++){
					if(j!=a[i]%10){
						flag=0;
						for(k=1;k<=n;k++){
							if(k!=i&&a[i]/10*10+j==a[k]){flag=1;break;}
						}
						if(!flag){a[i]=a[i]/10*10+j;break;}
					}
				}
			}
		}
		printf("%d\n",ans);
		for(i=1;i<=n;i++){
			if(a[i]<1000&&a[i]>=100) printf("0%d\n",a[i]);
			else if(a[i]<100&&a[i]>=10) printf("00%d\n",a[i]);
			else if(a[i]<10) printf("000%d\n",a[i]);
			else printf("%d\n",a[i]);
		}
	}
	
	return 0;
}