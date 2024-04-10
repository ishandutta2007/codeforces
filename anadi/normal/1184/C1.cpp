#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 2e5 + 7;

int n;
int in[N][2];
int x[N], y[N];
int minx = 100, maxx, miny = 100, maxy;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= 4 * n + 1; ++i){
		scanf("%d %d", &in[i][0], &in[i][1]);
		x[i] = in[i][0], y[i] = in[i][1];
	}
	
	sort(x + 1, x + 4 * n + 2);
	sort(y + 1, y + 4 * n + 2);
	
	minx = x[2], maxx = x[4 * n];
	miny = y[2], maxy = y[4 * n];
	
	for(int i = 1; i <= 4 * n + 1; ++i){
		if(in[i][0] < minx || maxx < in[i][0] || in[i][1] < miny || maxy < in[i][1]){
			printf("%d %d\n", in[i][0], in[i][1]);
			return 0;
		}

		if(in[i][0] == minx || in[i][0] == maxx || in[i][1] == miny || in[i][1] == maxy)
			continue;

		printf("%d %d\n", in[i][0], in[i][1]);
		break;
	}

	return 0;
}