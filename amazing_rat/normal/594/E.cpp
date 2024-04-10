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
const int maxn=(5e6)+10;
int n,K;
char ans[maxn];
char s[maxn],t[maxn*2];
namespace K1 {
void solve() {
	for (int i=1,j=n;i<j;i++,j--) if (s[i]!=s[j]) {
		if (s[i]>s[j]) reverse(s+1,s+n+1); break;
	}
	printf("%s\n",s+1); exit(0);
}
};
int d[maxn],tot,len[maxn],Ans;
void insert(char *s,int Len) {
	for (int i=0;i<Len;i++) ans[++Ans]=s[i];
}
namespace SP {
char ans[maxn]; bool flag;
void upd(char *s) {
	for (int i=1;i<=n;i++) if (!flag||ans[i]!=s[i]) {
		if (!flag||ans[i]>s[i]) {
			flag=1;
			for (int j=1;j<=n;j++) ans[j]=s[j];
		}
		return;
	}
}
int x1[maxn],x2[maxn];
bool chk(int i,int j) {
	if (x2[j-1]>=j-i) {
		int pos=j-i+1;
		return t[pos+x1[pos]]>t[x1[pos]+1];
	}
	return t[j-1-x2[j-1]]<t[x2[j-1]+1];
}
void init() {
	for (int i=1;i<=n;i++) {
		while (i+x1[i]<n&&t[i+x1[i]]==t[x1[i]+1]) x1[i]++;
	}
	for (int i=1;i<=n;i++) {
		while (i>x2[i]&&t[i-x2[i]]==t[x2[i]+1]) x2[i]++;
	}
}
void solve() {
	// case 0
	upd(t);
	// case 1
	for (int i=1;i<=n;i++) s[i]=t[n-i+1];
	upd(s);
	// case 2
	for (int i=1;i<=n;i++) t[i+n]=t[i];
	int i=1,j=2,k=0;
	while (i<=n&&j<=n&&k<n) {
		if (t[i+k]==t[j+k]) k++;
		else if (t[i+k]<t[j+k]) j+=k+1,k=0;
		else i+=k+1,k=0;
		if (i==j) j++;
	}
	//printf("%s\n",t+1);
	for (int k=1;k<=n;k++) s[k]=t[min(i,j)+k-1];
	//printf("%s\n",s+1);
	upd(s);
	// case 3
	init();
	j=n;
	for (int i=n-1;i>=1;i--) if (chk(i,j)) j=i;
	int pos=0;
	for (int i=n;i>=j;i--) s[++pos]=t[i];
	for (int i=1;i<j;i++) s[++pos]=t[i];
	upd(s);
	//printf("%s\n",ans+1);
	// case 4
	int p=tot;
	while ((d[p+1]-d[p])*2<=(d[p]-d[p-1])) {
		bool flag=0;
		for (int i=d[p]-1;i>=d[p-1];i--) if (t[i]!=t[n-i+d[p-1]]) {
			if (t[i]<t[n-i+d[p-1]]) flag=1; break;
		}
		if (flag) break;
		p--;
	}
	p=d[p];
	pos=0;
	for (int i=p;i<=n;i++) s[++pos]=t[i];
	for (int i=p-1;i>=1;i--) s[++pos]=t[i];
	upd(s);
	insert(ans+1,n);
}
};
int main() {
	scanf("%s",s+1); read(K); n=strlen(s+1);
	//read(n),read(K),scanf("%s",s+1);
	if (K==1) K1::solve();
	for (int i=1;i<=n;i++) t[i]=s[n-i+1];
	int i=1,j,k;
	while (i<=n) {
		j=i;
		k=i+1;
		while (k<=n&&t[j]<=t[k]) {
			if (t[j]<t[k]) j=i;
			else j++;
			k++;
		}
		d[++tot]=i; len[tot]=k-j;
		while (i<=j) i+=k-j;
	}
	d[tot+1]=n+1;
//	printf("%s\n",t+1);
//	for (int i=1;i<=tot;i++) printf("%d ",d[i]); puts("");
	while (tot&&K>=3) {
		insert(t+d[tot],d[tot+1]-d[tot]);
		if (len[tot]!=1||len[tot-1]!=1) K--;
		tot--;
	}
	if (!tot) { printf("%s\n",ans+1); return 0; }
	n=d[tot+1]-1;
	SP::solve();
	printf("%s\n",ans+1);
	return 0;
}