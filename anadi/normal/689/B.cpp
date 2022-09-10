#include <bits/stdc++.h>

using namespace std;

const int mxn = 2e5 + 9;

int n;
int D[mxn][3];
queue <int> Q;
int d[mxn];

void check(int a, int b){
	if(d[a] != -1)
		return;
	d[a] = d[b] + 1;
	Q.push(a);
}

void BFS(){
	for(int i = 2; i <= n; ++i)
		d[i] = -1;
	Q.push(1);
	
	while(!Q.empty()){
		int k = Q.front();
		Q.pop();
		check(D[k][0], k);
		check(D[k][1], k);
		check(D[k][2], k);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &D[i][0]);
	for(int i = 1; i <= n; ++i)
		D[i][1] = i + 1;
	for(int i = 1; i <= n; ++i)
		D[i][2] = i - 1;
	BFS();
	for(int i = 1; i <= n; ++i)
		printf("%d ", d[i]);
	return 0;
}