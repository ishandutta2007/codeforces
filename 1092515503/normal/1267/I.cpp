#include<bits/stdc++.h>
using namespace std;
int T,n,a[210],b[210],A,B,cnt;
bool cmp(int x,int y){
	printf("? %d %d\n",x,y),fflush(stdout);
	static char s[10];scanf("%s",s);
	return s[0]=='<';
}
void insA(int x){
	for(int i=1;i<=A;i++)if(cmp(a[i],x)){
		for(int j=A+1;j>i;j--)a[j]=a[j-1];a[i]=x;
		A++;return;
	}
	a[++A]=x;
}
void insB(int x){
	for(int i=1;i<=B;i++)if(cmp(b[i],x)){
		for(int j=B+1;j>i;j--)b[j]=b[j-1];b[i]=x;
		B++;return;
	}
	b[++B]=x;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),A=B=cnt=0;
		while(A<(n+1)/2)insA(++cnt);
		while(A+B<n+1)insB(++cnt);
		while(true){
			if(cmp(a[A],b[B])){
				A--;
				if(cnt<2*n)insA(++cnt);
				else break;
			}else{
				B--;
				if(cnt<2*n)insB(++cnt);
				else break;
			}
		}
		puts("!"),fflush(stdout);
	}
	return 0;
}