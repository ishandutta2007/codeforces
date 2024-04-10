#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
string s;
pair <char, int> tab[N];

bool cmp(pair <char, int> a, pair <char, int> b){
	return a.nd < b.nd;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	cin >> s;
	
	if(m == n){
		cout << "";
	}
	
	for(int i = 0; i < n; ++i)
		tab[i] = {s[i], i};
	s = "";

	sort(tab, tab + n);
	sort(tab + m, tab + n, cmp);
	
	for(int i = m; i < n; ++i)
		s.push_back(tab[i].st);
	cout << s;
	return 0;
}