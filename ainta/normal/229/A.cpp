#include<stdio.h>
char p[10010];
int n,m,w[101][10010],t,chk,o,S,R,j,i;
int main(){
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",p);
		chk=t=0;
		for(j=0;j<m;j++){
			if(p[j]=='1'){
				t=0;
				if(chk==0)chk=1,o=j;}
			if(!chk){w[i][j]=m+1;continue;}
			w[i][j]=t;
			t++;}
		for(j=0;j<o;j++)w[i][j]=t++;
		if(!chk)break;
		chk=t=0;
		for(j=m-1;j>=0;j--){
			if(p[j]=='1'){
				t=0;
				if(chk==0)chk=1,o=j;}
			if(!chk)continue;
			if(w[i][j]>t)w[i][j]=t;
			t++;}
		for(j=m-1;j>=o;j--){if(w[i][j]>t)w[i][j]=t++;}
	}
	if(i<n){printf("-1\n");return 0;}
	R=m*n;
	for(i=0;i<m;i++){S=0;for(j=0;j<n;j++)S+=w[j][i];if(R>S)R=S;}
	printf("%d\n",R);
}