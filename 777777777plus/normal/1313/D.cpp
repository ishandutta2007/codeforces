#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 6e5+5;

int n,m,k;
int l[N],r[N],q[N];
vector<int>vl[N],vr[N];
int func[2][1<<8],num[1<<8];
int *f=func[0],*g=func[1];

void clear(){
	swap(g,f);
	memset(g,0,sizeof(g));
}

int main(){
	scanf("%d%*d%*d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&l[i],&r[i]);
		q[++m]=l[i];
		q[++m]=r[i];
		q[++m]=r[i]+1;
		q[++m]=l[i]-1;
	}
	sort(q+1,q+m+1);
	m=unique(q+1,q+m+1)-q-1;
	for(int i=1;i<=n;++i){
		l[i]=lower_bound(q+1,q+m+1,l[i])-q;
		r[i]=lower_bound(q+1,q+m+1,r[i])-q;
		vl[l[i]].push_back(i);
		vr[r[i]].push_back(i);
	}
	for(int i=1;i<(1<<8);++i)num[i]=num[i>>1]+(i&1);
	for(int i=1;i<=m;++i){
		static bool use[8];
		static int id[N],S;
		for(int j=0;j<vr[i-1].size();++j){
			int x=vr[i-1][j];
			for(int k=S;;k=(k-1)&S){
				g[k^(k&1<<id[x])]=max(g[k^(k&1<<id[x])],f[k]);
				if(!k)break;
			}
			use[id[x]]=0;
			S^=1<<id[x];
			clear();
		}
		for(int k=S;;k=(k-1)&S){
			g[k]=max(g[k],f[k]+((num[k]&1)?1:0)*(q[i]-q[i-1]));
			if(!k)break;
		}
		clear();
		for(int j=0;j<vl[i].size();++j){
			int x=vl[i][j];
			for(int k=0;k<8;++k)
			if(!use[k]){
				use[k]=1;
				id[x]=k;
				break;
			}
			S^=1<<id[x];
			for(int k=S;;k=(k-1)&S){
				if(k&1<<id[x])g[k]=max(g[k],f[k^1<<id[x]]+((num[k]&1)?1:-1)*(q[i]-q[i-1]));
				else g[k]=max(g[k],f[k]);	
				if(!k)break;
			}
			clear();
		}
	}
	printf("%d\n",*max_element(f,f+(1<<8)));
}