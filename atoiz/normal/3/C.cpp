#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int MAX = 100000, INF = 1000000;

struct State
{
	int idx = -1, a[3][3], turn;
	int getIdx()
	{
        if (idx < 0) {
            idx = 0;
            for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) idx = idx * 3 + a[i][j];
            idx = idx * 2 + turn - 1;
        }
        return idx;
	}

	int getWinner()
	{
        for (int i = 0; i < 3; ++i) if (a[i][0] && a[i][0] == a[i][1] && a[i][0] == a[i][2]) return a[i][0];
        for (int j = 0; j < 3; ++j) if (a[0][j] && a[0][j] == a[1][j] && a[0][j] == a[2][j]) return a[0][j];
        if (a[0][0] == a[1][1] && a[0][0] == a[2][2] && a[0][0]) return a[0][0];
        if (a[0][2] == a[1][1] && a[0][2] == a[2][0] && a[0][2]) return a[0][2];
        for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) if (!a[i][j]) return -1;
        return 0;
	}
} states[MAX];

int moves[MAX], winner[MAX];

void backtrack(int idx)
{
    if (states[idx].getWinner() >= 0) {
        moves[idx] = 0;
        winner[idx] = states[idx].getWinner();
//		cerr << winner[idx] << endl << endl;
        return;
    }

    moves[idx] = -1, winner[idx] = -1;
    State cur = states[idx];
//	for (int i = 0; i < 3; ++i) { for (int j = 0; j < 3; ++j) cerr << cur.a[i][j]; cerr << endl; }
    int turn = cur.turn;
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) if (!cur.a[i][j]) {
        cur.a[i][j] = turn;
		cur.turn = 3 - turn;
        cur.idx = -1; int nxt = cur.getIdx();
        if (moves[nxt] < 0) {
			states[nxt] = cur;
            backtrack(nxt);
        }
        cur.a[i][j] = 0;
		cur.turn = turn;

        if (winner[idx] == turn) {
			if (winner[nxt] == winner[idx]) moves[idx] = min(moves[idx], moves[nxt] + 1);
        } else if (winner[nxt] == turn) {
			winner[idx] = winner[nxt];
			moves[idx] = moves[nxt] + 1;
        } else if (winner[idx] == 0) {
			if (winner[nxt] == winner[idx]) moves[idx] = min(moves[idx], moves[nxt] + 1);
        } else if (winner[nxt] == 0) {
			winner[idx] = winner[nxt];
			moves[idx] = moves[nxt] + 1;
        } else {
			winner[idx] = winner[nxt];
			moves[idx] = max(moves[idx], moves[nxt] + 1);
        }
    }
}

int main()
{
	fill_n(moves, MAX, -1);
    State bg;
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) bg.a[i][j] = 0;
    bg.turn = 1;
    states[bg.getIdx()] = bg;
	backtrack(bg.getIdx());

	int tests = 1;
	while (tests--) {
        State cur;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
            char ch;
            cin >> ch;
            if (ch == 'X') ++cnt1, cur.a[i][j] = 1;
            else if (ch == '0') ++cnt2, cur.a[i][j] = 2;
            else cur.a[i][j] = 0;
        }
        cur.turn = (cnt1 == cnt2) ? 1 : 2;

        if (moves[cur.getIdx()] < 0) cout << "illegal\n";
        else if (moves[cur.getIdx()] == 0) {
            if (winner[cur.getIdx()] == 0) cout << "draw\n";
            else if (winner[cur.getIdx()] == 1) cout << "the first player won\n";
            else if (winner[cur.getIdx()] == 2) cout << "the second player won\n";
        }
        else {
            cout << (cur.turn == 1 ? "first\n" : "second\n");
        }
	}
}