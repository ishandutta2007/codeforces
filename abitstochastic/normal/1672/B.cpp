#include<bits/stdc++.h>
using namespace std;

int main(){
	int T; string str; cin >> T;
	while(T--){
		cin >> str;
		if(str.back() != 'B') cout << "NO" << endl;
		else{
			int cnt = 0; bool flg = 1;
			for(auto t : str){
				cnt += t == 'A' ? 1 : -1;
				flg &= cnt >= 0;
			}
			cout << (flg ? "YES" : "NO") << endl;
		}
	}
	return 0;
}