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
const int INF = 1e9 + 9;

int n, k;
int cur = 1;
vector <int> s;
vector <int> res;

int main(){
	scanf("%d %d", &n, &k);
	
	s.push_back(n + 1);
	for(int i = 1; i <= k; ++i){
		int a; scanf("%d", &a);
		if(s.back() < a){
			puts("-1");
			return 0;
		}
		
		s.push_back(a);
		while(s.size() > 1 && s.back() == cur){
			s.pop_back();
			++cur;
		}
		
		res.push_back(a);
	}
	
	while(res.size() < n){
		res.push_back(s.back() - 1);
		s.push_back(s.back() - 1);
		
		while(s.size() > 1 && s.back() == cur){
			s.pop_back();
			++cur;
		}
	}
	
	for(int v: res)
		printf("%d ", v);
	return 0;
}