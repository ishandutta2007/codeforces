/*input
8 8
2 3 1 8
 
*/
 
#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
 
using namespace std;
 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define x first
#define y second
 
// start of code
 
const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2}, dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
const int MAXN = 1002;
const bool WHITE = 0, BLACK = 1;
int N, M;
pii W, B, F;
int dist[MAXN][MAXN], dist1[MAXN][MAXN], fr, rr;
pii last[MAXN][MAXN], last1[MAXN][MAXN], qu[MAXN * MAXN];
bool mouse, winner, finalPhase = 0, sprint = 0;
 
void whiteMove()
{
	if (winner == BLACK) {
		cin >> W.x >> W.y;
		return;
	}

	if (sprint) {
		W = last1[W.x][W.y];
		cout << W.x << ' ' << W.y << endl;
		if (!dist1[W.x][W.y]) exit(0);
		return;
	}
 
	FOR(d, 0, 7) {
		if (W.x + dx[d] == B.x && W.y + dy[d] == B.y) {
			cout << B.x << ' ' << B.y << endl;
			exit(0);
		}
	}
 
 	if (W == F && mouse != winner) finalPhase = 1;
	if (finalPhase) {
		assert(mouse == BLACK);
		if (W == F) W = pii(N / 2, M / 2 - 2);
		else if (W == pii(N / 2, M / 2 - 2)) W = pii(N / 2 + 2, M / 2 - 1);
		else W = pii(N / 2, M / 2);
 
		cout << W.x << ' ' << W.y << endl;
		if (W == pii(N / 2, M / 2)) exit(0);
		return;
	}
 
	W = last[W.x][W.y];
	cout << W.x << ' ' << W.y << endl;
	if (W == F) {
		if (mouse != winner) finalPhase = 1;
		else exit(0);
	}
}
 
void blackMove()
{
	if (winner == WHITE) {
		cin >> B.x >> B.y;
		return;
	}

	if (sprint) {
		B = last1[B.x][B.y];
		cout << B.x << ' ' << B.y << endl;
		if (!dist1[B.x][B.y]) exit(0);
		return;
	}
 
	FOR(d, 0, 7) {
		if (W.x + dx[d] == B.x && W.y + dy[d] == B.y) {
			cout << W.x << ' ' << W.y << endl;
			exit(0);
		}
	}
 
 	if (B == F && mouse != winner) finalPhase = 1;
	if (finalPhase) {
		assert(mouse == WHITE);
		if (B == F) B = pii(N / 2 + 1, M / 2 - 2);
		else if (B == pii(N / 2 + 1, M / 2 - 2)) B = pii(N / 2 - 1, M / 2 - 1);
		else B = pii(N / 2 + 1, M / 2);
 
		cout << B.x << ' ' << B.y << endl;
		if (B == pii(N / 2 + 1, M / 2)) exit(0);
		return;
	}

	B = last[B.x][B.y];
	cout << B.x << ' ' << B.y << endl;
	if (B == F) {
		if (mouse != winner) finalPhase = 1;
		else exit(0);
	}
}
 
signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	cin >> N >> M >> W.x >> W.y >> B.x >> B.y;
	mouse = ((W.x ^ W.y ^ B.x ^ B.y) & 1) ? BLACK : WHITE;
	F = pii(N / 2 + mouse, M / 2);
 
	FOR(i, 1, N) FOR(j, 1, M) dist[i][j] = dist1[i][j] = MAXN * MAXN;
	dist[F.x][F.y] = 0, dist1[N + 1 - F.x][F.y] = 0;
 
	fr = rr = 0;
	qu[++rr] = F;
	while (fr < rr) {
		pii cur = qu[++fr];
		FOR(d, 0, 7) {
			int x = cur.x + dx[d], y = cur.y + dy[d];
			if (x <= 0 || x > N || y <= 0 || y > M) continue;
			if (dist[x][y] <= dist[cur.x][cur.y] + 1) continue;
			dist[x][y] = dist[cur.x][cur.y] + 1;
			last[x][y] = cur;
			qu[++rr] = pii(x, y);
		}
	}
 
	fr = rr = 0;
	qu[++rr] = pii(N + 1 - F.x, F.y);
	while (fr < rr) {
		pii cur = qu[++fr];
		FOR(d, 0, 7) {
			int x = cur.x + dx[d], y = cur.y + dy[d];
			if (x <= 0 || x > N || y <= 0 || y > M) continue;
			if (dist1[x][y] <= dist1[cur.x][cur.y] + 1) continue;
			dist1[x][y] = dist1[cur.x][cur.y] + 1;
			last1[x][y] = cur;
			qu[++rr] = pii(x, y);
		}
	}

	if (mouse == WHITE) {
		if (dist[W.x][W.y] > dist1[B.x][B.y]) {
			winner = BLACK;
			sprint = 1;
		} else {
			winner = (dist[W.x][W.y] < dist[B.x][B.y]) ? WHITE : BLACK;
		}
	}
	else {
		if (dist1[W.x][W.y] <= dist[B.x][B.y]) {
			winner = WHITE;
			sprint = 1;
		} else {
			winner = (dist[B.x][B.y] < dist[W.x][W.y] - 1) ? BLACK : WHITE;
		}
	}

	cout << (winner == WHITE ? "WHITE" : "BLACK") << endl;
 
	while (true) {
		whiteMove();
		blackMove();
	}
}