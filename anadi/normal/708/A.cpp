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

int main(){
	string s;
	cin >> s;
	
	bool use = false;
	bool now = false;
	for(int i = 0; i < s.size(); ++i)
		if(s[i] != 'a'){
			if(!use || now){
				use = true;
				now = true;
				s[i]--;
			}
		}
		else
			now = false;
		
	if(!use)
		s[s.size() - 1] = 'z';
	cout << s;
	return 0;
}