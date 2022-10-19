#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=(1e9)+7;
const int maxn=(1e5)+10;
int n,cnt[maxn],mx;
int ans;
int v[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); int x; v[0]=n;
	for (int i=1;i<=n;i++) {
		read(x);
		cnt[x]++; v[cnt[x]-1]--; v[cnt[x]]++;
		mx=max(mx,cnt[x]);
		if (mx>1&&v[mx-1]+1==(i-1)/(mx-1)&&(i-1)%(mx-1)==0) ans=i;
		if ((i-1)%mx==0&&v[mx]==(i-1)/mx) ans=i;
		if (mx==1) ans=i;
	}
	printf("%d\n",ans);
	return 0;
}