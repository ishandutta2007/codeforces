#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<pair<int, int>, int > mp;

int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

vector<pair<int, int> > v;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string s,t;
		int a, b, c;
		cin >> s;
		int j = 1;
		while (s[j] != '+'){
			t += s[j];
			j++;
		}
		if (t.length() == 2){
			a = (t[0] - '0') * 10 + t[1] - '0';
		}
		else{
			a = t[0] - '0';
		}
		t = "";
		j++;
		while (s[j] != ')'){
			t += s[j];
			j++;
		}
		if (t.length() == 2){
			b = (t[0] - '0') * 10 + t[1] - '0';
		}
		else{
			b = t[0] - '0';
		}
		t = "";
		j++;
		j++;
		while (j<s.length()){
			t += s[j];
			j++;
		}
		if (t.length() == 2){
			c = (t[0] - '0') * 10 + t[1] - '0';
		}
		else{
			c = t[0] - '0';
		}
		//cout << a << " " << b << " " << c << endl;
		mp[make_pair((a + b) / gcd(a + b, c), c / gcd(a + b, c))]++;
		v.push_back(make_pair((a + b) / gcd(a + b, c), c / gcd(a + b, c)));
	}
	for (int i = 0; i < v.size(); i++){
		cout << mp[v[i]] << " ";
	}
	return 0;
}