#include<bits/stdc++.h>
using namespace std;

long long T , L , R;

long long sq(long long x){
	long long ans = sqrt(x);
	while(ans * ans > x) --ans;
	while((ans + 1) * (ans + 1) <= x) ++ans;
	return ans;
}

int main(){
	for(cin >> T ; T ; --T){
		cin >> L >> R;
		long long valL = sq(L) , valR = sq(R) , ans = max(0ll , valR - valL - 1) * 3;
		for(int i = valL ; i <= valL + 2 ; ++i)
			if(i * valL >= L && i * valL <= R) ++ans;
		if(valL != valR){
			swap(valL , valR);
			for(int i = valL ; i <= valL + 2 ; ++i)
				if(i * valL >= L && i * valL <= R) ++ans;
		}
		cout << ans << endl;
	}
	return 0;
}