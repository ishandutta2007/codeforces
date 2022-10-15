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

const int MAXN = 100005;

int N,arr[MAXN],sum;
ll ans = LLONG_MAX;

inline ll calc(vector<int> &v){
	int med = (int)v[v.size()/2];
	ll tt = 0;
	for(int i=0; i<v.size(); i++)
		tt+=abs(v[i]-med);
	return tt;
}

inline void doit(int group){
	vector<int> v;
	ll res = 0;
	for(int i=1; i<=N; i++){
		if(arr[i]) v.push_back(i);
		if(v.size() == group){
			res+=calc(v);
			v.clear();
		}
	}
	ans = min(ans,res);
}

int main() {
	boost();

	cin>>N;
	for(int i=1; i<=N; i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	for(int f=1; f<=sqrt(sum); f++){
		if(sum%f == 0){
			if(f != 1) doit(f);
			if(sum/f != 1) doit(sum/f);
		}
	}
	if(ans == LLONG_MAX) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}