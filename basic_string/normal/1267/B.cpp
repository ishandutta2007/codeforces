#include<bits/stdc++.h>
using namespace std;
char s[300009],c[300009];
int a[300009];
int main(){
	int n=0,l,i,j;
	scanf("%s",s),l=strlen(s);
	for(i=1,j=0;i<l;++i){
		if(s[i]!=s[j]){
			a[++n]=i-j,c[n]=s[j],j=i;
		}
	}
	a[++n]=i-j,c[n]=s[j];
	if(n&1){
		j=(n>>1)+1;
		if(a[j]<2)puts("0");
		else{
			for(i=j-1;i;--i){
				l=n-i+1;
				if(c[i]!=c[l]||a[i]+a[l]<3){
					puts("0");
					break;
				}
			}
			if(i==0)printf("%d",a[j]+1);
		}
	}else puts("0");
	return 0;
}