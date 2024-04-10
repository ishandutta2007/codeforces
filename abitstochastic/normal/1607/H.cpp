#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 2e5 + 7; int T , N , A[_] , B[_] , M[_] , tarA[_];
map < int , vector < int > > pot;
struct seg{int l , r , id;};

signed main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N; pot.clear(); int cnt = 0;
		for(int i = 1 ; i <= N ; ++i){cin >> A[i] >> B[i] >> M[i]; pot[A[i] + B[i] - M[i]].push_back(i);}
		for(auto t : pot){
			priority_queue < pair < int , int > > q; vector < seg > S;
			for(auto r : t.second) S.push_back((seg){max(0ll , A[r] - M[r]) , A[r] - max(0ll , M[r] - B[r]) , r});
			sort(S.begin() , S.end() , [&](seg p , seg q){return p.l < q.l;});
			for(int i = 0 ; i < S.size() ; ++i){
				if(q.size() && S[i].l > -q.top().first){int tar = -q.top().first; ++cnt; while(q.size()){tarA[q.top().second] = tar; q.pop();}}
				q.push(make_pair(-S[i].r , S[i].id));
			}
			int tar = -q.top().first; ++cnt; while(q.size()){tarA[q.top().second] = tar; q.pop();}
		}
		cout << cnt << '\n'; for(int i = 1 ; i <= N ; ++i) cout << A[i] - tarA[i] << ' ' << M[i] - (A[i] - tarA[i]) << '\n';
	}
	return 0;
}