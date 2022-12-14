#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
const int maxn = 1e5 + 100;

int main (){
	int n;
	string s;
	cin >> n >> s;
	int cnt0 = 0, cnt1 = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '1')
			cnt1 ++;
		else
			cnt0 ++;
	}
	cout << abs (cnt1 - cnt0) << endl;
}