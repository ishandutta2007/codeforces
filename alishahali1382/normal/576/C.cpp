#include <bits/stdc++.h>

using namespace std;

const int MAXN=1000 * 1000 + 10;
const long long lim=(long long)2500 * 1000 * 1000;

struct point{
	int x, y, ind;
} A[MAXN];

bool cmp(point a, point b){
	if (a.x==b.x) return (a.y<b.y)^(a.x%2);
	return a.x<b.x;
}

int n;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d %d", &A[i].x, &A[i].y);
		A[i].ind=i;
		A[i].x/=1000;
	}
	sort(A, A+n, cmp);
	
	for (int i=0; i<n; i++){
		printf("%d ", A[i].ind+1);
	}
	printf("\n");
	return 0;
}