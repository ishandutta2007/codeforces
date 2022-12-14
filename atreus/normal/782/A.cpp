#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>

#define F first
#define S second

using namespace std;

const int maxn = 1e5 + 500;
bool mark[maxn];

int main (){
	int n, ans = 0, cnt = 0;
	cin >> n;
	for (int i = 1; i <= 2 * n; i++){
		int a;
		cin >> a;
		if (mark[a])
			cnt --;
		else {
			cnt ++;
			mark[a] = true;
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
}