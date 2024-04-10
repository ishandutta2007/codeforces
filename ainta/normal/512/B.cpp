#include<stdio.h>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
map<int, int>Map;
set<int>Set;
int n, L[310], C[310];
int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}
int main(){
	int i, j, x, t, y, ty;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", &L[i]);
	for (i = 1; i <= n; i++)scanf("%d", &C[i]);
	Set.insert(0);
	set<int>::iterator it;
	for (i = 1; i <= n; i++){
		for (it = Set.begin(); it != Set.end(); it++){
			x = *it;
			t = gcd(x, L[i]);
			y = Map[t], ty = Map[x];
			if (!y)Set.insert(t);
			if (!y || y > ty + C[i]) Map[t] = ty + C[i];			
		}
	}
	if (Map[1] == 0){
		printf("-1\n");
	}
	else printf("%d\n", Map[1]);
}