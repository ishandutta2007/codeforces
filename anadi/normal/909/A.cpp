#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, m;
int tab[N];

string a;
string b;

int main(){
	cin >> a >> b;
	int cur1 = 1, cur2 = 0;
	
	string ret; ret.pb(a[0]);
	while(cur1 < a.size() && a[cur1] < b[cur2]){
		ret.pb(a[cur1++]);
	}
	
	if(cur2 == 0)
		ret.pb(b[0]);
	cout << ret << "\n";
	return 0;
}