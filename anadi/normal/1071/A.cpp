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

int a, b;
vector <int> resa, resb;

int main(){
	cin >> a >> b;
	int Left = a + b, cur = 1;
	
	while(Left >= cur){
		Left -= cur;
		++cur;
	}
	
	int ca = a, cur2 = 1;
	vector <int> resa;

	while(ca >= cur2){
		resa.push_back(cur2);
		ca -= cur2;
		++cur2;
	}
	
	cur2 = cur - 1; int cb = b;
	while(cb >= cur2 && cur2 > 0){
		resb.push_back(cur2);
		cb -= cur2;
		cur2--;
	}
	
	if(resa.size() + resb.size() == cur)
		resa.pop_back();
	
	if(resa.size() + resb.size() + 1 < cur){
		int t = cur2;
		ca -= t;

		resa.push_back(t);
		resb.push_back(abs(ca));
		
		for(int i = 0; i < resa.size(); ++i)
			if(resa[i] == abs(ca))
				swap(resa[i], resa[resa.size() - 1]);
		resa.pop_back();
	}
	
	printf("%d\n", resa.size());
	for(int v: resa)
		printf("%d ", v);
	puts("");
	printf("%d\n", resb.size());
	for(int v: resb)
		printf("%d ", v);
	return 0;
}