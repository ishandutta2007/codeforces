#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 1e5 + 2;
const int inf = 1e9;

pair < int, int > a[maxn];
pair < int, int > b[maxn];
int c[maxn];
int answer[maxn];
int n, m, s;
set < pair < int, int > > q;


bool solve(int t){
	int ss = s;
	int cur = 0;
	q.clear();
	memset(answer, -1, sizeof(answer));
	for (int i = 0; i < m; i += t){
		for (; cur < n && b[cur].fr >= a[i].fr; cur++)
			q.insert(mp(c[b[cur].sc], b[cur].sc));
// 		cerr << "set\n";
// 		for (set < pair < int, int > > :: iterator it = q.begin(); it != q.end(); it++)
// 			printf("%d %d\n", it->fr, it->sc);
		
		if (q.empty())
			return 0;
		for (int j = i; j < m && j < i + t; j++){
			answer[a[j].sc] = q.begin()->sc;	
		}
		ss -= c[q.begin()->sc];
		if (ss < 0) return 0;
		q.erase(q.begin());			
	}
	return ss >= 0;
}


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int l, r;
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++){
		scanf("%d", &a[i].fr);
		a[i].sc = i;
	}
	for (int i = 0; i < n; i++){
		scanf("%d", &b[i].fr);
		b[i].sc = i;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	sort(a, a + m, greater < pair < int, int > >());
	sort(b, b + n, greater < pair < int, int > >());
	/*for (int i = 0; i < m; i++)
		printf("%d %d\n", a[i].fr, a[i].sc);
	printf("\n");
	
	for (int i = 0; i < n; i++)
		printf("%d %d\n", b[i].fr, b[i].sc);
	printf("\n");
	*/l = 0;
	r = m + 1;
	while (r - l > 1){
		if (solve((l + r) / 2))
			r = (l + r) / 2;
		else
			l = (l + r) / 2;
	}
	if (r == m + 1){
		cout << "NO\n";
		return 0;
	}
	assert(solve(r));
	cerr << "time: " << r << endl;
	cout << "YES\n";
	for (int i = 0; i < m; i++)
		printf("%d ", answer[i] + 1);
	printf("\n");
	return 0;
}