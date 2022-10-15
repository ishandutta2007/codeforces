#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MAXN = 2005;

int T,N,M,A[MAXN];

int main() {
    boost();

	cin>>T;
	while(T--){
		cin>>N>>M;
		for(int i=1; i<=N; i++)
			cin>>A[i];
		if(N == 2) cout<<-1<<endl;
		else if(M < N) cout<<-1<<endl;
		else{
			vector<pii> v;
			for(int i=1; i<=N; i++)
				v.push_back(make_pair(A[i],i));
			sort(v.begin(),v.end());
			vector<pii> res;
			ll cost = 0;
			for(int i=1; i<=N; i++){
				int nxt = i+1;
				if(nxt == N+1) nxt = 1;
				res.push_back(make_pair(i,nxt));
				cost+=A[i]+A[nxt];
			}
			M-=N;
			while(M--){
				cost+=v[0].first+v[1].first;
				res.push_back(make_pair(v[0].second,v[1].second));
			}
			cout<<cost<<endl;
			for(int i=0; i<res.size(); i++)
				cout<<res[i].first<<" "<<res[i].second<<endl;
		}
	}

    return 0;
}