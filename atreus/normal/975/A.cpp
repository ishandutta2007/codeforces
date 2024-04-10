#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 100;
int a[100];
set <string> se;
string p (string s){
	memset (a, 0, sizeof a);
	for (int i = 0; i < s.size(); i++)
		a[s[i] - 'a'] ++;
	string k;
	for (int i = 0; i < 26; i++)
		if (a[i] > 0)
			k += i + 'a';
	return k;
}

int main (){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		s = p (s);
		se.insert (s);
	}
	cout << se.size() << endl;
}