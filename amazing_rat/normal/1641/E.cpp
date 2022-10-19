// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
typedef long long ll;
typedef vector<int> poly;
const int mod=998244353;
const int maxn=(3e5)+10;
int n,m;

int ksm(int x,int y) {
    int res=1;
    while (y) {
        if (y&1) res=(ll)res*x%mod;
        x=(ll)x*x%mod; y>>=1;
    }
    return res;
}
int N,rev[maxn],BB[maxn],w[maxn],lg;
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
void init(int n) {
    N=1; lg=0;
    while (N<n) N*=2,lg++;
    for (int i=0;i<N;i++)
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
    int V=ksm(3,(mod>>lg));
    w[N>>1]=1;
    for (int i=(N>>1)+1;i<N;i++) w[i]=(ll)w[i-1]*V%mod;
    for (int i=(N>>1)-1;i>=1;i--) w[i]=w[i<<1];
}
void ntt(int *a,int flag) {
    if (flag==-1) reverse(a+1,a+N);
    int tmp;
    for (int i=0;i<N;i++) BB[i]=a[rev[i]];
    for (int i=1;i<N;i<<=1)
    for (int j=0;j<N;j+=(i<<1))
    for (int k=0;k<i;k++) {
        tmp=(ll)BB[i+j+k]*w[i+k]%mod;
        BB[i+j+k]=BB[j+k]+mod-tmp; if (BB[i+j+k]>=mod) BB[i+j+k]-=mod;
        BB[j+k]+=tmp; if (BB[j+k]>=mod) BB[j+k]-=mod;
    }
    for (int i=0;i<N;i++) a[i]=BB[i];
    if (flag==-1) {
        int V=mod-(mod-1)/N;
        for (int i=0;i<N;i++) a[i]=(ll)a[i]*V%mod;
    }
}
void print(poly A) {
    for (int i=0;i<A.size();i++) printf("%d ",A[i]); printf("\n");
}
poly operator * (poly A,poly B) {
    int n=(int)A.size(),m=(int)B.size();
    if (n+m<=150) {
        poly res(n+m-1,0);
        for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) update(res[i+j],(ll)A[i]*B[j]%mod);
        return res;
    }
    init(n+m+2);
    A.resize(N,0),B.resize(N,0);
    ntt(A.data(),1),ntt(B.data(),1);
    for (int i=0;i<N;i++) A[i]=(ll)A[i]*B[i]%mod;
    ntt(A.data(),-1);
    A.resize(n+m-1);
    return A;
}
int a[maxn],S[maxn],T[maxn],ans,mi[maxn],p[maxn];
int pre[maxn],suf[maxn];
bool mk[maxn];
int res[maxn],P[maxn],Q[maxn];
void dfs(int l,int r) {
	if (l>=r) return;
	int mid=(l+r)>>1;
	dfs(l,mid),dfs(mid+1,r);
	poly A(mid-l+1),B(r-mid+2);
	int f=0,g=0;
	for (int i=l;i<=mid;i++) if (mk[i]) A[i-l]=P[i],f=1;
	for (int i=mid+1;i<=r;i++) if (mk[i]) B[i-mid-1]=Q[i],g=1;
	if (!f||!g) return;
	A=A*B;
	for (int i=0;i<A.size();i++) if (A[i]) update(res[i+l+mid+1],A[i]);
}
void solve(int op) {
	memset(res,0,sizeof(res)),memset(mk,0,sizeof(mk));
	memset(P,0,sizeof(P)),memset(Q,0,sizeof(Q));
	for (int i=1;i<=m;i++) if (p[i]%2==op) mk[p[i]]=1;
	for (int i=1;i<=m;i++) pre[i]=(pre[i-1]+(p[i]%2==op)*mi[i-1])%mod;
	for (int i=m;i>=1;i--) suf[i]=(suf[i+1]+(p[i]%2==op)*mi[m-i])%mod;
	for (int i=1;i<=m;i++) if (p[i]%2==op) {
		update(ans,(ll)p[i]*S[p[i]-1]%mod*suf[i+1]%mod*mi[i-1]%mod);
		update(ans,(ll)p[i]*S[p[i]]%mod*pre[i-1]%mod*mi[m-i]%mod);
		update(ans,mod-(ll)T[p[i]-1]*suf[i+1]%mod*mi[i-1]%mod);
		update(ans,mod-(ll)T[p[i]]*pre[i-1]%mod*mi[m-i]%mod);
		P[p[i]]=mi[i-1];
		Q[p[i]]=mi[m-i];
	}
	dfs(1,n);
	for (int i=2;i<=n*2;i+=2) update(ans,(ll)T[i/2]*2%mod*res[i]%mod);
	memset(res,0,sizeof(res));
	for (int i=1;i<=m;i++) if (p[i]%2==op) {
		P[p[i]]=(ll)p[i]*mi[i-1]%mod;
		Q[p[i]]=mi[m-i];
	}
	dfs(1,n);
	for (int i=2;i<=n*2;i+=2) update(ans,mod-(ll)S[i/2]*res[i]%mod);
	memset(res,0,sizeof(res));
	for (int i=1;i<=m;i++) if (p[i]%2==op) {
		P[p[i]]=mi[i-1];
		Q[p[i]]=(ll)mi[m-i]*p[i]%mod;
	}
	dfs(1,n);
	for (int i=2;i<=n*2;i+=2) update(ans,mod-(ll)S[i/2]*res[i]%mod);
}
int PRE[maxn][2],SUF[maxn][2];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	mi[0]=1; for (int i=1;i<maxn;i++) mi[i]=(ll)mi[i-1]*2%mod;
	init(n*2+5);
	for (int i=1;i<=n;i++) read(a[i]),S[i]=(S[i-1]+a[i])%mod,T[i]=(T[i-1]+(ll)a[i]*i%mod)%mod;
	for (int i=1;i<=m;i++) read(p[i]);
	
	for (int i=1;i<=m;i++) {
		int tmp=((ll)S[p[i]]*p[i]-T[p[i]]+mod)%mod;
		update(ans,(ll)tmp*mi[m-i]%mod);
		tmp=((ll)T[n]-T[p[i]-1]+mod-(ll)p[i]*(S[n]-S[p[i]-1]+mod)%mod+mod)%mod;
		update(ans,(ll)tmp*mi[i-1]%mod);
	}
	solve(0),solve(1);
	memset(res,0,sizeof(res)),memset(P,0,sizeof(P)),memset(Q,0,sizeof(Q)),memset(mk,0,sizeof(mk));
	for (int i=1;i<=m;i++) {
		PRE[i][0]=PRE[i-1][0],PRE[i][1]=PRE[i-1][1];
		update(PRE[i][p[i]%2],mi[i-1]);
	}
	for (int i=m;i>=1;i--) {
		SUF[i][0]=SUF[i+1][0],SUF[i][1]=SUF[i+1][1];
		update(SUF[i][p[i]%2],mi[m-i]);
	}
