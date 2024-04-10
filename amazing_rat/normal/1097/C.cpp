#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(5e5)+10;
int n,cnt,len;
char s[maxn];
int S[maxn*2],ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) {
		scanf("%s",s+1);
		len=strlen(s+1); cnt=0;
		int MN=0;
		for (int j=1;j<=len;j++) {
			if (s[j]=='(') cnt++; else cnt--;
			MN=min(MN,cnt);
		}
		if (MN>=0) S[cnt+maxn]++;
		else if (cnt<0&&MN==cnt) S[cnt+maxn]++;
	}
	for (int i=1;i<maxn;i++)
		ans+=min(S[i+maxn],S[-i+maxn]);
	ans+=S[maxn]/2;
	printf("%d\n",ans);
	return 0;
}