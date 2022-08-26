#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7; vector < int > pot[_]; int T , N , ans[_];

int main(){
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 1 ; i <= N ; ++i){int x; cin >> x; pot[x].push_back(i);}
		vector < int > num; for(int i = 1 ; i <= N ; ++i) num.push_back(i);
		sort(num.begin() , num.end() , [&](int x , int y){return pot[x].size() > pot[y].size();});
		for(int p = 0 ;  ; ++p){
			while(num.size() && pot[num.back()].empty()) num.pop_back();
			if(num.empty()) break;
			for(int i = 0 ; i < num.size() ; ++i)
				ans[pot[num[i]].back()] = num[(i + 1) % num.size()];
			for(int i = 0 ; i < num.size() ; ++i) pot[num[i]].pop_back();
		}
		for(int i = 1 ; i <= N ; ++i) cout << ans[i] << ' ';
		cout << endl;
	}
	return 0;
}