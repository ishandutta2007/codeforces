#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
    while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
    f *= fu;
}

const int N = 1000 + 10;

int G[N], used[N];
int v[N], a[N], b[N], t[N], ned[N];
int n, len;

int main() {
	cin >> n;
	for(int i = 1; i < n; i++) {
		cin >> a[i] >> b[i];
		v[a[i]]++; v[b[i]]++;
		if(a[i] == b[i]) {
			printf("NO\n");
			return 0;
		}
		if(a[i] != n && b[i] != n) {
			printf("NO\n");
			return 0;
		}
	}
	if(v[n] != n - 1) {
		printf("NO\n");
		return 0;
	}
	for(int i = 1; i < n; i++) t[i] = a[i] + b[i] - n;
	sort(t + 1, t + n);
	for(int i = n - 1; i >= 1; i--) {
		if(t[i] < i) {
			printf("NO\n");
			return 0;
		}
	}
	G[1] = n;
	int now = 2;
	for(int i = n - 1; i >= 1; i--) {
		while(v[i]) {
			now++;
			v[i]--;
			used[i] = 1;
		}
		if(used[i]) G[now - 1] = i;
	}
	for(int i = 2; i <= n; i++) {
		if(G[i] == 0) ned[++len] = i;
	}
	int tmp = 1;
	for(int i = n - 1; i >= 1; i--) {
		if(!used[i]) {
			G[ned[tmp]] = i;
			tmp++;
		}
	}
	printf("YES\n");
	for(int i = 1; i < n; i++) {
		printf("%d %d\n", G[i], G[i + 1]);
	}
	return 0;
}