#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
char s[3];
char t[3];
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%s",s+1);
	for (int i=1;i<=5;i++) {
		scanf("%s",t+1);
		if (t[1]==s[1]||t[2]==s[2]) {
			printf("YES\n"); return 0;
		}
	} printf("NO\n");
	return 0;
}