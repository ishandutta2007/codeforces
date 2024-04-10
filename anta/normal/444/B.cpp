#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int glb_x;
int getNextX() {
    glb_x = (glb_x * 37LL + 10007) % 1000000007;
    return glb_x;
}

int main() {
	int n, d;
	scanf("%d%d%d", &n, &d, &glb_x);
	vector<int> a(n), b(n);

	for(int i = 0; i < n; i = i + 1)
        a[i] = i + 1;
    for(int i = 0; i < n; i = i + 1)
        swap(a[i], a[getNextX() % (i + 1)]);
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1)
        swap(b[i], b[getNextX() % (i + 1)]);


	//c[i] = max_{j=0}^i a[j]*b[i-j]
	//d
	//d100
	//	
	//d
	//	b

	vector<int> c(n, 0);

	if(d >= 2000) {
		priority_queue<pair<int,int> > q;
		vector<pair<int,int> > tmp;

		rep(i, n) {
			q.push(mp(a[i], i));
			
			while(!q.empty()) {
				int j = q.top().second;
				tmp.push_back(q.top());
				q.pop();
				if(b[i-j] == 1) {
					c[i] = a[j];
					break;
				}
			}

			each(i, tmp)
				q.push(*i);
			tmp.clear();
		}

	}else {
		vector<int> ones;
		rep(i, n) if(b[i] == 1)
			ones.push_back(i);

		rep(i, n) {
			each(o, ones) {
				if(*o <= i)
					amax(c[i], a[i-*o]);
			}
		}
	}

	rep(i, n)
		printf("%d\n", c[i]);

	return 0;
}