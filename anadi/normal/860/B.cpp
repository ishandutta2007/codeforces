#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int T = 3 * N + 7;

const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, m;
bool ans[N];
string word[N];
map <LL, int> M;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		char s[10];
		scanf("%s", s);
		set <LL> S;

		for(int j = 0; j < 9; ++j){
			LL cur = 0LL;
			for(int k = j; k < 9; ++k){
				cur *= 11LL, cur += s[k] - '0' + 1;
				S.insert(cur);
			}
		}
		
		for(LL v: S)
			M[v]++;
		word[i] = s;
	}
	
	for(int i = 1; i <= n; ++i)
		for(int l = 1; l <= 9; ++l){
			for(int j = 0; j + l <= 9; ++j){
				LL cur = 0;
				for(int k = j; k < j + l; ++k)
					cur *= 11LL, cur += word[i][k] - '0' + 1;

				if(M[cur] == 1){
					ans[i] = true;
					for(int k = j; k < j + l; ++k)
						printf("%c", word[i][k]);
					puts("");
					break;
				}
			}

			if(ans[i] != 0)
				break;
		}

	return 0;
}