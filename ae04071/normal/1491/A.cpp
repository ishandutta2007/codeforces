#include <bits/stdc++.h>
using namespace std;

int n,m,a[100001];

int main() {
	int c[2] = {0,};
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i),c[a[i]]++;
	while(m--) {
		int t,v;
		scanf("%d%d",&t,&v);
		if(t==1) {
			c[a[v]]--;
			c[1-a[v]]++;
			a[v] = 1-a[v];
		} else {
			puts(c[1] >= v ? "1" : "0");
		}
	}
	return 0;
}