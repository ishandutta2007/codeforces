/*input
2
3
1 2 3 5 6 E 7
8 9 10 4 11 12 13
11
34 45 6 22 16 43 38 44 5 4 41 14 7 29 28 19 9 18 42 8 17 33 1
E 15 40 36 31 24 10 2 21 11 32 23 30 27 35 25 13 12 39 37 26 20 3

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
#include <utility>
#include <tuple>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>
#include <functional>

using namespace std;

// start of code

int K;
vector<int> A;
vector<vector<int>> table;
string finalSequence;

void rotateForward()
{
	// cout << "rotate forward" << endl;
	if (!finalSequence.empty() && finalSequence.back() == 'B') finalSequence.pop_back();
	else finalSequence += "F";

	for (int i = 4 * K; i > 0; --i) {
		swap(A[i - 1], A[i]);
	}
}

void rotateBackward()
{
	// cout << "rotate backward" << endl;
	if (!finalSequence.empty() && finalSequence.back() == 'F') finalSequence.pop_back();
	else finalSequence += "B";

	for (int i = 1; i <= 4 * K; ++i) {
		swap(A[i - 1], A[i]);
	}
}

void simpleJump() // jump first value pass 2 positions
{ 
	finalSequence += "JFF";
	for (int i = 1; i <= 2; ++i) {
		swap(A[i - 1], A[i]);
	}
}

void customJump(int idx) // jump (idx)`s value pass 2 positions
{
	for (int i = 0; i < idx; ++i) rotateBackward();
	simpleJump();
	while (A[0] != 1) rotateForward();
}

void readFromInput()
{
	cin >> K;
	finalSequence = "";
	table.assign(2, vector<int>(2 * K + 1));
	for (auto &vec : table) for (auto &i : vec) {
		string str;
		cin >> str;
		if (str == "E") i = 0;
		else i = stoi(str);
	}
}

void backToCorner()
{
	for (int row = 0; row < 2; ++row) {
		for (int col = 0; col < 2 * K; ++col) {
			if (table[row][col] == 0) {
				finalSequence += 'r';
				swap(table[row][col], table[row][col + 1]);
			}
		}
	}

	if (table[0][2 * K] == 0) {
		finalSequence += 'd';
		swap(table[0][2 * K], table[1][2 * K]);
	}
}

void relabel()
{
	for (auto &vec : table) for (int &i : vec) {
		if (i >= 2 * K + 2) i = 4 * K + 2 - i;
		else if (i >= 1) i += 2 * K;
	}
}

void convertToA()
{
	A.resize(4 * K + 1);
	for (int i = 0; i <= 2 * K; ++i) {
		A[2 * K + i] = table[0][i];
	}
	for (int i = 0; i < 2 * K; ++i) {
		A[2 * K - 1 - i] = table[1][i];
	}
	assert(table[1][2 * K] == 0);
}

string forwardDefinition()
{
	return "u" + string(2 * K, 'l') + "d" + string(2 * K, 'r');
}

string backwardDefinition()
{
	return string(2 * K, 'l') + "u" + string(2 * K, 'r') + "d";
}

string jumpKDefinition()
{
	return string(K + 1, 'B') + (string(K, 'l') + "u" + string(K, 'r') + "d") + string(K + 1, 'F');
}

string jumpDefinition()
{
	string def = "";
	def += "B";
	def += jumpKDefinition();
	def += jumpKDefinition();
	def += "F";
	for (int i = 0; i < K * 2; ++i) def += jumpKDefinition();
	def += "B";
	for (int i = 0; i < K * 2; ++i) def += jumpKDefinition();
	def += "F";

	// dirty optimization
	assert(def.back() == 'F'); def.pop_back();
	assert(def.back() == 'F'); def.pop_back();

	// cout << "SZ " << def.size() << endl;
	return def;

	// return "B" + jumpKDefinition() + jumpKDefinition() + "F" + string(K, jumpKDefinition().c_str()) + "B" + string(K, jumpKDefinition().c_str()) + "F";
}

void trim()
{
	string copySequence = finalSequence + "$";
	finalSequence = "";

	char curChar = '?';
	int curCount = 0;
	for (char ch : copySequence) {
		if (curChar == ch) {
			++curCount;
			if (curCount == 10) {
				if (ch == 'F') finalSequence += "X", curCount = 0;
				else if (ch == 'B') finalSequence += "Y", curCount = 0;
				else if (ch == 'J') finalSequence += "Z", curCount = 0;
			}
		} else {
			finalSequence += string(curCount, curChar);
			curChar = ch;
			curCount = 1;
		}
	}
}

void outputSuccess()
{
	trim();
	// cout <<	finalSequence.size() << ' ' << jumpDefinition().size() << endl;
	cout << "SURGERY COMPLETE" << '\n';
	cout << finalSequence << '\n';
	cout << "F " << forwardDefinition() << '\n';
	cout << "B " << backwardDefinition() << '\n';
	cout << "J " << jumpDefinition() << '\n';
	cout << "X FFFFFFFFFF" << '\n';
	cout << "Y BBBBBBBBBB" << '\n';
	cout << "Z JJJJJJJJJJ" << '\n';
	cout << "DONE" << '\n';
}

void outputFailure()
{
	cout << "SURGERY FAILED" << '\n';
}

void log() // for debugging purposes
{
	cout << "--------------------------------" << endl;
	cout << "A = ";
	for (int x : A) cout << x << ' ';
	cout << endl;
	return;
	cout << "table: " << endl;
	for (int i = 2 * K; i <= 4 * K; ++i) {
		cout << A[i] << ' ';
	}
	cout << '\n';

	for (int i = 2 * K - 1; i >= 0; --i) {
		cout << A[i] << ' ';
	}
	cout << 'E';
	cout << '\n';

	cout << "current sequence = " << finalSequence << endl;
	cout << "--------------------------------" << endl;
	cout << endl;
}

void solve()
{
	readFromInput();
	backToCorner();
	relabel();
	convertToA();
	while (A[0] != 1) rotateForward();

	for (int noFixed = 1; noFixed <= 4 * K - 2; ++noFixed) {
		int nextValue = noFixed + 1;

		int curPos = (int) (find(A.begin(), A.end(), nextValue) - A.begin());

		while (curPos < noFixed || curPos > noFixed + 2) {
			// log();
			customJump(curPos);
			curPos = (int) (find(A.begin(), A.end(), nextValue) - A.begin());
		}

		while (A[noFixed] != nextValue) {
			// log();
			customJump(noFixed);
		}
	}

	bool isSorted = is_sorted(A.begin(), A.end());
	if (isSorted) {
		outputSuccess();
	} else {
		outputFailure();
	}
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tests;
	cin >> tests;
	while (tests--) {
		solve();
	}

	return 0;
}