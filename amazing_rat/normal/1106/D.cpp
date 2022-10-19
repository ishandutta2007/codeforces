#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int n,m,x,y,vis[maxn];
vector<int> g[maxn];
struct cmp {
	bool operator() (int a,int b) {
		return a>b;
	}
};
priority_queue<int,vector<int>,cmp> q;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=m;i++) {
		read(x); read(y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	q.push(1); vis[1]=1;
	while (!q.empty()) {
		x=q.top(); q.pop();
		printf("%d ",x);
		for (int i=0;i<g[x].size();i++) {
			y=g[x][i];
			if (!vis[y]) {
				q.push(y); vis[y]=1;
			}
		}
	} printf("\n");
	return 0;
}