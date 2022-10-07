#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <ctime>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <functional>
#include <memory.h>


using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define less lessss
#define equal equall
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z <<  ") = (" << x << ", " << y << ", " << z << ")" << endl
#define get gettt

const int INF = 1e9 + 10;
const int N = 1111;
const int K = 10;

struct pt {
	long long x, y;
	int id;
	pt () { }
	pt (long long x, long long y): x(x), y(y) { }
	pt operator + (pt A) {
		return pt(x + A.x, y + A.y);
	}
	pt operator - (pt A) {
		return pt(x - A.x, y - A.y);
	}
	long long operator * (pt A) {
		return x * A.y - y * A.x;
	}
	void read() {
		int xx, yy;
		scanf("%d%d", &xx, &yy);
		x = xx;
		y = yy;
	}
	long long len2() {
		return x * x + y * y;
	}
};


int k, n;
pt a[N];
pt p[N];
int q[N];
int cur1;
int cur2;
int use[N];
int tmr;
bool flag;
bool get[K];
vector < int > who[K][N];
vector < int > add[K];


void rec(int it) {
	if (cur2 - cur1 > k - it) return;
	if (flag) return;
	if (cur1 == cur2) {
		flag = 1;
		return;
	}
	int v = q[cur1];
	cur1++;
	for (int i = 0; i < k; i++) {
		if (!get[i]) {
			get[i] = 1;			
			add[it].clear();
			for (auto id: who[i][v])
				if (use[id] != tmr) {
					use[id] = tmr;
					add[it].pb(id);
					q[cur2++] = id;
				}
			rec(it + 1);
			for (auto id: add[it]) {
				cur2--;
				use[id] = -1;
			}

			get[i] = 0;
		}
	}		
	cur1--;

}

void read() {
	scanf("%d%d", &k, &n);
	for (int i = 0; i < k; i++)
		a[i].read();
	for (int i = 0; i < n; i++)
		p[i].read();	
}

pt O;
bool cmp(pt A, pt B) {
	A = A - O;
	B = B - O;
	bool partA = (A.y < 0 || (A.y == 0 && A.x < 0));
	bool partB = (B.y < 0 || (B.y == 0 && B.x < 0));
	if (partA != partB) {
		return partA < partB;
	}
	return A * B > 0 || (A * B == 0 && A.len2() <  B.len2());
}

bool oneLine(pt A, pt B) {
	A = A - O;
	B = B - O;
	bool partA = (A.y < 0 || (A.y == 0 && A.x < 0));
	bool partB = (B.y < 0 || (B.y == 0 && B.x < 0));
	if (partA != partB) {
		return 0;
	}
	return A * B == 0;
}

void solve() {
	for (int i = 0; i < n; i++)
		p[i].id = i;
	vector < pt > b;
	for (int i = 0; i < n; i++)
		b.pb(p[i]);

	for (int i = 0; i < k; i++) {
		O = a[i]; 
		sort(b.begin(), b.end(), cmp);
		for (int j = 0; j < n; ) {
			int t = j;
			vector < int > tmp;
			for (; j < n && oneLine(b[j], b[t]); j++) {
				who[i][b[j].id] = tmp;
				if ((int)who[i][j].size() > K + 1)
					who[i][j].resize(K + 1);
				tmp.pb(b[j].id);
			}
		}
	}

	//for (int i = 0; i < k; i++, cerr << endl)
		//for (int j = 0; j < n; j++)
			//cerr << who[i][j].size() << " ";

	int sum = 0;
	for (int i = 0; i < n; i++) {
		tmr++;
		flag = 0;
		cur1 = cur2 = 0;
		q[cur2++] = i;
		use[i] = tmr;
		memset(get, 0, sizeof(get));

		rec(0);
		sum += flag;



	}
	printf("%d\n", sum);
}


int main() {
#ifdef MY_DEBUG 
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif

	if (1) {
		read();
		solve();
	}

	return 0;
}