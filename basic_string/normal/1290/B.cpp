#include<cstdio>
#include<cstring>
const int N=200009;
int f[N],s[N],t[N],n;
char a[N];
int ne[N],to[N],he[N];
int L[N],R[N];
inline void add(int x){
	for(;x<=n;x+=x&-x)++t[x];
}
inline void del(int x){
	for(;x<=n;x+=x&-x)--t[x];
}
inline int sum(int x){
	register int y=0;
	for(;x;x-=x&-x)y+=t[x];
	return y;
}
int main(){
	register int m,i,j,k;
	scanf("%s",a+1),n=strlen(a+1);
	scanf("%d",&m);
	for(i=1;i<=m;++i){
		scanf("%d%d",&j,&k);
		ne[i]=he[k],to[i]=j,he[k]=i;
		L[i]=j,R[i]=k;
	}
	for(i=1,k=0;i<=n;++i){
		if(!f[a[i]])++k;else del(f[a[i]]);
		add(i),f[a[i]]=i;
		for(j=he[i];j;j=ne[j])s[j]=k-sum(to[j]-1);
	}
	for(i=1;i<=m;++i){
		if(s[i]>2)puts("Yes");
		else if(s[i]==2){
			if(a[L[i]]==a[R[i]])puts("No");
			else puts("Yes");
		}else{
			if(L[i]==R[i])puts("Yes");
			else puts("No");
		}
	}
    return 0;
}//@#