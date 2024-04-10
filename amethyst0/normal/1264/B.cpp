//#pragma comment(linker, "/STACK:1000000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = 4;

int in[maxn];
int out[maxn];

vector <int> ed[4];

vector <int> vert;

void euler(int x) {
	while (!ed[x].empty()) {
		int y = ed[x].back();
		ed[x].pop_back();
		euler(y);
	}

	vert.push_back(x);
}

int n;

void check(int x, int y) {
	for (int i = 0; i < 4; i++) {
		ed[i].clear();
	}

	for (int i = 0; i < out[0]; i++) {
		ed[0].push_back(1);
	}

	for (int i = 0; i < in[0]; i++) {
		ed[1].push_back(0);
	}

	for (int i = 0; i < out[3]; i++) {
		ed[3].push_back(2);
	}

	for (int i = 0; i < in[3]; i++) {
		ed[2].push_back(3);
	}

	if (out[2] - in[3] < 0 || out[2] - in[3] != in[1] - out[0]) {
		return;
	}

	for (int i = 0; i < out[2] - in[3]; i++) {
		ed[2].push_back(1);
	}

	if (out[1] - in[0] < 0 || out[1] - in[0] != in[2] - out[3]) {
		return;
	}

	for (int i = 0; i < out[1] - in[0]; i++) {
		ed[1].push_back(2);
	}

	vert.clear();
	euler(x);

	reverse(vert.begin(), vert.end());

	if ((int)vert.size() != n || vert.back() != y) {
		return;
	}

	cout << "YES\n";

	for (int x : vert) {
		printf("%d ", x);
	}

	//system("pause");
	exit(0);
}

int main() {
	int a, b, c, d;

	cin >> a >> b >> c >> d;

	n = a + b + c + d;

	in[0] = a;
	out[0] = a;
	in[1] = b;
	out[1] = b;
	in[2] = c;
	out[2] = c;
	in[3] = d;
	out[3] = d;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			in[i]--;
			out[j]--;
			if (in[i] >= 0 && out[j] >= 0) {
				check(i, j);
			}

			in[i]++;
			out[j]++;
		}
	}

	cout << "NO\n";

	//system("pause");
}