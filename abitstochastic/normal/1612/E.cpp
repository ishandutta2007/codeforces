#include<bits/stdc++.h>
using namespace std;

#define ld long double
vector < int > pot[200003] , ans; int N; ld mx;

int main(){
	ios::sync_with_stdio(0); cin >> N;
	for(int i = 1 ; i <= N ; ++i){int P , K; cin >> P >> K; pot[P].push_back(K);}
	for(int i = 1 ; i <= min(N , 20) ; ++i){
		static pair < ld , int > mxv[23]; for(int j = 0 ; j < i ; ++j) mxv[j].first = -1;
		for(int j = 1 ; j <= 2e5 ; ++j){
			ld sum = 0; for(auto t : pot[j]) sum += min(1.0 , 1.0 * t / i);
			for(int s = 0 ; s < i ; ++s)
				if(mxv[s].first < sum){
					for(int k = i ; k > s ; --k) mxv[k] = mxv[k - 1];
					mxv[s] = make_pair(sum , j); break;
				}
		}
		ld all = 0; for(int j = 0 ; j < i ; ++j) all += mxv[j].first;
		if(mx < all){mx = all; ans.clear(); for(int j = 0 ; j < i ; ++j) ans.push_back(mxv[j].second);}
	}
	vector < pair < int , int > > tpot;
	for(int i = 1 ; i <= 2e5 ; ++i){
		int sum = 0; for(auto t : pot[i]) sum += t;
		tpot.push_back(make_pair(-sum , i));
	}
	sort(tpot.begin() , tpot.end()); long double tmx = -1 , tsum = 0; int tid = 0;
	for(int i = 0 ; i < N ; ++i){
		tsum -= tpot[i].first;
		if(i >= 20 && tmx < tsum / (i + 1)){tmx = tsum / (i + 1); tid = i;}
	}
	if(tmx > mx){mx = tmx; ans.clear(); for(int i = 0 ; i <= tid ; ++i) ans.push_back(tpot[i].second);}
	cout << ans.size() << endl; for(auto t : ans) cout << t << ' ';
	return 0;
}