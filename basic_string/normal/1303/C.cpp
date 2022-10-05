#include<bits/stdc++.h>
using namespace std;
char s[209];
int a[209],u[29],v[29],f[29];
bool b[29][29];
int getf(int x){
	return f[x]==x?x:f[x]=getf(f[x]);
}
int main(){
	int T,l,i,j,k;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s),l=strlen(s);
		memset(b,0,sizeof(b));
		memset(u,0,sizeof(u)),memset(v,0,sizeof(v));
		for(i=0;i<l;++i)a[i]=s[i]-'a'+1;
		for(i=1;i<=26;++i)f[i]=i;
		for(i=1;i<l;++i){
			if(b[a[i]][a[i-1]])continue;
			b[a[i]][a[i-1]]=b[a[i-1]][a[i]]=1;
			if(getf(a[i])==getf(a[i-1])){puts("NO");goto ggg;}
			if(!u[a[i]]&&!v[a[i-1]])u[a[i]]=a[i-1],v[a[i-1]]=a[i];
			else if(!v[a[i]]&&!u[a[i-1]])v[a[i]]=a[i-1],u[a[i-1]]=a[i];
			else{
				for(j=0;j<26;++j)if(getf(j)==getf(a[i]))swap(u[j],v[j]);
				if(!u[a[i]]&&!v[a[i-1]])u[a[i]]=a[i-1],v[a[i-1]]=a[i];
			else if(!v[a[i]]&&!u[a[i-1]])v[a[i]]=a[i-1],u[a[i-1]]=a[i];
			else{puts("NO"); goto ggg;}
			}
			f[getf(a[i])]=getf(a[i-1]);
		}
		puts("YES");
		for(i=1;i<=26;++i){
			if(!u[i]&&!v[i])putchar('a'+i-1);
		}
		for(i=1;i<=26;++i){
			if(!u[i]&&v[i]){
				j=i;
				while(v[j]){
					putchar('a'+j-1);
					j=v[j];
				}
				putchar('a'+j-1);
				break;
			}
		}
		putchar(10);
		ggg:;
	}
	return 0;
}//