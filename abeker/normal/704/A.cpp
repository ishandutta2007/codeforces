#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 300005;

int f[MAXN];
vector <int> V[MAXN];
vector <int> pos;

void update(int x, int val) {
	for (x++; x < MAXN; x += x & -x)
		f[x] += val;
}

int get(int x) {
	int res = 0;
	for (x++; x; x -= x & -x)
		res += f[x];	
	return res;
}

int main() {
	int N, Q;
	scanf("%d%d", &N, &Q);
	int maks = 0;
	pos.push_back(0);
	for (int i = 1; i <= Q; i++) {
		int t, x;
		scanf("%d%d", &t, &x);
		if  (t == 1) {
			V[x].push_back(i);
			update(i, 1);
			pos.push_back(i);			
		}		
		else if (t == 2) 
			for (; !V[x].empty(); V[x].pop_back())
				update(V[x].back(), -1);
		else maks = max(maks, x);
		printf("%d\n", get(i) - get(pos[maks]));
	}
	return 0;
}