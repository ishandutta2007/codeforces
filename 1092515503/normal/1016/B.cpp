#include<bits/stdc++.h>
using namespace std;
int S,T,q,kmp[1010];
char s[1010],t[1010];
void getkmp(){
	int j=-1;
	kmp[0]=-1;
	for(int i=1;i<S;i++){
		while(j!=-1&&s[j+1]!=s[i])j=kmp[j];
		if(s[j+1]==s[i])j++;
		kmp[i]=j;
	}
}
int match(int l,int r){
	int res=0,j=-1;
	for(int i=l;i<=r;i++){
		while(j!=-1&&s[j+1]!=t[i])j=kmp[j];
		if(s[j+1]==t[i])j++;
		if(j==S-1)res++,j=kmp[j];
	}
	return res;
}
int main(){
	scanf("%d%d%d",&T,&S,&q);
	scanf("%s%s",t,s);
	getkmp();
	for(int i=1,l,r;i<=q;i++){
		scanf("%d%d",&l,&r),l--,r--;
		printf("%d\n",match(l,r));
	}
	return 0;
}