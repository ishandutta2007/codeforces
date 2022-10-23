# include <bits/stdc++.h>
# define ll long long
using namespace std;
int T, n, k;
bool solve(){
	if (k % 3 != 0) return n % 3 != 0;
	else return n % (k + 1) == k || n % (k + 1) % 3 != 0;
}
int main(){
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &k);
		if (solve()) printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}