//	printf("%d\n",ans);
	for (int i=1;i<=m;i++) {
		update(ans,(ll)S[p[i]-1]*p[i]%mod*SUF[i+1][p[i]&1^1]%mod*mi[i-1]%mod);
		update(ans,(ll)S[p[i]]*p[i]%mod*PRE[i-1][p[i]&1^1]%mod*mi[m-i]%mod);
		update(ans,mod-(ll)T[p[i]-1]*SUF[i+1][p[i]&1^1]%mod*mi[i-1]%mod);
		update(ans,mod-(ll)T[p[i]]*PRE[i-1][p[i]&1^1]%mod*mi[m-i]%mod);
		mk[p[i]]=1;
		P[p[i]]=mi[i-1],Q[p[i]]=mi[m-i];
	}
	//int tmp=p[1]*S[p[1]-1]+p[2]*S[p[2]];
	//tmp-=T[p[1]-1]+T[p[2]];
	//printf("tmp=%d\n",tmp);
	//printf("%d\n",ans);
	dfs(1,n);
	for (int i=1;i<=n*2;i+=2) update(ans,(ll)2*T[i/2]*res[i]%mod);
	memset(res,0,sizeof(res));
	for (int i=1;i<=m;i++) P[p[i]]=(ll)p[i]*mi[i-1]%mod;
	dfs(1,n);
	for (int i=1;i<=n*2;i+=2) update(ans,mod-(ll)S[i/2]*res[i]%mod);
	memset(res,0,sizeof(res));
	for (int i=1;i<=m;i++) P[p[i]]=mi[i-1],Q[p[i]]=(ll)p[i]*mi[m-i]%mod;
	dfs(1,n);
	for (int i=1;i<=n*2;i+=2) update(ans,mod-(ll)S[i/2]*res[i]%mod);
	
	//printf("%d\n",ans);
	ans=(ll)ans*ksm(mi[m]-1,mod-2)%mod;
	printf("%d\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/