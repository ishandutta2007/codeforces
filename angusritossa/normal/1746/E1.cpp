#include <bits/stdc++.h>
using namespace std;
bool getRes() {
	char inp[20];
	scanf(" %s", inp);
	return inp[0] == 'Y';
}
vector<int> add(vector<int> a, vector<int> b) {
	vector<int> res = a;
	for (auto i : b) res.push_back(i);
	return res;
}
bool query(vector<int> a) {
	printf("? %lu ", a.size());
	for (auto i : a) printf("%d ", i);
	printf("\n");
	fflush(stdout);
	return getRes();
}
void solve(vector<int> couldBe) {
	if (couldBe.size() <= 2) {
		for (auto a : couldBe) {
			printf("! %d\n", a);
			fflush(stdout);
			char inp[20];
			scanf(" %s", inp);
			if (inp[1] == ')') exit(0);
		}
	} else if (couldBe.size() == 3) {
		printf("? 1 %d\n", couldBe[1]);
		fflush(stdout);
		bool res1 = getRes();
		printf("? 1 %d\n", couldBe[0]);
		fflush(stdout);
		bool res2 = getRes();
		printf("? 1 %d\n", couldBe[0]);
		fflush(stdout);
		bool res3 = getRes();
		printf("? 1 %d\n", couldBe[2]);
		fflush(stdout);
		bool res4 = getRes();
		if (res2 && res3) solve({couldBe[0]});
		if (!res2 && !res3) solve({couldBe[1], couldBe[2]});
		if (res2 && res1) solve({couldBe[0], couldBe[1]});
		if (res2 && !res1) solve({couldBe[0], couldBe[2]});
		if (res3 && res4) solve({couldBe[0], couldBe[2]});
		if (res3 && !res4) solve({couldBe[0], couldBe[1]});
	} else {
		vector<int> a, b, c, d;
		for (int i = 0; i < couldBe.size(); i++) {
			if (i%4 == 0) {
				a.push_back(couldBe[i]);
			} else if (i%4 == 1) {
				b.push_back(couldBe[i]);
			} else if (i%4 == 2) {
				c.push_back(couldBe[i]);
			} else {
				d.push_back(couldBe[i]);
			}
		}
		bool res1 = query(add(a, b));
		bool res2 = query(add(b, c));
		if (res1 && res2) {
			solve(add(a, add(b, c)));
		}
		if (!res1 && !res2) {
			solve(add(a, add(c, d)));
		}
		if (res1 && !res2) {
			solve(add(a, add(b, d)));
		}
		if (!res1 && res2) {
			solve(add(b, add(c, d)));
		}
	}
}
int main() {
	int x;
	scanf("%d", &x);
	vector<int> v;
	for (int i = 1; i <= x; i++) v.push_back(i);
	solve(v);
}