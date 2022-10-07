#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
int n;
std :: vector< std :: pair<int, int> > a, b;
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i){
		int x = read(), y = read();
		if (x > y) a.push_back(std :: make_pair(x, i));
		else b.push_back(std :: make_pair(-y, i));
	}
	if (a.size() > b.size()){
		std :: sort(a.begin(), a.end());
		printf("%d\n", a.size());
		for (auto u : a) printf("%d ", u.second);
	}
	else{
		std :: sort(b.begin(), b.end());
		printf("%d\n", b.size());
		for (auto u : b) printf("%d ", u.second);
	}
}