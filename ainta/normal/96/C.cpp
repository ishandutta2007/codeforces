#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct A{
	char p[200];
	bool operator()(A q,A r){
		if(strcmp(q.p,r.p)<0) return 1;
		return 0;}
}w[200];
char s[200],c[2],pp[200];
int v[200];
int n,m,i,j,k,a;
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",w[i].p);}
	scanf("%s",s);
	scanf("%s",c);
	m=strlen(s);
	for(i=0;i<m;i++) pp[i]=s[i];
	stable_sort(w,w+n,A());
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			a=strlen(w[i].p);
			for(k=0;k<a;k++){
				if(w[i].p[k]!=s[k+j]&&w[i].p[k]!=s[k+j]+'A'-'a'&&w[i].p[k]!=s[k+j]+'a'-'A') break;}
			if(k==a){
				for(k=0;k<a;k++){
					if(s[k+j]==c[0]||s[k+j]==c[0]+'A'-'a'||s[k+j]==c[0]+'a'-'A'){
						if(c[0]=='a'||c[0]=='A'){
							if(s[k+j]>'Z') pp[k+j]='b';
							else pp[k+j]='B';}
						else{
							if(s[k+j]>'Z') pp[k+j]='a';
							else pp[k+j]='A';
						}
						continue;
					}
					if(s[k+j]>'Z'&&c[0]<'a') pp[k+j]=c[0]-'A'+'a';
					else if(s[k+j]<'a'&&c[0]>'Z') pp[k+j]=c[0]-'a'+'A';
					else pp[k+j]=c[0];
				}
			}
		}
	}
	printf("%s\n",pp);
}