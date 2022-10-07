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

const int maxn = 1000;
const int inf = 1e9;

vector < int > a[maxn];
vector < int > b;


bool cmp(int a, int b){
	return a > b;	
}

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
	int n, res1 = 0, res2 = 0, k;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &k);
		a[i].resize(k);
		for (int j = 0; j < k; j++)
			scanf("%d", &a[i][j]);
	}
// 	for (int i = 0; i < n; i++, cerr << endl)
// 		for (int j = 0; j < (int)a[i].size(); j++)
// 			cerr << a[i][j] << " ";
// 	
	for (int i = 0; i < n; i++){
		k = a[i].size() / 2;
		for (int j = 0; j < k; j++)
			res1 += a[i][j];
		for (int j = (int)a[i].size() - 1; j >= (int)a[i].size() - k; j--)
			res2 += a[i][j];
		if ((int)a[i].size() % 2 == 1){
// 			cerr << "i pos: " << i << " " << ((int)a[i].size() ) / 2 << endl;
			b.pb(a[i][k]);
		}
	}
// 	cerr << b.size() << endl;
// 	for (int i = 0; i < (int)b.size(); i++)
// 		cerr << b[i] << " ";
// 	cerr << endl;
	sort(b.begin(), b.end(), cmp);
	for (int i = 0; i < (int)b.size(); i++){
		if (i % 2 == 0) res1 += b[i];
		if (i % 2 == 1) res2 += b[i];		
	}
	cout << res1 << " " << res2 << endl;
	
    return 0;
}