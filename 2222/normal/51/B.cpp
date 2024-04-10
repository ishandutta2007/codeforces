#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

string s;

vector <int> asnwer;

int i;

bool expect(const char *q) {
	for (int j = i; *q; ++i, ++q)
		if (s[i] != *q) {
			i = j;
			return false;
		}
	return true;
}

void parseTable() {
	if (!expect("<table>")) return;
	int res = 0;
	for (; expect("<tr>"); ) {
		for (; expect("<td>"); res += expect("</td>"))
			parseTable();
		expect("</tr>");
	}
	expect("</table>");
	asnwer.pb(res);
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	for (string l; getline(cin, l); s += l);
	parseTable();
	sort(all(asnwer));
	REP (i, sz(asnwer)) cout << asnwer[i] << ' ';
	cout << endl;
	return 0;
}