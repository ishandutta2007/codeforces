#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int N = 1e5 + 7;

int n, k;
int a[N];
vector <int> jobs[N];

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	
	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		jobs[a[i]].push_back(x);
	}
	
	int cnt = 0;
	vector <int> maybe;

	for(int i = 1; i <= k; ++i){
		if(jobs[i].size() == 0){
			++cnt;
			continue;
		}

		sort(jobs[i].begin(), jobs[i].end());
		jobs[i].pop_back();
		
		for(auto v: jobs[i])
			maybe.push_back(v);
	}
	
	LL res = 0LL;
	sort(maybe.begin(), maybe.end());
	
	maybe.resize(cnt);
	for(auto v: maybe)
		res += v;
	printf("%lld\n", res);
	return 0;
}