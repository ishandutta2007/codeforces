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

int n;
vector <int> A, B;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int a;
		scanf("%d", &a);
		A.push_back(a);
	}
	
	for(int i = 0; i < n; ++i){
		int a;
		scanf("%d", &a);
		B.push_back(a);
	}	
	
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	LL sa = 0LL, sb = 0LL;
	for(int i = 0; i < n; ++i){
		if(A.size() > 0 && (B.size() == 0 || A.back() >= B.back())){
			sa += A.back();
			A.pop_back();
		}
		else
			B.pop_back();
		
		if(B.size() > 0 && (A.size() == 0 || B.back() >= A.back())){
			sb += B.back();
			B.pop_back();
		}
		else
			A.pop_back();
	}
	
	printf("%lld\n", sa - sb);
	return 0;
}