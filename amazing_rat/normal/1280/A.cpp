#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=(1e9)+7;
const int maxn=(2e6)+10;
int T,x,n,tmp;
ll ans;
char s[maxn];
bool flag;
int main() {
//	freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(x); scanf("%s",s+1);
		ans=n=strlen(s+1);
		flag=1;
		for (int l=1;l<=x;l++) {
			if (flag) {
				tmp=n;
				for (int i=2;i<=s[l]-'0';i++) {
					for (int j=l+1;j<=n;j++) {
						s[++tmp]=s[j];
						if (tmp>x) { flag=0; break; }
					}
					if (tmp>x) { flag=0; break; }
				}
				n=tmp;
			}
			ans+=(ans-l+mod)*(s[l]-'0'-1);
		//	printf("%lld\n",ans);
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/