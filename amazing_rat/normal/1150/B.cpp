#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n;
char s[60][60];
int fx[5][2]={{-1,0},{1,0},{0,-1},{0,1},{0,0}};
void NO() {
	printf("NO\n");
	exit(0);
}
void insert(int i,int j) {
	int x,y;
	for (int k=0;k<5;k++) {
		x=i+fx[k][0];
		y=j+fx[k][1];
		if (s[x][y]=='#') NO();
		if (x<1||y<1||x>n||y>n) NO();
		s[x][y]='#';
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		if (s[i][j]=='.') insert(i+1,j);
	printf("YES\n");
	return 0;
}