#include<cstdio>
#include<cstring>
using namespace std;
int c[139],n,m,f[200039],a[200039],un,wn,ans;
char s[1039];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main(){
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) f[i]=i;
	for(i=1;i<=n;i++){
		scanf("%s",&s);
		m=strlen(s);
		for(j=0;j<m;j++){
			if(c[s[j]]!=i&&c[s[j]])un=find(i),wn=find(c[s[j]]),f[un]=wn;
			c[s[j]]=i;
		}
	}
	for(i=1;i<=n;i++) if(find(i)==i) ans++;
	printf("%d\n",ans);
}