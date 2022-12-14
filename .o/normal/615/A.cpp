#include <bits/stdc++.h>
using namespace std;

set<int> s;
int main() {
	int n, m;scanf("%d%d",&n,&m);
	while(n--) {
		int x;scanf("%d",&x);
		while(x--) {int b;scanf("%d",&b);s.insert(b);}
	}
	puts(s.size() == m ? "YES" : "NO");
	return 0;
}