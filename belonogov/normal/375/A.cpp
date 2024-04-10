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

const int maxn = 1e6 + 2;
const int inf = 1e9;

char s[maxn];
int a[maxn];
int pos[maxn];
int t[4] = {1, 6, 8, 9};
int n;

bool check(){
	int d = 0;
	for (int i = 0; i < n; i++){
		d += a[i];
		d %= 7;
		d *= 10;
	}
// 	cerr << "d: " << d << endl;
	return !d;
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		a[i] = s[i] - '0';
// 	
	for (int i = 0; i < 4; i++)
		pos[i] = i;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 4; j++)
			if (a[i] == t[j])
				swap(a[j], a[i]);
	}
	for (int i = 0; i < 24; i++){
		for (int j = 0; j < 4; j++)
			a[pos[j]] = t[j];
// 		for (int j = 0; j < 4; j++)
// 			cerr << pos[j];
// 		cerr << endl;
// 		
		if (check()){
			for (int t = 0; t < n; t++)
				printf("%d", a[t]);
			cout << endl;
			return 0;			
		}
// 		for (int j = 0; j < n; j++)
// 			cerr << a[j];
// 		cerr << endl;
// 		cerr << endl;
		next_permutation(pos, pos + 4);
	}
	
	
	return 0;
}