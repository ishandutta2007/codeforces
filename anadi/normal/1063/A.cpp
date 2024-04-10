#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
char s[N];
int cnt[N];
char res[N];

int main(){
	scanf("%d", &n);
	scanf("%s", s + 1);
	
	sort(s + 1, s + n + 1);
	printf("%s\n", s + 1);
	return 0;
	
	for(int i = 1; i <= n; ++i)
		cnt[s[i] - 'a']++;
	
	int np = -1, s = 0;
	for(int i = 0; i < 26; ++i){
		s += cnt[i] - cnt[i]%2;
		if((cnt[i] & 1) && np == -1)
			np = i;
	}
	
	if(np != -1)
		++s;
	
	int cur = 0, cur2 = s;
	for(int i = 0; i < 26; ++i){
		int t = cnt[i] / 2;
		while(t--){
			res[++cur] = i + 'a';
			res[cur2--] = i + 'a';
		}
	}
	
	if(s & 1)
		res[cur2] = np + 'a';
	
	cur = s;
	for(int i = 0; i < 26; ++i)
		if(i != np && (cnt[i] & 1))
			res[++cur] = i + 'a';
	printf("%s\n", res + 1);
	return 0;
}