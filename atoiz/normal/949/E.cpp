#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<int> bt(int bit, vector<int> prea)
{
	sort(prea.begin(), prea.end());
	prea.erase(unique(prea.begin(), prea.end()), prea.end());
	bool full1 = 1, fullm1 = 1, full0 = 1;
	vector<int> a;
	for (int i : prea) {
        full1 &= (i == 1);
        fullm1 &= (i == -1);
        full0 &= (i % 2 == 0);
        if (i != 0) a.push_back(i);
	}
	if (a.empty()) return {};
    if (full1) return {1 << bit};
    if (fullm1) return {-(1 << bit)};
    if (full0) {
        vector<int> newa;
        for (int i = 0; i < a.size(); ++i) {
            newa.push_back(a[i] / 2);
        }
        return bt(bit + 1, newa);
    }

    // 1
    vector<int> newa;
    for (int i = 0; i < a.size(); ++i) {
		if (a[i] % 2 == 0) {
			if (a[i] != 0) newa.push_back(a[i] / 2);
		} else {
			if (a[i] != 1) newa.push_back((a[i] - 1) / 2);
		}
    }
    vector<int> ans1 = bt(bit + 1, newa);
    ans1.push_back((1 << bit));

    // -1
    newa.clear();
    for (int i = 0; i < a.size(); ++i) {
		if (a[i] % 2 == 0) {
			if (a[i] != 0) newa.push_back(a[i] / 2);
		} else {
			if (a[i] != -1) newa.push_back((a[i] + 1) / 2);
		}
    }
    vector<int> ans2 = bt(bit + 1, newa);
    ans2.push_back(-(1 << bit));

    if (ans1.size() < ans2.size()) return ans1;
    else return ans2;
}

int main()
{
    int n; scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    vector<int> ans = bt(0, a);
    printf("%d\n", ans.size());
    for (int i : ans) printf("%d ", i); printf("\n");
}