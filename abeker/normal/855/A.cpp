#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

map <string, bool> bio;

int main() {
	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		puts(bio[s] ? "YES" : "NO");
		bio[s] = true;
	}
	return 0;
}