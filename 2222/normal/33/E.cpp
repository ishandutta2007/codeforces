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

int m, n, k, dtime[111];
string dis[111];
pii busy[4];
int freeTimePerDay;

int readTime() {
	int h, m;
	scanf("%d:%d", &h, &m);
	return h * 60 + m;
}

int duration(pii s) { return max(s.Y - s.X + 1, 0); }

pii operator & (const pii &a, const pii &b) {
	return pii(max(a.X, b.X), min(a.Y, b.Y));
}

struct stupid {
	int id, day, time, money, freetime, index;
	void read(int index) {
		this->index = index;
		string s;
		cin >> s >> day;
		time = readTime();
		cin >> money;
		id = -1;
		REP (i, m) if (s == dis[i]) id = i;
		freetime = time + freeTimePerDay * (day - 1);
		pii q(0, time - 1);
		REP (i, 4) freetime -= duration(q & busy[i]);
	}
} s[111];

bool operator < (const stupid &a, const stupid &b) { return a.freetime < b.freetime; }

int F[111][50000];

void printTime(int t) {
	int day = t / freeTimePerDay + 1;
	t -= (day - 1) * freeTimePerDay;
	cout << day << ' ';
	REP (i, 4) {
		if (busy[i].X <= t) t += duration(busy[i]);
	}
	printf("%02d:%02d", t / 60, t % 60);
}

struct task {
	int student, startTime, endTime;
	void print() {
		cout << student + 1 << ' ';
		printTime(startTime);
		cout << ' ';
		printTime(endTime);
		cout << endl;
	}
};

vector <task> ans;

int f(int i, int now) {
	if (i == n) return 0;
	int &res = F[i][now];
	if (res < 0) {
		res = f(i + 1, now);
		if (s[i].id >= 0 && now + dtime[s[i].id] <= s[i].freetime) {
			res = max(res, f(i + 1, now + dtime[s[i].id]) + s[i].money);
		}
	}
	return res;
}

void restore(int i, int now) {
	if (i == n) return;
	int res = f(i, now);
	if (res == f(i + 1, now)) restore(i + 1, now);
	else {
		ans.pb((task){s[i].index, now, now + dtime[s[i].id] - 1});
		restore(i + 1, now + dtime[s[i].id]);
	}
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> m >> n >> k;
	REP (i, m) cin >> dis[i];
	REP (i, m) cin >> dtime[i];
	freeTimePerDay = 24 * 60;
	REP (i, 4) {
		busy[i].X = readTime();
		scanf("-");
		busy[i].Y = readTime();
		freeTimePerDay -= duration(busy[i]);
	}
	REP (i, n) s[i].read(i);
	sort(s, s + n);
	CL(F, -1);
	cout << f(0, 0) << endl;
	restore(0, 0);
	cout << ans.size() << endl;
	REP (i, sz(ans)) 
		ans[i].print();
	return 0;
}