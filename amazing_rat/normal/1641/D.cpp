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
typedef unsigned long long ull;
const int INF=(2e9)+10;
const ull xyr=(1e9)+7;
const int maxn=(1e5)+10;
int n,m;
int tot,a[maxn][6],w[maxn];
int b[maxn][32];
map<int,int> MM;
map<ull,int> M;
int id[maxn];
bool cmp(int x,int y) { return w[x]<w[y]; }
int ans=INF;
struct node {
	int id,l,r,mid;
};
vector<node> Q,Q2;
int cnt[maxn*32],bit[340];
bool CMP(node A,node B) { return A.mid<B.mid; }
pair<ull,pair<int,int> > D[maxn*32];
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	for (int i=1;i<=n;i++) {
		MM.clear();
		int flag=1;
		for (int j=0;j<m;j++) {
			read(a[i][j]);
			if (MM[a[i][j]]) flag=0; MM[a[i][j]]=1;
		}
		read(w[i]);
		if (!flag) i--,n--;
	}
	for (int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,cmp);
	int tot2=0;
	for (int i=1;i<=n;i++) {
		sort(a[i],a[i]+m);
		for (int t=1;t<(1<<m);t++) {
			ull V=0;
			for (int j=0;j<m;j++) if (t>>j&1) V=V*xyr+a[i][j];
			D[++tot2]=MP(V,MP(i,t));
		}
		Q.push_back((node){i,1,n,0});
	}
	sort(D+1,D+tot2+1);
	for (int i=1;i<=tot2;i++) {
		if (D[i].first!=D[i-1].first||i==1) tot++;
		b[D[i].second.first][D[i].second.second]=tot;
	}
	for (int t=1;t<(1<<m);t++) {
		int cnt=0; for (int i=0;i<m;i++) if (t>>i&1) cnt++;
		if (cnt&1) bit[t]=1; else bit[t]=-1;
	}
	while (!Q.empty()) {
		for (int i=1;i<=tot;i++) cnt[i]=0;
		for (node &A : Q) A.mid=(A.l+A.r)/2;
		Q2.clear();
		sort(Q.begin(),Q.end(),CMP);
		int pos=1;
		for (node &A : Q) {
			while (pos<=A.mid) {
				for (int t=1;t<(1<<m);t++) {
					cnt[b[id[pos]][t]]+=bit[t];
				}
				pos++;
			}
			int now=0;
			for (int t=1;t<(1<<m);t++) now+=cnt[b[A.id][t]];
			if (A.mid-now>0) {
				ans=min(ans,w[A.id]+w[id[A.mid]]);
				//printf("%d %d %d %d\n",A.id,id[A.mid],A.mid,now);
				if (A.l<A.mid) Q2.push_back((node){A.id,A.l,A.mid-1,0});
			} else if (A.mid<A.r) Q2.push_back((node){A.id,A.mid+1,A.r,0});
		}
		Q.swap(Q2);
	}
	if (ans==INF) ans=-1;
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