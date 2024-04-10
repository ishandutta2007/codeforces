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

const int MAXN = 1000005;

int N,arr[MAXN];
ll psa[MAXN],ans=LLONG_MAX;
vector<ll> tmp;

inline ll calc(vector<pair<ll,int>> &v){
	ll tot = 0, res = 0;
	for(pair<ll,int> c:v)
		tot+=c.first;
	ll curr = 0;
	int idx = -1;
	for(int i=0; i<v.size(); i++){
		curr+=v[i].first;
		if(curr >= (tot+1)/2){
			idx = v[i].second;
			break;
		}
	}
	for(int i=0; i<v.size(); i++){
		ll move = abs(idx-v[i].second);
		res+=move*v[i].first;
	}
	return res;
}

inline void doit(ll group){
	ll arr2[MAXN];
	for(int i=1; i<=N; i++)
		arr2[i] = arr[i]%group;
	ll sum = 0, res = 0;
	vector<pair<ll,int>> v;
	for(int i=1; i<=N; i++){
		if(sum+arr2[i] >= group){
			v.push_back({group-sum,i});
			res+=calc(v);
			v.clear();
			sum = sum+arr2[i]-group;
			if(sum) v.push_back({sum,i});
		}else{
			sum+=arr2[i];
			v.push_back({arr2[i],i});
		}
	}
	ans = min(ans,res);
}

int main() {
    boost();

	cin>>N;
	for(int i=1; i<=N; i++){
		cin>>arr[i];
		psa[i] = psa[i-1]+arr[i];
	}

	ll bruh = psa[N];
	for(ll i=2; i*i <= bruh; i++){
		if(bruh%i == 0){
			tmp.push_back(i);
			while(bruh%i == 0)
				bruh/=i;
		}
	}
	if(bruh > 1) tmp.push_back(bruh);

	for(ll what:tmp){
		doit(what);
	}
	if(ans == LLONG_MAX) cout<<-1<<endl;
	else cout<<ans<<endl;

    return 0;
}