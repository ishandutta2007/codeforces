#include<bits/stdc++.h>
using namespace std;

int main(){
	int T , L; string S1 , S2;
	for(cin >> T ; T ; --T){
		cin >> L >> S1 >> S2;
		int cnt1 = 0 , cnt2 = 0 , mn = 1e9;
		for(auto t : S1) cnt1 += t == '1';
		for(auto t : S2) cnt2 += t == '1';
		if(cnt1 == cnt2){
			int num = 0;
			for(int i = 0 ; i < L ; ++i)
				num += S1[i] != S2[i];
			mn = num;
		}
		if(L - cnt1 + 1 == cnt2){
			int num = 0;
			for(int i = 0 ; i < L ; ++i)
				num += S1[i] == S2[i] && S1[i] == '1';
			mn = min(mn , 2 * num - 1);
		}
		cout << (mn == 1e9 ? -1 : mn) << endl;
	}
	return 0;
}