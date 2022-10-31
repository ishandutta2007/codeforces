#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
int X;
vector<int> pa;
vector<int> ch;
vector<int> depth;
queue<int> qu;
vector<set<int> > amari;
int sumdepth = 0;
void changeParent(int a, int b) {
	if (pa[a] != -1) {
		ch[pa[a]]--;
		//amari[depth[pa[a]]].insert(pa[a]);
		if (ch[pa[a]] == 0) {
			qu.push(pa[a]);
		}
		amari[depth[a]].erase(a);
		sumdepth -= depth[a];
	}
	pa[a] = b;
	ch[b]++;
	if (ch[b] == X) {
		amari[depth[b]].erase(b);
	}
	depth[a] = depth[b] + 1;
	amari[depth[a]].insert(a);


	sumdepth += depth[a];
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, S;
	cin >> N >> S;
	if (S < 1 + 2 * (N - 1)) {
		cout << "No" << endl;
		return 0;
	}
	int ng = 0;
	int ok = N;
	while (ok - ng > 1) {
		int m = (ok + ng) / 2;
		int mx = 1;
		int mxc = 1;
		int lev = 1;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			if (mxc == 0) {
				mx *= m;
				mxc = mx;
				lev++;
			}
			mxc--;
			ans += lev;
		}
		//cerr << m << " " << ans << endl;
		if (ans >= S) {
			ng = m;
		}
		else {
			ok = m;
		}
	}
	if (ok == 1) {
		cout << "No" << endl;
		return 0;
	}
	//cerr << ok << endl;
	X = ok;
	pa.resize(N, -1);
	ch.resize(N, 0);
	depth.resize(N, -1);
	depth[0] = 1;
	sumdepth = 1;
	amari.resize(N + 2);
	amari[1].insert(0);
	int cur = 1;
	X--;
	for (int i = 1; i < N; i++) {
		while ((int)amari[cur].size() == 0) cur++;
		int b = *amari[cur].begin();
		changeParent(i, b);
	}
	X++;
	for (int i = 0; i < N; i++) {
		amari[depth[i]].insert(i);
		if (i > 0 && ch[i] == 0)qu.push(i);
	}
	cur = 1;
	while (sumdepth > S) {
		while ((int)amari[cur].size() == 0) cur++;
		int a = qu.front(); qu.pop();
		
		if (sumdepth - depth[a] + cur + 1 <= S) {
			int b = *amari[S - sumdepth + depth[a] - 1].begin();
			changeParent(a, b);
			//cerr << a << " " << b << endl;
		}
		else {
			int b = *amari[cur].begin();
			changeParent(a, b);
			//cerr << a << " " << b << endl;
		}
	}
	//cerr << sumdepth << endl;
	cout << "Yes" << endl;
	for (int i = 1; i < N; i++) {
		if (i > 1)cout << " ";
		cout << pa[i] + 1;
	}
	cout << endl;

}