#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,w[100039],now1,now2,now3,now4,a[100039],now,flag[100039],flags,ans,tot;
int main(){
	srand((unsigned int) time(0));
	register int i,j;
	scanf("%d",&n);
	for(i=2;i<=n;i++) printf("XOR %d %d\n",1,i),fflush(stdout),scanf("%d",&w[i]);
	for(i=2;i<=n;i++){
		if(!w[i]){ans=1;tot=i;flags=1;break;}
		else if(flag[w[i]]){ans=flag[w[i]],tot=i;flags=1;break;}
		flag[w[i]]=i;
	}
	if(flags){
		printf("AND %d %d\n",ans,tot);
		fflush(stdout);
		scanf("%d",&now1);
		a[1]=now1^w[ans];
		for(i=2;i<=n;i++)a[i]=w[i]^a[1];
	}
	else{
		for(i=2;i<=n;i++){
			if(w[i]==1){
				printf("AND 1 %d\n",i);
				fflush(stdout);
				scanf("%d",&now1);
				a[1]^=now1;
			}
			if(w[i]==n-2){
				printf("AND  1 %d\n",i);
				fflush(stdout);
				scanf("%d",&now1);
				a[1]^=now1;
			}
		}
		for(i=2;i<=n;i++)a[i]=w[i]^a[1];
	}
	printf("! ");
	for(i=1;i<=n;i++) printf("%d ",a[i]);
}