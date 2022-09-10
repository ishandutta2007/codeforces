#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PLL pair <LL, LL>
#define PDD pair <D, D>
#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

char big[] = {'A', '0', '0', '0', '0', '0', '0', 'H', 'I', '0', '0', '0', 'M', '0', 'O', '0', '0', '0', '0', 'T', 'U', 'V', 'W', 'X', 'Y', '0'};
string s;

bool dobry(char a, char b){
	if(a == b){
		if(a == 'o' || a == 'x' || a == 'w' || a == 'v')
			return true;
		return false;
	}
	
	if((a == 'p' && b == 'q') || (a == 'b' && b == 'd') || (a == 'q' && b == 'p') || (a == 'd' && b == 'b'))
		return true;
	return false;		
}

bool ok(int l, int r){
	while(l >= 0){
		if(s[l] <= 'Z')
			if(big[s[l] - 'A'] != s[r])
				return false;
		if(s[l] >= 'a')
			if(!dobry(s[l], s[r]))
				return false;
		--l;
		++r;
	}
	
	return true;
}

int main(){
	cin >> s;
	int r = s.size() / 2;
	int l = r - 1;
	if(s.size()%2 == 1)
		++l;
	ok(l, r) ? puts("TAK") : puts("NIE");
	return 0;
}