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

const int maxn = 1e6;
const int inf = 1e9;

int a[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int n, k, l, r, Sall, Sk;
	cin >> n >> k >> l >> r >> Sall >> Sk;
	
	Sk -= k * l;
	Sall -= n * l;
	int d = Sk / k;
	for (int i = 0; i < k; i++)
		a[i] = d;
	int t = Sk - k * d;
	for (int i = 0; i < t; i++)
		a[i]++;
	
	if (n != k){
		Sall -= Sk;
		d = Sall / (n - k);
		for (int i = k; i < n; i++)
			a[i] = d;
		t = Sall - (n - k) * d;
		for (int i = k; i < t + k; i++)
			a[i]++;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", a[i	] + l);
	printf("\n");
	
	
	
	
 
    return 0;
}