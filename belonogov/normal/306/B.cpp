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

struct Event{
	int t, id, type, r;
	Event(){}
	Event(int t, int id, int type, int r): t(t), id(id), type(type), r(r){}
};

Event a[maxn * 2];
bool use[maxn];
vector < int > answer;
set < pair < int, int > > q;


bool cmp(Event a, Event b){
	return a.t < b.t || (a.t == b.t && a.type < b.type);	
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int n, m, l, r, cur = 0, curentSeg;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		scanf("%d%d", &l, &r);
		l--;
		r += l;
		a[cur++] = Event(l, i, 0, r);
		a[cur++] = Event(r, i, 1, -1);		
	}
	
	sort(a, a + cur, cmp);
	
	curentSeg = -1;
	for (int i = 0; i < cur; ){
		int j = i;
		for (; i < cur && a[j].t == a[i].t; i++){
			if (a[i].type == 0)
				q.insert(mp(a[i].r, a[i].id));
			else{
				q.erase(mp(a[i].t, a[i].id));
				if (a[i].id == curentSeg)
					curentSeg = -1;				
			}
		}
		if (!q.empty() && curentSeg == -1){
			curentSeg = q.rbegin()->sc;
// 			cerr << curentSeg << endl;
			answer.pb(curentSeg);
		}		
	}
	
	
	for (int i = 0; i < (int)answer.size(); i++)
		use[answer[i]] = 1;

	printf("%d\n", m - (int)answer.size());
	for (int i = 0; i < m; i++)
		if (!use[i])
			printf("%d ", i + 1);	
	printf("\n");
	
 
    return 0;
}