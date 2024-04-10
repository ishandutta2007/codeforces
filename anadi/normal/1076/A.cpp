#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	cout.tie(NULL);

	cin >> n >> s; int pl = -1;
	for(int i = 0; i < n; ++i){
		if(i == n - 1)
			pl = i;
		else if(s[i] > s[i + 1]){
			pl = i;
			break;
		}
	}
	
	for(int i = 0; i < pl; ++i)
		cout << s[i];
	for(int i = pl + 1; i < n; ++i)
		cout << s[i];
	return 0;
}