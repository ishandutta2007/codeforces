#include<bits/stdc++.h>
using namespace std;
int A,B,S,P,Z[15011],mx1,mx2,mn=0x3f3f3f3f,idx;
char a[5011],b[5011],s[15010];
bool ok;
void Zalgo(char *p){
	int l=0,r=0;
	P=strlen(p),S=P+A+B+2,memcpy(s,p,P),s[P]='$',memcpy(s+P+1,a,A),s[P+A+1]='#',memcpy(s+P+A+2,b,B);
//	for(int i=0;i<S;i++)putchar(s[i]);puts("");
	for(int i=1;i<S;i++){
		Z[i]=0;
		if(i<=r)Z[i]=min(Z[i-l],r-i);
		while(i+Z[i]<S&&s[Z[i]]==s[Z[i]+i])Z[i]++;
		if(i+Z[i]>r)l=i,r=i+Z[i];
	}
//	for(int i=0;i<S;i++)printf("%d\n",Z[i]);
}
int main(){
	scanf("%s%s",a,b),A=strlen(a),B=strlen(b);
	for(int i=0;i<A;i++){
		Zalgo(a+i),Z[A+1]=mx1=mx2=ok=0,idx=-1;
		for(int j=1;j<S;j++){
			if(Z[j]>mx1)mx2=mx1,ok=true,mx1=Z[j],idx=j;
			else if(Z[j]==mx1)ok=false;
			else mx2=max(mx2,Z[j]);
		}
		if(ok&&idx>A+P+1)mn=min(mn,mx2+1);
	}
	printf("%d\n",mn==0x3f3f3f3f?-1:mn);
	return 0;
}