#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

const int maxn = 3e5 + 500;
int sum[maxn], tim[maxn];

int main() {
    ios_base::sync_with_stdio(false);
	int inx, cnt = 0;
	string s;
	cin >> s;
	if (s[0] == ')' || s[0] == '#')
		return cout << -1, 0;
	else
		sum[0] = 1;
	for (int i = 1; i < s.size(); i++){
		if (s[i] == ')')
			sum[i] = sum[i - 1] - 1;
		else if (s[i] == '(')
			sum[i] = sum[i - 1] + 1;
		else {
			cnt ++;
			inx = i;
			sum[i] = sum[i - 1] - 1;
		}
		if (sum[i] < 0)
			return cout << -1, 0;
	}
	int k = sum[inx];
	for (int i = inx; i < s.size(); i++){
		k = min(k, sum[i]);
	}
	if (sum[s.size() - 1] - k > 0)
		return cout << -1, 0;
	while (cnt > 1){
		cnt --;
		cout << 1 << endl;
	}
	cout << k + 1 << endl;
}