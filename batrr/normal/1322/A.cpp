#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e6 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n, ans, bal;
char s[N];
int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	for(int i = 0; i < n; i++){
		if(s[i] == '(')
			bal++;
		else
			bal--;
		if(bal < 0 || (bal == 0 && s[i] == '('))
			ans++;
	}
	if(bal != 0){
		printf("-1");
		return 0;
	}
	printf("%d", ans);
}