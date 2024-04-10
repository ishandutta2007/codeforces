#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 3e5 + 6; int T , N , M;
map < int , int > num; map < int , vector < int > > pot; set < pair < int , int > > vis;
struct dat{int val , pl , pr; bool flg;}; bool operator <(dat p , dat q){return p.val < q.val;}

signed main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> M; vis.clear(); num.clear(); pot.clear(); int ans = 0;
		for(int i = 1 ; i <= N ; ++i){int A; cin >> A; ++num[A]; vis.insert(make_pair(A , A));}
		for(int i = 1 ; i <= M ; ++i){int x , y; cin >> x >> y; vis.insert(make_pair(x , y)); vis.insert(make_pair(y , x));}
		for(auto t : num) pot[t.second].push_back(t.first);
		for(auto &t : pot) reverse(t.second.begin() , t.second.end());
		for(auto &p : pot)
			for(auto &q : pot)
				if(p.first <= q.first){
					vector < int > &L = p.second , &R = q.second;
					priority_queue < dat > que; que.push((dat){L[0] + R[0] , 0 , 0 , 1});
					while(!que.empty()){
						dat now = que.top(); que.pop();
						if(vis.find(make_pair(L[now.pl] , R[now.pr])) == vis.end()){ans = max(ans , (p.first + q.first) * now.val); break;}
						if(now.flg && now.pl + 1 != L.size()) que.push((dat){L[now.pl + 1] + R[now.pr] , now.pl + 1 , now.pr , 1});
						if(now.pr + 1 != R.size()) que.push((dat){L[now.pl] + R[now.pr + 1] , now.pl , now.pr + 1 , 0});
					}
				}
		cout << ans << '\n';
	}
	return 0;
}