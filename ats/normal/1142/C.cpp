#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
//f[j](x) = a[j]x + b[j]aj
//x
template<typename T> class CHT
{
private:
	using ptt = pair<T, T>;
	bool check(ptt l1, ptt l2, ptt l3) {
		return (l2.first - l1.first)*(l3.second - l2.second) >= (l2.second - l1.second)*(l3.first - l2.first);
	}
	T f(int i, T x) {
		return lines[i].first * x + lines[i].second;
	}
public:
	vector<ptt> lines;
	int head;
	CHT() : head(0) {};
	void add(T a, T b) {
		ptt line(a, b);
		while ((int)lines.size() - head >= 2 && check(*(lines.end() - 2), lines.back(), line)) {
			lines.pop_back();
		}
		lines.emplace_back(line);
	}
	T get(T x) {
		while ((int)lines.size() - head >= 2 && f(head, x) >= f(head + 1, x)) {
			head++;
		}
		return f(head, x);
		// int low = -1, high = lines.size() - 1;
		// while (high - low > 1) {
		// 	int mid = (high + low) / 2;
		//     if(f(mid, x) >= f(mid+1, x)){
		//         low = mid;
		//     }else{
		//         high = mid;
		//     }
		// }
		// return f(high, x);
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<pair<int, int> > A(N);
	int res = 0;
	int x, y;
	map<int, int> mn;
	//map<int, int> cnt;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		A[i] = { -x, -x * x + y };

		if (mn.count(A[i].first) == 0) {
			mn[A[i].first] = A[i].second;
		}
		else {
			mn[A[i].first] = max(mn[A[i].first], A[i].second);
		}
		//cnt[A[i].first]++;
	}
	sort(A.begin(), A.end());
	CHT<int> cht;
	for (auto i : mn) {
		cht.add(i.first, i.second);
	}
	/*int tot = 0;
	int sofar = 0;
	for (auto i : cnt) {
		tot += sofar * i.second;
		sofar += i.second;
	}

	cerr << tot << endl;

*/
	res = (int)cht.lines.size() - 1;
	/*for (auto p : cht.lines) {
		cerr << p.first << " " << p.second << endl;
	}*/

	cout << res << endl;
}