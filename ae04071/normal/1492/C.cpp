#include <bits/stdc++.h>
using namespace std;

int n,m;
char s[200100],t[200100];
int l[200100],r[200100];

int main() {
	scanf("%d%d",&n,&m);
	scanf("%s%s",s+1,t+1);
	
	int b=0;
	for(int i=1;i<=n;i++) {
		if(s[i] == t[b+1]) l[++b] = i;
	}
	b=m+1;
	for(int i=n;i;i--) {
		if(s[i] == t[b-1]) r[--b] = i;
	}

	int ans=0;
	for(int i=1;i<m;i++) {
		ans = max(ans, r[i+1] - l[i]);
	}
	printf("%d\n",ans);
	
	return 0;
}