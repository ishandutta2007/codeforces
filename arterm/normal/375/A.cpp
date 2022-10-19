#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int rem(const string &a){
	int s = 0;
	for (int i = a.size() - 1, j = 1; i >= 0; --i,j = (10 * j) % 7){
		s = (s + (a[i]-'0') * j) % 7;
	}
	return s;
}


int main(){
#ifdef TROLL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); ++i){
		if (s[i] == '1')
			swap(s[i], s[0]);
		if (s[i] == '6')
			swap(s[i], s[1]);
		if (s[i] == '8')
			swap(s[i], s[2]);
		if (s[i] == '9')
			swap(s[i], s[3]);
	}

	while (rem(s) != 0)
		next_permutation(s.begin(), s.begin() + 4);

	cout << s << "\n";


	return 0;
}