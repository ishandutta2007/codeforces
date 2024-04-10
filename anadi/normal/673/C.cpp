#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

const int mxn = 1e5 + 7;
const int INF = 1e9 + 7;
const int MX = 1e9 + 9;

int n;
int res[mxn];
int now[mxn];
int a[mxn];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	
	for(int i = 1; i <= n; ++i){
		int mx = 0;
		int color = 0;
		for(int j = i; j <= n; ++j){
			now[a[j]]++;
			if(now[a[j]] > mx){
				mx = now[a[j]];
				color = a[j];
			}
			if(now[a[j]] == mx && a[j] < color)
				color = a[j];
			res[color]++;
		}
		for(int j = 1; j <= n; ++j)
			now[j] = 0;
	}
	
	for(int i = 1; i <= n; ++i)
		printf("%d ", res[i]);
	
	return 0;
}