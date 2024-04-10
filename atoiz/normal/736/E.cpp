#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct score
{
	int i, val;

	bool operator< (score& sc) { return val > sc.val; }
};

int n, m, average, cur_total;
vector<score> scores;
vector< vector<char> > scoreboard;
bool possible = true;

void gen_scoreboard()
{
	scoreboard = vector< vector<char> >(m);
	for (int i = 0; i < m; ++i) {
		scoreboard[i] = vector<char>(m);
		for (int j = 0; j < m; ++j) {
			scoreboard[i][j] = 'D';
		}
		scoreboard[i][i] = 'X';
	}
}

void input()
{
	cin >> m >> n;
	average = m - 1;
	cur_total = 0;

	scores = vector<score>(m);
	for (int i = 0; i < m; ++i) scores[i].i = i;

	for (int i = 0; i < n; ++i) {
		cin >> scores[i].val;
		scores[i].val -= average;
		cur_total -= scores[i].val;
	}

	if (scores[n-1].val * (m - n) < cur_total) {
		possible = false;
		return;
	}

	for (int i = n; i < m; ++i) {
		scores[i].val = ceil(double(cur_total) / (m - i));
		cur_total -= scores[i].val;
	}

	gen_scoreboard();
}

void print_scoreboard()
{
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << scoreboard[i][j];
		}
		cout << endl;
	}
}

void make_wl(int win, int lose)
{
	--scores[win].val;
	++scores[lose].val;
	scoreboard[ scores[win].i ][ scores[lose].i ] = 'W';
	scoreboard[ scores[lose].i ][ scores[win].i ] = 'L';
}

int index_of(int from, int to, int idx)
{
	for (int i = from; i <= to; ++i)
		if (scores[i].i == idx) return i;
	return -1;
}

bool solve()
{
	if (!possible) return false;

	for (int win = 0; scores[win].val > 0; ++win) {
		for (int lose = m - 1; lose > win && scores[win].val > 0; --lose) {
			make_wl(win, lose);
		}
		if (scores[win].val > 0) {
			return false;
		}

		if (win != scores.size() - 1) {
			sort(scores.begin() + win + 1, scores.end());
			int idx = index_of(win + 1, scores.size() - 1, scores[win].i + 1);
			score tmp = scores[idx];
			scores[idx] = scores[win + 1];
			scores[win + 1] = tmp;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	input();
	if (solve()) {
		cout << "yes" << endl;
		print_scoreboard();
	} else cout << "no" << endl;
}