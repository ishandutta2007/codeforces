#include<bits/stdc++.h>
using namespace std;

int T , N , A[200003] , B[200003];

int main(){
	cin >> T;
	while(T--){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> B[i];
		for(int i = 1 ; i <= N ; ++i) cin >> A[i];
		int pos = 1; multiset < int > lft; bool flg = 1;
		for(int i = 1 ; i <= N ; ++i){
			if(A[i] == A[i - 1] && lft.find(A[i]) != lft.end()){
				lft.erase(lft.find(A[i])); continue;
			}
			while(pos <= N && B[pos] != A[i])
				lft.insert(B[pos++]);
			if(pos > N){flg = 0; break;}
			++pos;
		}
		cout << (flg ? "YES" : "NO") << endl;
	}
	return 0;
}