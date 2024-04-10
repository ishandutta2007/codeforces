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

const int maxn = 2e5 + 2;
const int inf = 1e9;

pair < int, int > a[maxn];
pair < int, int > e[maxn];
vector < pair < int, int > > b;
vector < pair < int, int > > c;

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
	int n, m, pos, cur, j;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		scanf("%d%d", &a[i].fr, &a[i].sc);
		a[i].fr--;
		a[i].sc--;		
	}
	sort(a, a + m);

	int uk = 0;
	for (int i = 0; i < m; ){
		j = i;
		for (; i < m && a[i].fr == a[j].fr; i++)
			e[uk++] = a[i];
		e[uk++] = mp(a[i - 1].fr, n);		
	}
	for (int i = 0; i < uk; i++)
		a[i] = e[i];
	m = uk;
	
	if (m == 0 || a[0].fr > 0)
		b.pb(mp(0, n));
	else
		b.pb(mp(0, 1));

	for (int i = 0; i < m;){
// 		cerr << "i: " << i << endl;
		j = i;
		cur = 0;
		for (; i < m && a[j].fr == a[i].fr; i++){
			if (cur < (int)b.size()){
				pos = b[cur].fr;
				for (;cur < (int)b.size() && b[cur].sc < a[i].sc; cur++);
				
				if (a[i].sc - pos > 0)
					c.pb(mp(pos, a[i].sc));		
				if (cur < (int)b.size() &&  b[cur].fr <= a[i].sc && a[i].sc < b[cur].sc){
					b[cur].fr = a[i].sc + 1;
					if (b[cur].sc - b[cur].fr <= 0)
						cur++;				
				}
				if (cur < m && b[cur].fr <= a[i].sc)
					cur++;				
			}
		}
// 		for (int ii = 0; ii < (int)c.size(); ii++)
// 			cerr << c[ii].fr << " " << c[ii].sc << "\t\t";
// 		cerr << endl;
	
		if (!c.empty() && ((i < m && a[i].fr - a[i - 1].fr > 1) || (i == m && a[i - 1].fr != n - 1))){
			pos = c[0].fr;
			c.clear();
			c.pb(mp(pos, n));			
		}	
		b = c;
// 		for (int ii = 0; ii < (int)b.size(); ii++)
// 			cerr << b[ii].fr << " " << b[ii].sc << "\t\t";
// 		cerr << endl;
		c.clear();
	}
	if (!b.empty() && b.back().sc == n)
		cout << (n - 1) * 2 << endl;
	else
		cout << -1 << endl;
	
 
    return 0;
}