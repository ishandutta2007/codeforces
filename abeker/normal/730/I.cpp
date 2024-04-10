#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 3005;

struct student {
	int a, b, id;
	bool operator <(const student &rhs) const {
		if (a != rhs.a) return a > rhs.a;
		if (b != rhs.b) return b > rhs.b;
		return id > rhs.id;
	}
};

int N, P, S;
student s[MAXN];
bool bio[MAXN];

void load() {
	scanf("%d%d%d", &N, &P, &S);
	for (int i = 0; i < N; i++)
		scanf("%d", &s[i].a);
	for (int i = 0; i < N; i++)
		scanf("%d", &s[i].b);
}

void norm(vector <pii> &v) {
	sort(v.begin(), v.end(), greater <pii> ());
	for (int i = 1; i < v.size(); i++)
		v[i].first += v[i - 1].first;
}

void output(const vector <int> &v) {
	for (auto it : v)
		printf("%d ", ++it);
	puts("");
}

void solve() {
	for (int i = 0; i < N; i++)
		s[i].id = i;
		
	sort(s, s + N);
	
	int sum = 0, sol = 0;
	vector <int> x, y;
	for (int i = 1; i <= N; i++) {
		sum += s[i - 1].a;
		vector <pii> pref, suff;
		for (int j = 0; j < i; j++)
			pref.push_back({s[j].b - s[j].a, s[j].id});
		for (int j = i; j < N; j++)
			suff.push_back({s[j].b, s[j].id});
		norm(pref);
		norm(suff);
		
		int rest = i - P;
		if (rest < 0 || S - rest > suff.size() || rest > S) 
			continue;
		int tmp = sum + (rest ? pref[rest - 1].first : 0) + (S - rest ? suff[S - rest - 1].first : 0);
		if (tmp > sol) {
			sol = tmp;
			x.clear();
			y.clear();
			for (int j = 0; j < rest; j++)
				y.push_back(pref[j].second);
			for (int j = 0; j < S - rest; j++)
				y.push_back(suff[j].second);
			memset(bio, false, sizeof bio);
			for (auto it : y)
				bio[it] = true;
			for (int j = 0; j < i; j++)
				if (!bio[s[j].id])
					x.push_back(s[j].id);
		}
	}
	
	printf("%d\n", sol);
	output(x);
	output(y);
}

int main() {
	load();
	solve();
	return 0;
}