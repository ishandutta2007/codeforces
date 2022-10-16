#include <iostream>
#include <string>

using namespace std;

int frecv[105];

int main() {
	string str;

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; ++ i) {
		cin >> str;
		++ frecv[str.size()];
	}

	int cate_min = 0;
	int cate_max = 0;
	
	cin >> str;

	for (int i = 1; i <= 100; ++ i)
		if (i < str.size()) {
			cate_min += frecv[i];
			cate_max += frecv[i];
		}
		else if (i == str.size()) {
			cate_min ++;
			cate_max += frecv[i];
			break;
		}
	
	cate_min += ((cate_min - 1) / k) * 5;
	cate_max += ((cate_max - 1) / k) * 5;
	
	cout << cate_min << ' ' << cate_max << endl;
	return 0;
}