#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

const int mxn = 2e5 + 7;
const LL INF = 1e9 + 7LL;

map <int, int> M;
int t[mxn];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		M[a]++;
	}

	int m;
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i)
		scanf("%d", &t[i]);

	int res = 0;
	int res2 = 0;
	int nr = 1;
	for(int i = 1; i <= m; ++i){
		int a;
		scanf("%d", &a);
		if(M[t[i]] > res){
			nr = i;
			res = M[t[i]];
			res2 = M[a];
			continue;
		}

		if(M[t[i]] == res && M[a] > res2){
			nr = i;
			res2 = M[a];
			continue;
		}
	}
	
	printf("%d\n", nr);
	return 0;
}