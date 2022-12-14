#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <cmath>
#include <queue>
#include <fstream>
#include <stack>

#define F first
#define S second
#define PB push_back
using namespace std;

map <char, vector <char> > v;

int main(){
	ios_base::sync_with_stdio(false);
	string a, b, txt;
	cin >> a >> b >> txt;
	for (int i = 0; i < a.size(); i++){
		v[a[i]].push_back(b[i]);
		char cap = a[i] - 'a' + 'A';
		char des = b[i] - 'a' + 'A';
		v[cap].push_back(des);
	}
	for (int i = 0; i < txt.size(); i++){
		if (txt[i] - '0' < 10)
			cout << txt[i];
		else
			cout << v[txt[i]][0];
	}
}