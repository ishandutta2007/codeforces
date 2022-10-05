#include<bits/stdc++.h>
using namespace std;
const int N=70009;
char s[N],a[5],b[5];
int mp[500009],h[N],len[N],f[509][N],p[5][N],aa[N];
vector<int>v[N];
inline int get(char*s,int l){
	int r=0,i=0;
	for(;i<l;++i)r=r*26+s[i]-96;
	return r;
}
int main(){
	int n,q,id=0,ct=0,i,j,k,l,u,x,y,z,o;
	scanf("%s%d",s+1,&q),n=strlen(s+1);
	for(l=1;l<5;++l){
		for(i=1,j=n-l+2;i<j;++i){
			k=get(s+i,l);
			if(!mp[k])mp[k]=++id,len[id]=l;
			v[p[l][i]=mp[k]].push_back(i);
		}
	}
	for(i=1;i<=id;++i)aa[i]=i;
	sort(aa+1,aa+id+1,[](int x,int y){return v[x].size()>v[y].size();});
	for(int gg=1;gg<=min(id,500);++gg){
		i=aa[gg],j=v[i].size(),h[i]=++ct,u=len[i],memset(f[ct],9,id+2<<2);
		for(k=1;k<j;++k){
			x=v[i][k-1],y=v[i][k];
			for(z=x;z<y;++z)for(l=1;l<5;++l)f[ct][p[l][z]]=min(f[ct][p[l][z]],min(max(z+l-x,u),max(y+u-z,l)));
		}
		for(z=x=v[i][j-1];z<=n;++z)for(l=1;l<5;++l)f[ct][p[l][z]]=min(f[ct][p[l][z]],max(z+l-x,u));
		for(z=1,y=v[i][0];z<y;++z)for(l=1;l<5;++l)f[ct][p[l][z]]=min(f[ct][p[l][z]],max(y+u-z,l));
	}
	while(q--){
		scanf("%s%s",a,b),x=mp[get(a,strlen(a))],y=mp[get(b,strlen(b))];
		if(!x||!y)puts("-1");
		else if(h[x])printf("%d\n",f[h[x]][y]);
		else if(h[y])printf("%d\n",f[h[y]][x]);
		else{
			j=v[x].size(),k=v[y].size()-1,l=len[x],u=len[y],z=0,o=1e9;
			for(i=0;i<j;++i){
				while(z<k&&v[y][z]<v[x][i])++z;
				if(v[y][z]>=v[x][i]){
					o=min(o,v[y][z]+u-v[x][i]);
					if(z)o=min(o,v[x][i]+l-v[y][z-1]);
				}else o=min(o,v[x][i]+l-v[y][z]);
			}
			printf("%d\n",max(o,max(l,u)));
		}
	}
	return 0;
}