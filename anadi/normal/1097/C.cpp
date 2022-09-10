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
string in[N];
map <int, int> M;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> in[i];
	
	for(int i = 0; i < n; ++i){
		int mn = 0, s = 0;
		for(auto c: in[i]){
			s += c == '(' ? 1 : -1;
			mn = min(mn, s);
		}
		
		if(mn == 0)
			M[s]++;
	}
	
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int mn = 0, s = 0;
		for(auto c: in[i]){
			s += c == '(' ? 1 : -1;
			mn = min(mn, s);
		}
		
		if(s < 0 && mn == s && M[-s] > 0)
			M[-s]--, ++ans;
	}
	
	while(M[0] > 1)
		M[0] -= 2, ++ans;
	printf("%d\n", ans);
	return 0;
}