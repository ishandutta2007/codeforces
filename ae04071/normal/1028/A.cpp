#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

int n,m;
char str[200][200];

int main() {
	int t,b,l,r;
	scanf("%d%d",&n,&m);
	t=n;b=0;l=m;r=0;
	for(int i=0;i<n;i++) {
		scanf("%s",str[i]);
		for(int j=0;j<m;j++) if(str[i][j]=='B') {
			t=min(t,i); b=max(b,i);
			l=min(l,j); r=max(r,j);
		}
	}
	printf("%d %d\n",(t+b)/2+1, (l+r)/2+1);
	return 0;
}