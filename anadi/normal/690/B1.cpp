#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
typedef long long int LL;

#define PII pair <int, int>
#define PLL pair <LL, LL>
#define PLD pair <LD, LD>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

const int N = 55;
const LL mod = 1e6 + 3;

int n;
char s[N][N];
PII mn, mx;
int ile4 = 0;
int ile2 = 0;
int ile1 = 0;

bool check(){
	if(mx.st < mn.st || mx.nd < mn.nd)
		return false;
	
	if(mn.st == 1 || mn.nd == 1 || mx.nd == n || mx.st == n)
		return false;
	
	if((mx.st - mn.st + 1) * (mx.nd - mn.nd + 1) != ile4)
		return false;

	for(int i = mn.st; i <= mx.st; ++i)
		for(int j = mn.nd; j <= mx.nd; ++j)
			if(s[i][j] != '4')
				return false;

	if(2 * (mx.st + mx.nd - mn.st - mn.nd + 2) != ile2)
		return false;
	if(ile1 != 4)
		return false;
	if(s[mn.st - 1][mn.nd - 1] != '1' || s[mn.st - 1][mx.nd + 1] != '1' || s[mx.st + 1][mn.nd - 1] != '1' || s[mx.st + 1][mx.nd + 1] != '1')
		return false;
	
	for(int i = mn.st; i <= mx.st; ++i)
		if(s[i][mn.nd - 1] != '2' || s[i][mx.nd + 1] != '2')
			return false;

	for(int i = mn.nd; i <= mx.nd; ++i)
		if(s[mn.st - 1][i] != '2' || s[mx.st + 1][i] != '2')
			return false;
	return true;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j){
			if(s[i][j] == '4')
				++ile4;
			if(s[i][j] == '2')
				++ile2;
			if(s[i][j] == '1')
				++ile1;
		}
	
	mn = mp(n + 1, n + 1);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(s[i][j] == '4'){
				mn = min(mn, mp(i, j));
				mx = max(mx, mp(i, j));
			}
	
	if(!check())
		puts("No");
	else
		puts("Yes");
	return 0;
}