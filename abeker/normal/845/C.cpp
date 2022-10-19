#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 200005;

int N;
int l[MAXN], r[MAXN];
vector <int> comp;
int a[2 * MAXN];

int get(int val) {
	return lower_bound(comp.begin(), comp.end(), val) - comp.begin();
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", l + i, r + i);
		comp.push_back(l[i]);
		comp.push_back(r[i]);
	}
	
	sort(comp.begin(), comp.end());
	
	for (int i = 0; i < N; i++) {
		a[get(l[i])]++;
		a[get(r[i]) + 1]--;
	}
	
	for (int i = 1; i < 2 * MAXN; i++)
		a[i] += a[i - 1];
	
	puts(*max_element(a, a + 2 * MAXN) <= 2 ? "YES" : "NO");
	
	return 0;
}