#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 2e5 + 7; int N , A[_] , T;

double check(pair < int , int > x , pair < int , int > y){
	return (long double)(y.second - x.second) / (x.first - y.first);
}
int calc(pair < int , int > x , pair < int , int > y){
	return floor(x.first * (long double)(y.second - x.second) / (x.first - y.first) + x.second + 0.1);
}

signed main(){
	ios::sync_with_stdio(0); cin >> T;
	while(T--){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
		sort(A + 1 , A + N + 1);
		int x = 0; for(int i = 2 ; i <= N ; ++i) x += A[i] + A[1];
		if(x > 0){cout << "INF\n"; continue;}
		x = 0; for(int i = 1 ; i < N ; ++i) x += A[i] + A[N];
		if(x < 0){cout << "INF\n"; continue;}
		int Sum1 = 0 , Sum2 = 0; vector < pair < int , int > > hull , stk;
		for(int i = 2 ; i <= N ; ++i){Sum1 += A[i] * A[1]; Sum2 += (A[i] + A[1]);}
		for(int i = 1 ; i < N ; ++i){
			hull.push_back(make_pair(Sum2 , Sum1));
			Sum1 -= A[i + 1] * A[1]; Sum2 -= A[i + 1] + A[1];
			Sum1 += A[i + 1] * A[N]; Sum2 += A[i + 1] + A[N];
		}
		sort(hull.begin() , hull.end() , [&](pair < int , int > p , pair < int , int > q){return p.first > q.first || p.first == q.first && p.second < q.second;}); int mx = -1e18;
		for(auto t : hull){
			if(stk.size() && t.first == stk.back().first) continue;
			while(stk.size() >= 2 && check(stk[stk.size() - 2] , t) > check(stk[stk.size() - 1] , t)) stk.pop_back();
			stk.push_back(t);
		}
		if(stk.size() == 1) mx = hull[0].second;
		else for(int i = 0 ; i + 1 < stk.size() ; ++i) mx = max(mx , calc(stk[i] , stk[i + 1]));
		cout << mx << endl;
	}
	return 0;
}