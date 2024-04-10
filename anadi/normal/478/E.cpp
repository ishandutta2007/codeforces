#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int LL;

#define int long long

#define st first
#define nd second
#define mp make_pair
#define PII pair <LL, LL>
 
const int MAX_N = 10 * 1000 * 1000;
const LL BIG_MAX = 1LL * MAX_N * MAX_N;
 
LL n, k;
int dgs[20];
vector <int> wavey;
 
vector <PII> all_left;
vector <pair <PII, PII> > all_right;
 
bool is_wavey(LL id){
	int t = 0;
	while(id){
		dgs[t++] = id % 10;
		id /= 10;
	}
	
	for(int i = 1; i + 1 < t; ++i){
		if(dgs[i] >= dgs[i - 1] && dgs[i] <= dgs[i + 1])
			return false;
 
		if(dgs[i] <= dgs[i - 1] && dgs[i] >= dgs[i + 1])
			return false;
	}
	
	if(t > 1 and dgs[0] == dgs[1])
	    return false;
	return true;
}
 
void get_left(){
	for(auto v: wavey){
		int _v = v;
		bool is_0 = true;
		
		int t = 0;
		while(v){
			dgs[t++] = v % 10;
			v /= 10;
		}
		
		if(t > 1){
			if(dgs[0] > dgs[1])
				is_0 = false;
		}
		
		if(t > 1 && dgs[0] == dgs[1])
			continue;
		
		if(is_0)
			all_left.push_back({_v, 0LL});
		else
			all_left.push_back({_v, 1LL});
	}
}
 
void get_right(){
	for(auto v: wavey){
		int _v = v;
		if(100 * v < MAX_N)
			continue;
 
		int type = 0;
		for(int i = 0; i < 7; ++i){
			dgs[i] = v % 10;
			v /= 10;
		}
		
		if(dgs[5] < dgs[4] && dgs[6] == 0)
			continue;
		
		if(dgs[6] < dgs[5])
			type = 1;
		all_right.push_back({{_v % n, type}, {dgs[6], _v}});
	}
	
	sort(all_right.begin(), all_right.end());
}
 
int32_t main(){
	scanf("%lld %lld", &n, &k);
	for(int i = 1; i < MAX_N; ++i)
		if(is_wavey(i))
			wavey.push_back(i);
	
	get_left();
	get_right();
		
	if(BIG_MAX / n < k){
		puts("-1");
		return 0;
	}
	
	for(auto v: wavey){
		if(v % n == 0)
			--k;
		
		if(k == 0){
			printf("%lld\n", v);
			exit(0);
		}
	}
	
	for(auto p: all_left){
		int cur = p.st;
		long long rest = (n - 1LL * cur * MAX_N % n) % n;
		
//		auto sta = mp(p.nd == 1 ? 0 : (cur % 10 + 1), 0);
//		auto en = mp(p.nd == 1 ? cur % 10 : 10, 0);
		
		int _l = lower_bound(all_right.begin(), all_right.end(), mp(mp(rest, p.nd), mp(p.nd == 1 ? 0LL : (cur % 10 + 1), 0LL))) - all_right.begin();
		int _r = upper_bound(all_right.begin(), all_right.end(), mp(mp(rest, p.nd), mp(p.nd == 1 ? cur % 10 : 10LL, 0LL))) - all_right.begin();
		
		if(cur < 10){
			_l = lower_bound(all_right.begin(), all_right.end(), mp(mp(rest, 0LL), mp(cur % 10 + 1, 0LL))) - all_right.begin();
			_r = upper_bound(all_right.begin(), all_right.end(), mp(mp(rest, 1LL), mp(cur % 10, 0LL))) - all_right.begin();
		}
		
/*		printf("for %d with search %d %d :: %d %d -> %d %d\n", p.st, rest, p.nd, sta.st, sta.nd, en.st, en.nd);
		for(int i = _l; i < _r; ++i)
			printf("[%d %d %d]", all_right[i].nd.nd, all_right[i].st.st, all_right[i].st.nd);
		puts("");
		
		for(int i = _l; i < _r; ++i)
			if(!is_wavey(1LL * p.st * MAX_N + all_right[i].nd.nd) || (1LL * p.st * MAX_N + all_right[i].nd.nd) % n != 0){
				printf("error for %d %d\n", p.st, p.nd);
				printf("[%d %d %d]\n", all_right[i].nd.nd, all_right[i].st.st, all_right[i].st.nd);
			}
*/
		if(_r - _l < k){
			k -= _r - _l;
			continue;
		}
		
		vector <int> all;
		for(int i = _l; i < _r; ++i)
			all.push_back(all_right[i].nd.nd);
		sort(all.begin(), all.end());
 
		printf("%lld\n", 1LL * p.st * MAX_N + all[k - 1]);
		exit(0);
	}
 
	puts("-1");
	return 0;
}