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

int main(){
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	
	if(x1 + y1 <= max(x2, y2)){
		puts("Polycarp");
		return 0;
	}
	
	int Moves1 = abs(x1 - y1 - (x2 - y2));
	if(x1 - y1 > x2 - y2)		
		x1 -= abs(x1 - y1 - (x2 - y2));
	else
		y1 -= abs(x1 - y1 - (x2 - y2));
	
	int Moves2 = x2 - x1; //printf("%d ", Moves2);
	if(Moves1 <= Moves2)
		puts("Polycarp");
	else
		puts("Vasiliy");
	return 0;
}