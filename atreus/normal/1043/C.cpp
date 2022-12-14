#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 3e4 + 10;
const int block = 320;

int a[maxn];

int main() {
	string s;
	cin >> s;
	
	if (s.size() == 1)
		return cout << 1 << endl, 0;

	bool af = 0;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == 'b' and s[i + 1] == 'a')
			cout << 1 << " ";
		else if (s[i] == 'a' and s[i + 1] == 'b')
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}
	if (s[s.size() - 1] == 'b')
		cout << 0 << endl;
	else
		cout << 1 << endl;
}