#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

string nums[26] = {"1", "12", "14", "145", "15", "124", "1245", "125", "24", "245", "13", "123", "134", "1345", "135", "1234", "12345", "1235", "234", "2345", "136", "1236", "2456", "1346", "13456", "1356"};

bool has(string s, char c) {
	for (auto x : s) if (x==c) return 1;
	return 0;
}

string det(string nu) {
	string ret = "00000";
	if (has(nu,'1')) { ret[0]++; ret[3]++; }
	if (has(nu,'2')) { ret[1]++; ret[3]++; }
	if (has(nu,'3')) { ret[2]++; ret[3]++; }
	if (has(nu,'4')) { ret[0]++; ret[4]++; }
	if (has(nu,'5')) { ret[1]++; ret[4]++; }
	if (has(nu,'6')) { ret[2]++; ret[4]++; }
	return ret;
}

int main() {
	//FOR(j,26) cout << char('a'+j) << " " << det(nums[j]) << "\n";
	int n;
	cin >> n;
	FOR(i,n) {
		string s;
		char c;
		FOR(j,5) {
			cin >> c;
			s += c;
		}
		FOR(j,26) if (det(nums[j]) == s) {
			cout << char('a'+j);
			break;
		}
	}
	cout << "\n";
	return 0;
}