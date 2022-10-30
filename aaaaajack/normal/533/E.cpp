#include<cstdio>
#define N 100100
char s[N],t[N];
int main(){
	int n,l,r,t1,t2,i;
	scanf("%d",&n);
	scanf("%s%s",s,t);
	l=0;
	r=n-1;
	while(s[l]==t[l]) l++;
	while(s[r]==t[r]) r--;
	for(i=l+1;i<=r;i++){
		if(s[i]!=t[i-1]) break;
	}
	t1=(i==r+1);
	for(i=l+1;i<=r;i++){
		if(s[i-1]!=t[i]) break;
	}
	t2=(i==r+1);
	printf("%d\n",t1+t2);
	return 0;
}