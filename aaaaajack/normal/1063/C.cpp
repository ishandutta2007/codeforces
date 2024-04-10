#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x;
	bool flag=false;
	int l=0,r=1<<29,ry=0;
	char s[100],t[100],m[100];
	scanf("%d",&n);
	if(n==1){
		printf("0 0\n");
		fflush(stdout);
		scanf("%s",s);
		printf("1 1 1 0\n");
		return 0;
	}
	printf("%d %d\n",l,l);
	fflush(stdout);
	scanf("%s",s);
	n--;
	do{
		ry+=2;
		printf("%d %d\n",r,ry);
		fflush(stdout);
		scanf("%s",t);
		n--;
	}while(n>0&&s[0]==t[0]);
	if(t[0]==s[0]){
		printf("%d %d %d %d\n",0,ry+1,1,ry+1);
		fflush(stdout);
		return 0;
	}
	while(n>0){
		printf("%d %d\n",(l+r)/2,ry);
		fflush(stdout);
		scanf("%s",m);
		if(m[0]==s[0]) l=(l+r)/2;
		else r=(l+r)/2;
		n--;
	}
	assert(r-l>=2);
	printf("%d %d %d %d\n",1<<29,ry-1,(l+r)/2,ry);
	fflush(stdout);
	return 0;
}