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

const int N = 200000 + 5;

pair <int, int> a[N];
set < pair <int, int> > t;
int ans[N];
int n, m, d, tot = 1;

int main() {
	cin >> n >> m >> d;
	for(int i = 1; i <= n; i++) read(a[i].first);
	for(int i = 1; i <= n; i++) a[i].second = i;
	sort(a + 1, a + n + 1);
	ans[a[1].second] = 1;
	t.insert(make_pair(a[1].first, 1));
	for(int i = 2; i <= n; i++) {
		set < pair <int, int> > :: iterator it = t.begin();
		if(a[i].first - it -> first > d) {
			ans[a[i].second] = it -> second;
			t.erase(make_pair(it -> first, it -> second));
			t.insert(make_pair(a[i].first, ans[a[i].second]));
		} else {
			tot++; ans[a[i].second] = tot;
			t.insert(make_pair(a[i].first, tot));
		}
	}
	cout << tot << endl;
	for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}