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

int N,cnt[MAXN],arr[MAXN][4],res[MAXN],ptr;
bool done[MAXN],used[MAXN];
set<pii> s;
set<int> nums[MAXN];
map<pii,set<int>> tmp;

//inline void fix(pii t){
//	int bad = nums[t.second].back();
//	nums[t.second].pop_back();
//	for(int k=1; k<=3; k++){
//		if(arr[bad][k] == t.second) continue;
//		s.erase(make_pair(cnt[arr[bad][k]],arr[bad][k]));
//		cnt[arr[bad][k]]--;
//		s.insert(make_pair(cnt[arr[bad][k]],arr[bad][k]));
//	}
//}

int main() {
	boost();

	cin>>N;
	for(int i=1; i<=N-2; i++){
		for(int k=1; k<=3; k++){
			int a; cin>>a;
			arr[i][k] = a;
			cnt[a]++;
			nums[a].insert(i);
		}
		sort(arr[i]+1,arr[i]+4);
		tmp[make_pair(arr[i][1],arr[i][2])].insert(i);
		tmp[make_pair(arr[i][1],arr[i][3])].insert(i);
		tmp[make_pair(arr[i][2],arr[i][3])].insert(i);
	}
	for(int i=1; i<=N; i++){
		s.insert(make_pair(cnt[i],i));
//		reverse(nums[i].begin(),nums[i].end());
	}

//	while(s.size()){
//		pii t = *s.begin(); s.erase(s.begin());
//		pii ss = *s.begin(); s.erase(s.begin());
//		res[++ptr] = t.second;
//		res[N-ptr+1] = ss.second;
//
//		fix(t);
//		fix(ss);
//	}
	pii st = *s.begin(); s.erase(s.begin());
	int p = st.second;

	res[++ptr] = p;

	int idx = *nums[p].begin();
//	nums[p].erase(idx);
	vector<int> ok;
	for(int i=1; i<=3; i++){
//		if(arr[idx][i] != p) ok.push_back(arr[idx][i]);
//		cnt[arr[idx][i]]--;
		if(cnt[arr[idx][i]] == 2) res[ptr+1] = arr[idx][i];
		else if(arr[idx][i] != p) res[ptr+2] = arr[idx][i];
//		nums[arr[idx][i]].erase(i);
	}
	ptr+=2;
	done[idx] = true;
	used[res[1]] = used[res[2]] = used[res[3]] = true;
//	ptr+=2;

	while(ptr < N){
		pii pp = {res[ptr-1],res[ptr]};
		if(pp.first > pp.second) swap(pp.first,pp.second);
		while(done[*tmp[pp].begin()])
			tmp[pp].erase(tmp[pp].begin());
		int nxt = *tmp[pp].begin(), a = -1;
		for(int k=1; k<=3; k++){
			if(used[arr[nxt][k]]) continue;
			a = arr[nxt][k];
		}
		res[++ptr] = a;
		used[res[ptr]] = true;
		done[nxt] = true;
	}
	for(int i=1; i<=N; i++)
		cout<<res[i]<<" ";
	return 0;
}