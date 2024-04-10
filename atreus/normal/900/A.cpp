#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n, mos = 0, man = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x, y;
		cin >> x >> y;
		if (x < 0)
			man ++;
		else
			mos ++;
	}
	if (man <= 1 || mos <= 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}