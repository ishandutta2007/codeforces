#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
char s[N];
int n, q, a[N][26], b[26];
int main(){
	scanf("%s", s);
	n = strlen(s);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 26; j++)
			a[i][j] = a[i - 1][j];
		a[i][s[i - 1] - 'a']++;	
	}

	scanf("%d", &q);
	while(q--){
		int l, r;
		scanf("%d%d", &l, &r);
		int cnt = 0;
		for(int i = 0; i < 26; i++){
			b[i] = a[r][i] - a[l - 1][i];
			if(b[i] > 0)
				cnt++;
		}
		if(l == r || cnt > 2 || (cnt == 2 && s[l - 1] != s[r - 1]))
			printf("Yes\n");
		else
			printf("No\n");		
	}
}