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
set <int> B, S, U;

void zero(){
	puts("0");
	exit(0);
}

int bestB(){
	if(B.size() == 0)
		return 0;
	return *(--B.end());
}

int bestS(){
	if(S.size() == 0)
		return MX;
	return *S.begin();
}

int main(){
	scanf("%d", &n);
	int ret = 1;

	while(n--){
		char s[10];
		scanf("%s", s);
		
		int val;
		scanf("%d", &val);
		
		assert(bestB() < bestS());
		if(U.size()){
			assert(bestB() < *U.begin());
			assert(*(--U.end()) < bestS());
		}

		if(s[1] == 'D'){
			if(val < bestB())
				B.insert(val);
			else if(bestS() < val)
				S.insert(val);
			else
				U.insert(val);
		}
		else{
			if(val < bestB())
				zero();
			if(bestS() < val)
				zero();
			
			if(B.size() > 0 && B.find(val) != B.end())
				B.erase(val);
			else if(S.size() > 0 && S.find(val) != S.end())
				S.erase(val);
			else{
				ret = (ret + ret)%MX;
				U.erase(val);
			}

			for(auto v: U)
				if(v < val)
					B.insert(v);
				else
					S.insert(v);
			U.clear();
		}
	}
	
	ret = (1LL * ret * (U.size() + 1))%MX;
	printf("%d\n", ret);
	return 0;
}