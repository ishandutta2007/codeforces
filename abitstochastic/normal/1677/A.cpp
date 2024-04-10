#include<bits/stdc++.h>
using namespace std;

const int _ = 5003;
int A[_] , N , T; long long val[_] , S[_] , ans;

int main(){
	for(cin >> T ; T ; --T){
		cin >> N; memset(val , 0 , sizeof(val)); ans = 0;
		for(int i = 1 ; i <= N ; ++i) cin >> A[i];
		for(int i = N ; i ; --i){
			for(int j = 1 ; j <= N ; ++j) S[j] = 0;
			for(int j = i + 1 ; j <= N ; ++j)
				if(A[j] > A[i]) ans += val[j]; else{++S[i + 1]; --S[j];}
			for(int j = 1 ; j <= N ; ++j){S[j] += S[j - 1]; val[j] += S[j];}
		}
		cout << ans << endl;
	}
	return 0;
}