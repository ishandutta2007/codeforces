#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>
#define PLL pair <LL, LL>
#define pb push_back

const int mxn = 1e5 + 7;

D t[mxn];
string s;
int n;
D k;

D liczba(string a){
	int x = 0;
	
	if(a[0] == '-'){
		for(int i = 1; i < a.size(); ++i){
			x *= 10;
			x += a[i] - '0';
		}

		x *= -1;
	}
	else{
		for(int i = 0; i < a.size(); ++i){
			x *= 10;
			x += a[i] - '0';
		}
	}
	
	return (D)x;
}

bool wstaw(){
	double res = 0.0;
	double bound = (D)n * (D)100000.0;
	for(int i = 1; i <= n + 1; ++i){
		res *= k;
		res += t[i];
		if(abs(res) >= bound)
			return false;
	}
	
	return res == 0.0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	int ile = 0;
	for(int i = n + 1; i >= 1; --i){
		cin >> s;
		if(s[0] == '?'){
			t[i] = -mxn;
			++ile;
		}
		else
			t[i] = liczba(s);
	}
	
	if(k == 0){
		if(t[n + 1] == -mxn){
			if((n - ile)%2 == 0)
				puts("Yes");
			else
				puts("No");
			return 0;
		}
		if(t[n + 1] == 0.0)
			puts("Yes");
		else
			puts("No");
		return 0;
	}
	
	if(ile != 0){
		if(n%2 == 1)
			puts("Yes");
		else
			puts("No");
		return 0;
	}
	
	if(wstaw())
		puts("Yes");
	else
		puts("No");

	return 0;
}