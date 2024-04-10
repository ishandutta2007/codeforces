#include<bits/stdc++.h>
using namespace std;

signed main(){
	int T; cin >> T;
	while(T--){
		string S; int N; cin >> N >> S; int pos = 0;
		if(S[0] == S[1]){cout << S[0] << S[1] << endl; continue;}
		while(pos + 1 < N && S[pos + 1] <= S[pos]) ++pos;
		for(int i = 0 ; i <= pos ; ++i) cout << S[i];
		for(int i = pos ; ~i ; --i) cout << S[i];
		cout << endl;
	}
	return 0;
}