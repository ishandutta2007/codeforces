#include <iostream>
#include <cstdio>
#include <string>
#include <set>
int n;
std::string s[200005];
std::set<std::string> S;
int main(){
	std::cin >> n;
	for (register int i = 1; i <= n; ++i) std::cin >> s[i];
	for (register int i = n; i; --i)
		if (!S.count(s[i])) std::cout << s[i] << std::endl, S.insert(s[i]);
}