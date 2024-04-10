#include <iostream>
#include <iomanip>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const int N = 200 * 1000 + 5;

pair<pair <int, int>, string> a[N];
map <string, int> mp;
int b[N];
vector <char> vec;
deque <int> q;
bool mark[N];
char c[55][55];
string s[N];



int main() {
	int n;
	cin >> n;
	mp["rat"] = 1, mp["child"] = 2, mp["woman"] = 2, mp["man"] = 3, mp["captain"] = 4;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> a[i].second >> s;
		a[i].first.second = i;
		a[i].first.first = mp[s];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		cout << a[i].second << endl;
	}
}