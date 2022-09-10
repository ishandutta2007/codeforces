#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL m;

bool check(LL mid){
	LL result = 0LL;
	for(LL i = 2LL; i * i * i <= mid; ++i)
		result += mid / (i * i * i);
	return result >= m;
}

LL BS(){
	LL pocz = 8LL;
	LL kon = 1e18;
	while(pocz < kon){
		LL mid = (pocz + kon) / 2LL;
		if(check(mid))
			kon = mid;
		else
			pocz = mid + 1;
	}
	
	return pocz;
}

int main(){
	scanf("%I64d", &m);
	LL result = BS();
	LL res = 0LL;
	for(LL i = 2LL; i * i * i <= result; ++i)
		res += result / (i * i * i);
	if(res != m)
		puts("-1");
	else
		printf("%I64d\n", result);
	return 0;
}