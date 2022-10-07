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

const int maxn = 1e6 + 100;
const int maxlog = 22;
const int inf = 1e9;

char s[maxn];
int b[maxn];
int table[maxn][maxlog];
int st[maxn];
int pref[maxn];


int getCnt(int l, int r){
	return pref[r] - pref[l];	
}

int getMin(int l, int r){
	r++;
	int t = st[r - l];
// 	cerr << "l r t " << l << " " << r << " " << t << endl;
	return min(table[l][t], table[r - (1 << st[r - l])][t]);	
}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
	int n, m, l, r;
	scanf("%s", s);
	n = strlen(s);
	b[0] = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == '(')
			b[i + 1] = b[i] + 1;
		else
			b[i + 1] = b[i] - 1;
	for (int i = 0; i < n; i++)
		pref[i + 1] = pref[i] + (s[i] == ')');
	st[1] = 0;
	
	
	for (int i = 2; i <= n + 2; i++){
		st[i] = st[i - 1];
		if ((1 << (st[i] + 1)) < i)
			st[i]++;		
	}
	
	for (int i = 0; i <= n; i++)
		table[i][0] = b[i];
	for (int j = 1; j < maxlog; j++)
		for (int i = 0; i <= n - (1 << j) + 1; i++)
			table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
// 	for (int j = 0; j < 10; j++, cerr << endl)
// 		for (int i = 0; i <= n; i++)
// 			cerr << table[i][j] << " ";
// 		
// 		
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		scanf("%d%d", &l, &r); l--;
// 		cerr << "b[i]: " << b[l] << endl;
// 		cerr << "getMin: " << getMin(l, r) << endl;
		cout << (getCnt(l, r) - (b[l] - getMin(l, r))) * 2 << endl;
	}
	
 
    return 0;
}