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
int num[30];

int main(){
	int n, k;
	string s;
	cin >> n >> k >> s;
	for (int i = 0; i < s.size(); i++)
		num[s[i] - 'a'] ++;
	char smll, bigg;
	for (int i = 0; i < 26; i++){
		if (num[i]){
			smll = char (i + 'a');
			break;
		}
	}
	for (int i = 25; i >= 0; i--){
		if (num[i]){
			bigg = char (i + 'a');
			break;
		}
	}
	if (k > n){
		cout << s;
		bool cur = 0;
		for (int i = 0; i < 26 and !cur; i++){
			if (num[i]){
				for (int j = 1; j <= k - n; j++)
					cout << char (i + 'a');
				cur = 1;
			}
		}
		cout << endl;
		return 0;
	}
	string a;
	bool con = 0;
	for (int i = k - 1; i >= 0; i--){
		if (con){
			a += s[i];
			continue;
		}
		if (s[i] == bigg){
			a += smll;
			continue;
		}
		for (int j = s[i] - 'a' + 1; j < 26; j++){
			if (num[j]){
				con = 1;
				a += char (j + 'a');
				break;
			}
		}
	}
	string rev;
	for (int i = a.size() - 1; i >= 0; i--)
		rev += a[i];
	cout << rev << endl;
}