#include<stdio.h>
struct A{
	bool v;
	int l,r,C;
}w[101];
bool v[101],chk;
int n,i,h1,h2,t,j,k,S,M;
char p[3];
double h,H,K=100000.0,l;
int main()
{
	scanf("%d%d%d",&h1,&h2,&n);
	for(i=0;i<n;i++){
		scanf("%d",&w[i].C);
		scanf("%s",p);
		scanf("%d%d",&w[i].l,&w[i].r);
		if(p[0]=='T')w[i].v=true;
		else w[i].v=false;
	}
	h=h1-h2;
	for(i=1;i<=n;i++){
		if(i&1)h+=h2*2;
		else h+=(100-h2)*2;
		chk=0;
		H=h1;
		for(j=0;j<n;j++)v[j]=0;
		S=0;
		for(j=0;j<i;j++){
			l=K*H/h;
			if(j&1){
				for(k=0;k<n;k++){
					if(w[k].v&&w[k].l<=l&&l<=w[k].r){
						S+=w[k].C;
						if(v[k])chk=1;
						v[k]=true;
						break;
					}
				}
				if(k==n)chk=1;
			}
			else{
				for(k=0;k<n;k++){
					if(!w[k].v&&w[k].l<=l&&l<=w[k].r){
						S+=w[k].C;
						if(v[k])chk=1;
						v[k]=true;
						break;
					}
				}
				if(k==n)chk=1;
			}
			if(chk)break;
			H+=100;
		}
		if(!chk&&S>M)M=S;
	}
	h=h2-h1;
	for(i=1;i<=n;i++){
		if(i&1)h+=(100-h2)*2;
		else h+=h2*2;
		chk=0;
		H=100-h1;
		for(j=0;j<n;j++)v[j]=0;
		S=0;
		for(j=0;j<i;j++){
			l=K*H/h;
			if(!(j&1)){
				for(k=0;k<n;k++){
					if(w[k].v&&w[k].l<=l&&l<=w[k].r){
						S+=w[k].C;
						if(v[k])chk=1;
						v[k]=true;
						break;
					}
				}
				if(k==n)chk=1;
			}
			else{
				for(k=0;k<n;k++){
					if(!w[k].v&&w[k].l<=l&&l<=w[k].r){
						S+=w[k].C;
						if(v[k])chk=1;
						v[k]=true;
						break;
					}
				}
				if(k==n)chk=1;
			}
			if(chk)break;
			H+=100;
		}
		if(!chk&&S>M)M=S;
	}
	printf("%d\n",M);
}