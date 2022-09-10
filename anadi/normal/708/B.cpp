#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>
#define PLL pair <LL, LL>
#define PDD pair <D, D>
#define pb push_back

const int N = 1e5 + 7;
const LL INF = 100000000000000000LL;
const int mx = 1e6;

int a, b, c, d;

int main(){
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int ile_zer = 0, ile_jed = 0;
	while(ile_zer * (ile_zer - 1) / 2 < a)
		ile_zer++;
	while(ile_jed * (ile_jed - 1) / 2 < d)
		++ile_jed;
	
	if(ile_zer * (ile_zer - 1) != 2 * a || ile_jed * (ile_jed - 1) != 2 * d){
		puts("Impossible");
		return 0;
	}
	
	if((a + d) == 0){
		if(b == 1 && c == 0)
			puts("01");
		else if(b == 0 && c == 1)
			puts("10");
		else if(b + c == 0)
			puts("0");
		else
			puts("Impossible");
		return 0;
	}
	
	if(a == 0){
		if(b == 0 && c == 0){
			for(int i = 0; i < ile_jed; ++i)
				cout << "1";
			return 0;
		}
		
		if(b + c != ile_jed){
			puts("Impossible");
			return 0;
		}
		
		for(int i = 0; i < c; ++i)
			cout << "1";
		cout << "0";
		for(int i = 0; i < b; ++i)
			cout << "1";
		return 0;
	}

	if(d == 0){
		if(b == 0 && c == 0){
			for(int i = 0; i < ile_zer; ++i)
				cout << "0";
			return 0;
		}
		
		if(b + c != ile_zer){
			puts("Impossible");
			return 0;
		}
		
		for(int i = 0; i < b; ++i)
			cout << "0";
		cout << "1";
		for(int i = 0; i < c; ++i)
			cout << "0";
		return 0;
	}

	if((b + c) != ile_zer * ile_jed){
		puts("Impossible");
		return 0;
	}	
	
	string ans;
	while(ile_zer > 0 || ile_jed > 0){
		if(b >= ile_jed && ile_zer > 0){
			ans.push_back('0');
			b -= ile_jed;
			--ile_zer;
		}
		else{
			ans.push_back('1');
			c -= ile_zer;
			--ile_jed;
		}
	}

	cout << ans;
	return 0;
}