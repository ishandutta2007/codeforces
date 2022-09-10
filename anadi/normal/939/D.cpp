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
const LL INF = 1e18 + 19LL;

int n;
int rep[30];
char s[2][N];

int Find(int a){
	if(a == rep[a])
		return a;
	return rep[a] = Find(rep[a]);
}

void Union(int a, int b){
	rep[Find(a)] = Find(b);
}

int main(){
	scanf("%d", &n);
	scanf("%s %s", s[0] + 1, s[1] + 1);
	
	for(int i = 0; i < 30; ++i)
		rep[i] = i;
		
	vector <pair <char, char> > res;
	for(int i = 1; i <= n; ++i)
		if(Find(s[0][i] - 'a') != Find(s[1][i] - 'a')){
			Union(s[0][i] - 'a', s[1][i] - 'a');
			res.push_back({s[0][i], s[1][i]});
		}
	
	printf("%d\n", res.size());
	for(auto v: res)
		printf("%c %c\n", v.st, v.nd);
	return 0;
}