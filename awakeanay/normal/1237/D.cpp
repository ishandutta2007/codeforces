#include <iostream>

#define int long long
#define MAXN 500005
#define INF 2000000000

int seg[4*MAXN];
int N;

void build(int arr[], int id = 1, int l = 0, int r = N-1) {
	if(l == r) {
		seg[id] = arr[l];
		return;
	}

	int m = (l+r)/2;
	build(arr, 2*id, l, m);
	build(arr, 2*id+1, m+1, r);
	seg[id] = std::max(seg[2*id], seg[2*id+1]);
}

int max(int l, int r, int id = 1, int x = 0, int y = N-1) {
	if(l <= x && y <= r)
		return seg[id];

	if(r < x || y < l)
		return 0;

	int m = (x+y)/2;
	int a = max(l, r, 2*id, x, m);
	int b = max(l, r, 2*id+1, m+1, y);
	return std::max(a, b);
}

signed main() {
	int n;
	std::cin >> n;

	int lea = INF; int mos = 0;
	int arr[4*n];
	N = 4*n;
	for(int i = 0; i < n; i++) {
		std::cin >> arr[i];
		arr[3*n+i] = arr[2*n+i] = arr[n+i] = arr[i];
		lea = std::min(lea, arr[i]);
		mos = std::max(mos, arr[i]);
	}

	if(lea*2 >= mos) {
		for(int i = 0; i < n; i++) {
			std::cout << -1 << " ";
		}
		std::cout << std::endl;
		return 0;
	}

	build(arr);

	int r = 0;
	for(int l = 0; l < n; l++) {
		while(max(l, r) <= 2*arr[r+1])
			r++;
		std::cout << r-l+1 << " ";
	}

	std::cout << std::endl;

	return 0;
}