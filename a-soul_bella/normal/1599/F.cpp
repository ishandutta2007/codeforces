#include <bits/stdc++.h>
 
using namespace std;
 
const int B=20; 
const int maxn=2e5,mod=1e9+7,inv2=(mod+1)/2; 
int n,q,a[maxn+5],lst[maxn+5]; 
int S[B+5][maxn+5],C[B+5][B+5];
int ans[maxn+5]; 
map<int,int> pos; 
struct node {
	int l,r,d,id; 
} ;
vector<node> Q[maxn+5];  
 
int add(int x,int y) {
	return (x+=y)>=mod?x-mod:x;
}
struct ddd {
	int sum[B+5],siz; 
	ddd() {
		memset(sum,0,sizeof(sum));
		siz=0; 
	}
	ddd operator + (const ddd &x) const {
		ddd ret;
		ret.siz=siz+x.siz; 
		for (int i=0;i<=B;i++) {
			ret.sum[i]=add(sum[i],x.sum[i]); 
		}
		return ret; 
	}
} s[(maxn<<2)+5];
 
void modify(int p,int l,int r,int pos,int d) {
	if (l==r) {
		int pw=1; 
		if (d==-1) s[p].siz=0;
		else s[p].siz=1; 
		if (d==-1) d=0; 
		for (int i=0;i<=B;i++) {
			s[p].sum[i]=pw;
			pw=1ll*pw*d%mod; 
		}
		return ; 
	}
	int mid=(l+r)>>1;
	if (pos<=mid) modify(p+p,l,mid,pos,d);
	else modify(p+p+1,mid+1,r,pos,d); 
	s[p]=s[p+p]+s[p+p+1];
}
ddd query(int p,int l,int r,int ql,int qr) {
	if (l==ql&&r==qr) return s[p];
	int mid=(l+r)>>1;
	if (qr<=mid) return query(p+p,l,mid,ql,qr);
	else if (mid<ql) return query(p+p+1,mid+1,r,ql,qr);
	else return query(p+p,l,mid,ql,mid)+query(p+p+1,mid+1,r,mid+1,qr); 
}
int tmp[maxn+5]; 
int fpw(int x,int k,int p) {
	int ret=1;
	while (k) {
		if (k&1) ret=1ll*ret*x%p;
		x=1ll*x*x%p; k>>=1; 
	}
	return ret; 
}
int main() {
	scanf("%d %d",&n,&q);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		lst[i]=pos[a[i]];
		pos[a[i]]=i; 
	}	
	C[0][0]=1;
	for (int i=1;i<=B;i++) {
		C[i][0]=1;
		for (int j=1;j<=i;j++) C[i][j]=add(C[i-1][j-1],C[i-1][j]);
	}
	for (int i=0;i<=n;i++) tmp[i]=1; 
	for (int k=0;k<=B;k++) {
		if (k==0) S[0][0]=1; 
		for (int i=1;i<=n;i++) S[k][i]=add(S[k][i-1],tmp[i]),tmp[i]=1ll*tmp[i]*i%mod;
	}
	for (int i=1;i<=n;i++) pos[a[i]]=0; 
	for (int i=1;i<=q;i++) {
		node qq; 
		scanf("%d %d %d",&qq.l,&qq.r,&qq.d);
		qq.id=i;
		Q[qq.r].push_back(qq);
	}
	for (int i=1;i<=n;i++) {
		if (pos[a[i]])
			modify(1,1,n,pos[a[i]],-1);
		modify(1,1,n,i,a[i]);
		pos[a[i]]=i;
		for (auto qq:Q[i]) {
			int L,Lpw[B+5],dpw[B+5],siz,d;  
			ddd D=query(1,1,n,qq.l,qq.r);
			siz=D.siz; d=qq.d; 
			L=add(D.sum[1],mod-1ll*(siz-1)*siz%mod*inv2%mod*d%mod); 
			L=1ll*L*fpw(siz,mod-2,mod)%mod; 
			// cout<<qq.l<<' '<<qq.r<<' '<<qq.d<<' '<<siz<<' '<<L<<'\n'; 
			if (pos[L]<qq.l) {
				continue ; 
			}
			Lpw[0]=1; dpw[0]=1; 
			int ok=1; 
			for (int j=1;j<=B;j++) Lpw[j]=1ll*Lpw[j-1]*L%mod,dpw[j]=1ll*dpw[j-1]*d%mod; 
			for (int k=2;k<=B;k++) {
				int hsh=0;
				for (int j=0;j<=k;j++) {
					hsh=add(hsh,1ll*Lpw[j]*C[k][j]%mod*dpw[k-j]%mod*S[k-j][siz-1]%mod); 
				}
				if (hsh!=D.sum[k]) {
					ok=0; 
					break ; 
				}
			}
			ans[qq.id]=ok; 
		}
	}
	for (int i=1;i<=q;i++) if (ans[i]) puts("Yes"); else puts("No"); 
	return 0; 
}