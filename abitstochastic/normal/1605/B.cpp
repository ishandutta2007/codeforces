#include<bits/stdc++.h>
using namespace std;

int main(){
	int T , N; string S;
	for(cin >> T ; T ; --T){
		cin >> N >> S; int cnt1 = 0; vector < int > pot0 , pot1;
		for(auto t : S) cnt1 += t - '0';
		for(int i = 0 ; i < S.size() - cnt1 ; ++i) if(S[i] == '1') pot1.push_back(i);
		for(int i = S.size() - cnt1 ; i < S.size() ; ++i) if(S[i] == '0') pot0.push_back(i);
		if(pot0.empty()) cout << 0 << endl;
		else{
			cout << 1 << endl << pot0.size() + pot1.size() << ' ';
			for(auto t : pot1) cout << t + 1 << ' ';
			for(auto t : pot0) cout << t + 1 << ' ';
			cout << endl;
		}
	}
	return 0;
}