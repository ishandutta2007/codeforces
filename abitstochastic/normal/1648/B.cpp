#include<bits/stdc++.h>
using namespace std;

int T , sum[1000003] , N , C , A[1000003];

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> C; for(int i = 1 ; i <= C ; ++i) sum[i] = 0;
		for(int i = 1 ; i <= N ; ++i){cin >> A[i]; sum[A[i]] = 1;}
		for(int i = 1 ; i <= C ; ++i) sum[i] += sum[i - 1];
		bool flg = 1;
		for(int i = 1 ; i <= C ; ++i)
			if(sum[i] != sum[i - 1])
				for(int j = i ; j <= C ; j += i)
					if(sum[min(j + i - 1 , C)] - sum[j - 1] > 0 && sum[j / i] == sum[j / i - 1]) flg = 0;
		cout << (flg ? "Yes" : "No") << '\n';
	}
	return 0;
}