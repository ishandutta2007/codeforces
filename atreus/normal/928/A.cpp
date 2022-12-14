#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define In insert
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7, maxn = 1e5 + 100;
set <char> uc;

void get_uc(){
	for (int i = 0; i < 26; i++)
		uc.insert (i + 'A');
}

string f (string s){
	for (int i = 0; i < s.size(); i++){
		if (s[i] == 'l' || s[i] == 'L')
			s[i] = '1';
		if (s[i] == 'I' || s[i] == 'i')
			s[i] = '1';
		if (s[i] == 'O' || s[i] == 'o')
			s[i] = '0';
		if (uc.find(s[i]) != uc.end())
			s[i] = s[i] - 'A' + 'a';
	}
	return s;
}

int main(){
	get_uc();
	string s;
	int n;
	cin >> s >> n;
	s = f (s);
	bool cur = 1;
	for (int i = 0; i < n; i++){
		string a;
		cin >> a;
		if (f(a) == s)
			cur = 0;
	}
	if (cur)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}