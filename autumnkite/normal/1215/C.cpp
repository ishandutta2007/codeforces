#include <cstdio>
#include <algorithm>
#include <vector>
#define N 200005
int n;
char s[N], t[N];
std :: vector< std :: pair<int, int> > ans;
int main(){
	scanf("%d%s%s", &n, s + 1, t + 1);
	int lst1 = 0, lst2 = 0;
	for (register int i = 1; i <= n; ++i)
		if (s[i] == 'a' && t[i] == 'b')
			if (lst1) ans.push_back(std :: make_pair(lst1, i)), lst1 = 0;
			else lst1 = i;
		else if (s[i] == 'b' && t[i] == 'a')
			if (lst2) ans.push_back(std :: make_pair(lst2, i)), lst2 = 0;
			else lst2 = i;
	if (lst1 && lst2)
		ans.push_back(std :: make_pair(lst1, lst1)), ans.push_back(std :: make_pair(lst1, lst2)), lst1 = lst2 = 0;
	if (lst1 || lst2) return puts("-1"), 0;
	printf("%d\n", ans.size());
	for (auto v : ans) printf("%d %d\n", v.first, v.second);
}