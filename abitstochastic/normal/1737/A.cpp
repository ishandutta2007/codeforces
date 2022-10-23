#include<bits/stdc++.h>
using namespace std;

int N , K , T , cnt[30];

int main(){
	for(cin >> T ; T ; --T){
		cin >> N >> K; string str; cin >> str;memset(cnt , 0 , sizeof(cnt));
		for(auto t : str) ++cnt[t - 'a'];
		string ans;
		for(int i = 1 ; i <= K ; ++i){
			int pos = 0;
			while(cnt[pos] && pos < N / K){--cnt[pos++];}
			ans.push_back('a' + pos);
		}
		cout << ans << endl;
	}
	
	return 0;
}