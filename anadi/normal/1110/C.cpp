#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

map <int, int> M;

int main(){
	int quest;
	cin >> quest;
	
	while(quest--){
		int a;
		cin >> a;
		
		int pt = 1;
		while(pt <= a)
			pt *= 2;
		
		pt--;
		if(a == pt){
			if(M.count(a))
				printf("%d\n", M[a]);
			else{
				int mx = 1;
				for(int i = 2; i * i <= a; ++i)
					if(a%i == 0)
						mx = max(mx, a / i);
				
				M[a] = mx;
				printf("%d\n", M[a]);
			}
		}
		else
			printf("%d\n", pt);
	}

	return 0;
}