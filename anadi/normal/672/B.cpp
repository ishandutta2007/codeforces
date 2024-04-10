#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;

#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

const LL MX = 1e9 + 7LL;
const LL INF = 1e9 + 9LL;
const int mxn = 2e5 + 7;

int n;
char word[30];

int main(){
	scanf("%d", &n);
	if(n > 26){
		puts("-1");
		return 0;
	}
	
	scanf("%s", word + 1);
	sort(word + 1, word + n + 1);
	
	int ile = 0;
	for(int i = 2; i <= n; ++i)
		if(word[i] == word[i - 1])
			++ile;
	
	printf("%d\n", ile);
	return 0;
}