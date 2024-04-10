#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n;
vector <int> A, B, NA;

int main(){
	scanf("%d", &n);
	A.resize(n + 1);
	B.resize(n + 1);
	NA.resize(n + 1);
	
	A[0] = -1, B[0] = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < i; ++j)
			NA[j + 1] = A[j];
		NA[0] = 0;
		
		bool ok = true;
		for(int j = 0; j < i; ++j){
			NA[j] += B[j];
			NA[j] %= 2;
//			if(NA[j] < -1 || 1 < NA[j])
//				ok = false;
		}
		
/*		if(!ok){
			for(int j = 0; j < i; ++j)
				NA[j + 1] = -A[j];
			
			ok = true;
			for(int j = 0; j < i; ++j){
				NA[j] += B[j];
				if(NA[j] < -1 || 1 < NA[j])
					ok = false;
			}
		}
*/		
		assert(ok);
		B = A;
		A = NA;
		
		if(A[i] == -1)
			for(int j = 0; j <= i; ++j)
				A[j] *= -1;
		if(B[i - 1] == -1)
			for(int j = 0; j <= i; ++j)
				B[j] *= -1;
	}

	printf("%d\n", n);
	for(int i = 0; i <= n; ++i)
		printf("%d ", A[i]);
	puts("");
	
	printf("%d\n", n - 1);
	for(int i = 0; i < n; ++i)
		printf("%d ", B[i]);
	return 0;
}