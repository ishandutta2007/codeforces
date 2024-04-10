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
const int INF = 1e9 + 9;

int n, m;
string s;

int ask(){
	cout << "? " << s << "\n";
	fflush(stdout);
	
	int ret;
	cin >> ret;
	return ret;
}

int find1(){
	s.resize(n);
	for(int i = 0; i < n; ++i)
		s[i] = '1';
	int ile = ask();
	
	s[0] = '0';
	if(ask() < ile)
		return 0;
	return 1;
}

int find2(int type){
	int p = 1, k = n - 1;
	for(int i = 1; i < n; ++i)
		s[i] = type + '0';
	s[0] = (type ^ 1) + '0';
	
	int last = ask();
	while(p < k){
		int m = (p + k) / 2;
		for(int i = p; i <= m; ++i)
			s[i] = (type ^ 1) + '0';
		int ile = ask();
		
		for(int i = p; i <= m; ++i)
			s[i] = type + '0';
		if(ile + m - p + 1 == last)
			p = m + 1;
		else
			k = m;
	}
	
	return p;
}

int main(){
	ios_base::sync_with_stdio(false);	
	cin >> n;
	int type = find1();

	int ans0 = -1, ans1 = -1;
	if(type){
		ans1 = 0;
		ans0 = find2(type ^ 1);
	}
	else{
		ans0 = 0;
		ans1 = find2(type ^ 1);
	}
	
	cout << "! " << ans0 + 1 << " " << ans1 + 1 << "\n";
	fflush(stdout);
	return 0;
}