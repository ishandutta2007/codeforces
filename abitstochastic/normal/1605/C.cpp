#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int T , N; string S; ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> S; int ans = -1;
		for(int L = 2 ; L <= 7 && !~ans ; ++L)
			for(int j = 0 ; j + L - 1 < S.size() ; ++j){
				static int cnt[3]; memset(cnt , 0 , sizeof(cnt));
				for(int k = 0 ; k < L ; ++k) ++cnt[S[j + k] - 'a'];
				if(cnt[0] > cnt[1] && cnt[0] > cnt[2]){ans = L; break;}
			}
		cout << ans << endl;
	}
	return 0;
}