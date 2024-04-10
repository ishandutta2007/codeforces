/*input
4
c=aa#bb
d12=c
res=c$d12
tmp=aa$c

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
#define fi first
#define se second

// start of code

const int NUM_LETTERS = 37, NUM_NAMES = (NUM_LETTERS - 11) * NUM_LETTERS * NUM_LETTERS * NUM_LETTERS, MAXN = 4006, NAME_SIZE = 4;
int letterToInt[300]; 
char intToLetter[NUM_LETTERS];
int nameToInt(string str) 
{ 
	while (SZ(str) < NAME_SIZE) str += ' ';
	int ans = 0; 
	FOR(i, 0, 3) ans = ans * NUM_LETTERS + letterToInt[(int) str[i]]; 
	return ans; 
}
string intToName(int code) 
{ 
	string str; 
	for (int _ = 0; _ < 4; ++_, code /= NUM_LETTERS) str = intToLetter[code % NUM_LETTERS] + str; 
	while (str.back() == ' ') str.pop_back();
	return str; 
}

int opToCode[300];
char codeToOp[4] = {'#', '$', '^', '&'};
#define exp expp
int n;
int nameToVar[NUM_NAMES], varToName[MAXN], exp[MAXN], ptr = 1, curName = 0;
int varOfExp[4 * MAXN * MAXN];
bool done[MAXN];
vector<string> outs;

int getExp(int i1, int i2, int op) { return i1 + MAXN * (i2 + MAXN * op); }

void add(int name) 
{ 
	nameToVar[varToName[ptr] = name] = ptr; ++ptr; 
}

void read()
{
	string line; cin >> line;

	int asgn = 0; for (; line[asgn] != '='; ++asgn);
	int opI = 0; for (; opI < SZ(line) && opToCode[(int) line[opI]] < 0; ++opI);
	// cout << line << ": ";

	if (opI == SZ(line)) {
		int lval = nameToInt(line.substr(0, asgn));
		int rval = nameToInt(line.substr(asgn + 1));

		if (!nameToVar[rval]) add(rval);
		nameToVar[lval] = nameToVar[rval];
	} else {
		int lval = nameToInt(line.substr(0, asgn));
		int val1 = nameToInt(line.substr(asgn + 1, opI - asgn - 1));
		int val2 = nameToInt(line.substr(opI + 1));

		if (!nameToVar[val1]) add(val1);
		if (!nameToVar[val2]) add(val2);

		int curExp = getExp(nameToVar[val1], nameToVar[val2], opToCode[(int) line[opI]]);
		if (varOfExp[curExp]) {
			nameToVar[lval] = varOfExp[curExp];
		} else {
			int lvar = nameToVar[lval] = ptr++;
			varOfExp[exp[lvar] = curExp] = lvar;
		}
	}
}

void declare(int var)
{
	// cout << var << ' ' << intToName(varToName[var]) << endl; 
	if (varToName[var] < 0) {
		while (nameToVar[curName]) ++curName;
		varToName[var] = curName++;
	}
	if (done[var] || !exp[var]) return;
	done[var] = 1;
	int cur = exp[var], i1, i2, op;
	i1 = cur % MAXN, cur /= MAXN, i2 = cur % MAXN, cur /= MAXN, op = cur;
	declare(i1); declare(i2);

	string str;
	str += intToName(varToName[var]);
	str += '=';
	str += intToName(varToName[i1]);
	str += codeToOp[op];
	str += intToName(varToName[i2]);
	outs.emplace_back(str);
}

signed main()
{
	// freopen("test.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	FOR(i, 0, NUM_LETTERS - 1) intToLetter[i] = -1;
	FOR(i, 0, 25) intToLetter[i] = i + 'a';
	// FOR(i, 0, 25) intToLetter[i + 26] = i + 'A';
	FOR(i, 0, 9) intToLetter[i + 26] = i + '0';
	intToLetter[36] = ' ';
	FOR(i, 0, NUM_LETTERS - 1) letterToInt[(int) intToLetter[i]] = i;
	FOR(i, 0, 299) opToCode[i] = -1; opToCode['#'] = 0, opToCode['$'] = 1, opToCode['^'] = 2, opToCode['&'] = 3;
	FOR(i, 0, MAXN - 1) varToName[i] = -1;

	cin >> n;
	FOR(_, 0, n-1) read();

	// FOR(i, 0, 10) cout << i << ": " << varToName[i] << ' ' << intToName(varToName[i]) << endl;

	// cout <<  "S" << nameToVar[nameToInt("res")] << endl;
	if (!nameToVar[nameToInt("res")] || intToName(varToName[nameToVar[nameToInt("res")]]) == "res") return cout << 0 << endl, 0;

	if (!exp[nameToVar[nameToInt("res")]]) 
		return cout << "1\nres=" << intToName(varToName[nameToVar[nameToInt("res")]]) << endl, 0;

	varToName[nameToVar[nameToInt("res")]] = nameToInt("res");

	declare(nameToVar[nameToInt("res")]);
	cout << SZ(outs) << '\n';
	FORA(x, outs) cout << x << '\n';

	return 0;
}