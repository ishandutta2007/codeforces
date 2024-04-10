#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <unordered_set>

using namespace std;

const int maxn = 2e3 + 100;
const int base = 37;
int fi[maxn], st[maxn];
unordered_set <long long> myset;
long long tav[maxn], hsh[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	string s, a, b;
	cin >> s >> a >> b;
	tav[0] = 1;
	for (int i = 1; i <= 2000; i++)
		tav[i] = tav[i - 1] * base;
	hsh[0] = s[0] - 'a' + 1;
	for (int i = 1; i < s.size(); i++)
		hsh[i] = hsh[i - 1] * base + s[i] - 'a' + 1;
	if (a.size() <= s.size()){
		for (int i = 0; i < s.size() - a.size() + 1; i++)
			if (s.substr(i, a.size()) == a)
				st[i] = true;
	}
	else
		return cout << 0, 0;
	if (b.size() <= s.size()){
		for (int i = 0; i < s.size() - b.size() + 1; i++)
			if (s.substr(i, b.size()) == b)
				fi[i] = true;
	}
	else
		return cout << 0, 0;

	for (int i = 0; i < s.size() - a.size() + 1; i++){
		if (st[i] == false)
			continue;
		for (int j = i; j < s.size() - b.size() + 1; j++){
			if (fi[j] == false)
				continue;
			if (j + b.size() >= i + a.size()){
				int len = j + b.size() - 1;
				myset.insert(hsh[len] - hsh[i] * tav[len - i]);
			}
		}
	}
//	for (set<string>::iterator it = myset.begin(); it != myset.end(); it ++)
//		cout << *it << " ";
	cout << myset.size() << endl;
}