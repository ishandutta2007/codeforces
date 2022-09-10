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

char s[mxn];
vector <int> A;
vector <int> B;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	scanf("%s", s + 1);
	
	A.pb(0);
	B.pb(0);
	for(int i = 1; i <= n; ++i)
		if(s[i] == 'a')
			A.pb(i);
		else
			B.pb(i);
	
	int last = 0;
	int now = 0;
	int res = k;
	int use = 0;
	int wsk = 0;
	for(int i = 1; i < A.size(); ++i){
		while(wsk < i && use + A[i] - last > k + 1){
			wsk++;
			use -= A[wsk] - A[wsk - 1] - 1;
		}
		
		if(wsk == i)
			use = 0;
		else
			use += A[i] - last - 1;
		
		now = A[i] - A[wsk] + 1;
		if(wsk == 0)
			now--;
		
		res = max(res, now + k - use);
		last = A[i];
	}

	wsk = 0;
	use = 0;
	now = 0;
	last = 0;
	
	for(int i = 1; i < B.size(); ++i){
		while(wsk < i && use + B[i] - last > k + 1){
			wsk++;
			use -= B[wsk] - B[wsk - 1] - 1;
		}
		
		if(wsk == i)
			use = 0;
		else
			use += B[i] - last - 1;
		
		now = B[i] - B[wsk] + 1;
		if(wsk == 0)
			now--;
		
		res = max(res, now + k - use);
		last = B[i];
	}


	printf("%d\n", min(res, n));
	return 0;
}