#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
struct node {
	int len,d[maxn];
	friend bool operator < (node t1,node t2) {
		if (t1.len!=t2.len) return t1.len<t2.len;
		for (int i=t1.len;i>=1;i--)
			if (t1.d[i]!=t2.d[i])
				return t1.d[i]<t2.d[i];
		return 1;
	}
} ans,A;
int n,d[maxn];
char s[maxn];
void insert(int i) {
	if (d[i+1]==0||max(n-i,i)>ans.len) return;
	int a=i,b=n,r=0; A.len=0;
	while (a||b) {
		A.len++;
		A.d[A.len]=(d[a]+d[b]+r)%10;
		r=(d[a]+d[b]+r)/10;
		if (a==1||a==0) a=0; else a--;
		if (b==i+1||b==0) b=0; else b--;
	}
	if (A<ans) ans=A;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) d[i]=s[i]-'0';
	ans.len=(1e9);
	for (int i=n/2;i>=1;i--) insert(i);
	for (int i=n/2+1;i<n;i++) insert(i);
	for (int i=ans.len;i>=1;i--)
		printf("%d",ans.d[i]);
	printf("\n");
	return 0;
}