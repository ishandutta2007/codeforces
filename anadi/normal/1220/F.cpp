#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second

#define LOGN 19
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 4e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, p;
int in[N];
int p1[N], p2[N];

int pt[N];
int mn[LOGN][N];

void read(){
	scanf("%d", &n);
	vector <int> tmp(n);

	for(int i = 0; i < n; ++i){
		scanf("%d", &tmp[i]);
		if(tmp[i] == 1)
			p = i + 1;
	}
	
	p1[1] = p2[1] = 1;
	in[n] = 1; int t = p - 1;

	for(int i = n - 1; i >= 1; --i){
		t = (t + n - 1) % n;
		in[i] = tmp[t];
		p1[in[i]] = i;
	}
	
	t = p - 1;
	for(int i = n + 1; i < n + n; ++i){
		t = (t + 1) % n;
		in[i] = tmp[t];
		p2[in[i]] = i;
	}
	
	for(int i = 1; i < n + n; ++i)
		mn[0][i] = in[i];
}

int ask(int from, int to){
	int t = pt[to - from + 1];
	return min(mn[t][from], mn[t][to - (1 << t) + 1]);
}

int build(int from, int to){
	if(from > to)	return 0;
	int val = ask(from, to);
//	printf("%d %d -> %d\n", from, to, val);
	if(p1[val] < from)
		return max(build(from, p2[val] - 1), build(p2[val] + 1, to)) + 1;
	return max(build(from, p1[val] - 1), build(p1[val] + 1, to)) + 1;
}

int ans, opt;
void update(int a){
	int cand = max(build(n - a, n - 1), build(n + 1, n + n - 1 - a)) + 1;
	if(cand < ans)
		ans = cand, opt = a + 1;
}

int main(){
	read();
	for(int i = 1; i < LOGN; ++i)
		for(int j = 1; j < n + n; ++j)
			mn[i][j] = min(mn[i - 1][j], mn[i - 1][min(j + (1 << (i - 1)), n + n - 1)]);
	
	pt[1] = 0;
	for(int i = 2; i < N; ++i){
		pt[i] = pt[i - 1];
		if(__builtin_popcount(i) == 1)
			pt[i]++;
	}
	
	if(n <= 2){
		printf("%d 0\n", n);
		return 0;
	}
	
	int s = 0, e = n - 1;
	while(s < e){
		int mid = (s + e + 1) >> 1;
		int Left = build(n - mid, n - 1);
		int Right = build(n + 1, n + n - 1 - mid);
//		printf("%d -> %d %d\n", mid, Left, Right);
		if(Left < Right)
			s = mid;
		else
			e = mid - 1;
	}
	
	ans = n;
	update(s);
	if(s + 1 < n)
		update(s + 1);
	
	printf("%d %d\n", ans, (p + n - opt) % n);
	return 0;
}