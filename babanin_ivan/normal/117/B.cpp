#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < n; i ++)
#define ford(i, n) for (int i = n - 1; i >= 0; i --)
#define mp make_pair
#define pb push_back
#define fi first
#define se second    

using namespace std;

typedef long long int64;
typedef long long ll;
typedef long double ld;

int64 a, b, mod;

bool used[20000000];

void print(int64 x) {
	vector <int64> tek;
	tek.clear();
	int64 t = x;
	while (t) {
		tek.pb(t % 10);
		t = t / 10;
	}
	while (tek.size() < 9)
		tek.pb(0);
printf("1 ");
	for (int i = tek.size() - 1; i >= 0; --i)
		printf("%d", tek[i]);
	exit(0);
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> a >> b >> mod;
	int64 i = 1;
	while (i <= a) {
		int64 x = (i * 1000000000) % mod;
		if (used[x])
			break;
		used[x] = true;
		if ((mod - x <= b) || (!x)) {
			++i;
			continue;
		}
		else {
			print(i);
		}
	}
	printf("2\n");
	return 0;
}