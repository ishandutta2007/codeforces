#include<bits/stdc++.h>
using namespace std;
int zero,one,S,Z[500010],l,r,suf,bz,bo,pz,po,num;
char s[500010];
void gt(){
	char c=getchar();
	while(c!='0'&&c!='1')c=getchar();
	while(c=='0'||c=='1')c=='0'?zero++:one++,c=getchar();
}
int main(){
	gt(),scanf("%s",s),S=strlen(s);
	for(int i=0;i<S;i++)s[i]=='0'?bz++:bo++;
	for(int i=1;i<S;i++){
		if(i<=r)Z[i]=min(Z[i-l],r-i);
		while(Z[i]+i<S&&s[Z[i]]==s[Z[i]+i])Z[i]++;
		if(Z[i]+i>r)l=i,r=Z[i]+i;
	}
	for(int i=1;i<=S;i++)if(Z[i]+i==S){suf=i;break;}
	for(int i=S-suf;i<S;i++)s[i]=='0'?pz++:po++;
	if(bz>zero||bo>one){
		for(int i=1;i<=zero;i++)putchar('0');
		for(int i=1;i<=one;i++)putchar('1');
		return 0;
	}
	while(bz+pz<=zero&&bo+po<=one)bz+=pz,bo+=po,num++;
	printf("%s",s);
	for(int i=1;i<=num;i++)printf("%s",s+S-suf);
	for(;bz<zero;bz++)putchar('0');
	for(;bo<one;bo++)putchar('1');
	return 0;
}