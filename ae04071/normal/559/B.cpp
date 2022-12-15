
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <cstring>
#include <map>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;

string a,b;
string get(string s) {
	if(sz(s)&1) return s;
	else {
		int t=sz(s)/2;
		string a(s.begin(),s.begin()+t),b(s.begin()+t,s.begin()+t*2);
		a=get(a); b=get(b);
		if(a>b) swap(a,b);
		return a+b;
	}
}
int main() {
	cin >> a >> b;

	a=get(a); b=get(b);
	if(a==b) puts("YES");
	else puts("NO");

	return 0;
}