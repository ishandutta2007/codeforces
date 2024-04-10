#include<stdio.h>
char p[1010];
int n,i,c[26],m,B,E,M,C,R;
int main(){
	scanf("%s",p);
	for(i=0;p[i];i++)c[p[i]-'a']++;
	m=i;
	scanf("%d",&n);
	if(m<n){
		printf("1\n");
		printf("%s",p);
		for(i=0;i<n-m;i++)printf("%c",p[0]);
		return 0;
	}
	B=m/n,E=m;
	R=-1;
	while(B<=E){
		M=(B+E+1)/2;
		C=0;
		for(i=0;i<26;i++){
			if(c[i]){
				C+=(c[i]-1)/M+1;
			}
		}
		if(C<=n){
			R=M;
			E=M-1;
		}
		else
			B=M+1;
	}
	printf("%d\n",R);
	if(R<0)return 0;
	B=n;
	for(i=0;i<26;i++){
		if(!c[i])continue;
		C=(c[i]-1)/R+1;
		B-=C;
		while(C--)printf("%c",'a'+i);
	}
	while(B--)printf("a");
	return 0;
}