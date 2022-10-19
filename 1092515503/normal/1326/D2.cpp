#include<bits/stdc++.h>
using namespace std;
int S,T,P,Z[2001000],L,R,l,r;
char s[1001000],p[2001000];
void Zalgo(){
	L=R=0;
	for(int i=1;i<P;i++){
		Z[i]=0;
		if(i<=R)Z[i]=min(Z[i-L],R-i);
		while(Z[i]+i<P&&p[Z[i]]==p[Z[i]+i])Z[i]++;
		if(Z[i]+i>R)L=i,R=Z[i]+i;
	}
}
void work(){
	P=0;
	for(int i=l;i<S-r;i++)p[P++]=s[i];
	p[P++]='$';
	for(int i=S-r-1;i>=l;i--)p[P++]=s[i];
	p[P]='\0';
//	printf("%s\n",p);
	Zalgo();
	int u=0,v=0;
	for(int i=1;i<P;i++)if(i+Z[i]==P){u=P-i;break;}
	reverse(p,p+(S-r-l)),reverse(p+P-(S-r-l),p+P);
//	printf("%s\n",p);
	Zalgo();
	for(int i=1;i<P;i++)if(i+Z[i]==P){v=P-i;break;}
	if(u>=v)l+=u;
	else r+=v;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s),S=strlen(s);
		l=r=0;
		while(l+r<S-1&&s[l]==s[S-r-1])l++,r++;
		work();
//		printf("%d %d\n",l,r);
		for(int i=0;i<l;i++)putchar(s[i]);
		for(int i=S-r;i<S;i++)putchar(s[i]);
		putchar('\n');
	}
	return 0;
}