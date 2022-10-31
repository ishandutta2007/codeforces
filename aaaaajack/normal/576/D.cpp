#include<cstring>
#include<bitset>
#include<cstdio>
#include<algorithm>
#define N 160
using namespace std;
bitset<N> mul(bitset<N> a[N],const bitset<N>& v){
	bitset<N> res;
	for(int i=0;i<N;i++) if(v[i]) res|=a[i];
	return res;
}
inline void trans(bitset<N> b[N],bitset<N> a[N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(a[i][j]) b[j][i]=true;
		}
	}
}
inline void sq(bitset<N> b[N],bitset<N> a[N]){
	bitset<N> tmp[N];
	trans(tmp,a);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			b[i][j]=(a[i]&tmp[j]).any();
		}
	}
}
bitset<N> qp(bitset<N> a[N],int p,const bitset<N>& v){
	bitset<N> t[2][N],res=v;
	int flag=0;
	for(int i=0;i<N;i++) t[0][i]=a[i];
	while(p){
		if(p&1){
			res=mul(t[flag],res);
		}
		sq(t[flag^1],t[flag]);
		flag^=1;
		p>>=1;
	}
	return res;
}
int main(){
	int n,m,a[N],b[N],d[N],td[N],sz,ans;
	bitset<N> mat[N],v;
	v[1]=true;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a[i],&b[i],&d[i]);
		td[i]=d[i];
	}
	td[m]=0;
	sort(td,td+m+1);
	sz=unique(td,td+m+1)-td;
	td[sz]=1023456789;
	for(int i=0;i<sz;i++){
		int j;
		for(j=0;j<m;j++){
			if(d[j]<=td[i]) mat[a[j]][b[j]]=true;
		}
		for(j=td[i];j<td[i+1]&&j<td[i]+n;j++){
			if(v[n]){
				printf("%d\n",j);
				return 0;
			}
			v=mul(mat,v);
		}
		v=qp(mat,td[i+1]-j,v);
	}
	puts("Impossible");
	return 0;
}