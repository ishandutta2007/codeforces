#include<bits/stdc++.h>
using namespace std;
int n,a[100100],m,b[100100],lim,f[100100],pos[100100],g[100100],las[100100];
multiset<int>s;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]),s.insert(b[i]);
	sort(b+1,b+m+1);
	memset(f,0x3f,sizeof(f)),f[0]=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=-1){
			int p=lower_bound(f+1,f+n+1,a[i])-f;
			if(f[p]>a[i])f[p]=a[i],pos[p]=i;
			g[i]=p,las[i]=pos[p-1];
		}else{
			for(int j=m,k=i;j;j--){
				while(k&&f[k-1]>=b[j])k--;
				if(k&&f[k]>b[j])f[k]=b[j],pos[k]=i;
				g[i]=max(g[i],k);
			}
		}
	}
//	for(int i=1;i<=n;i++)printf("(%d:%d,%d)",i,a[i],g[i]);puts("");
	int i=n;
	while(f[i]==0x3f3f3f3f)i--;
	for(int j=pos[i],nex=0x3f3f3f3f;i;i--){
		if(a[j]!=-1)nex=a[j],j=las[j];
		else{
			s.erase(s.find(nex=a[j]=*(lower_bound(b+1,b+m+1,nex)-1)));
			bool fd=false;
			for(int k=j-1;k;k--)if(a[k]!=-1&&g[k]==i-1&&a[k]<a[j]){j=k,fd=true;break;}
			if(fd)continue;
			while(--j)if(a[j]==-1)break;
		}
	}
	for(int i=1;i<=n;i++)if(a[i]==-1)a[i]=*s.begin(),s.erase(s.begin());
	for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
	return 0;
}