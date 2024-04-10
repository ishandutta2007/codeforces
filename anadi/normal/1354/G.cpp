#include <bits/stdc++.h>

using namespace std;

typedef long double T;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int getInt(int a = INT_MIN, int b = INT_MAX){
	static mt19937 rng((uint64_t)(new char));
	return uniform_int_distribution <int> (a, b)(rng);
}

int ask(vector <int> a, vector <int> b){
	printf("? %d %d\n", (int)a.size(), (int)b.size());
	for(auto v: a)
		printf("%d ", v);
	puts("");

	for(auto v: b)
		printf("%d ", v);
	puts("");	
	fflush(stdout);

	string ans;
	cin >> ans;
	
	if(ans == "FIRST")
		return 1;
	if(ans == "SECOND")
		return -1;
	
	if(ans == "WASTED")
		exit(0);
	return 0;
}

vector <int> vec(int from, int to){
	vector <int> ret;
	for(int i = from; i <= to; ++i)
		ret.push_back(i);
	return ret;
}

bool ask2(int from, int to, int from2, int to2){
	return ask(vec(from, to), vec(from2, to2));
}

void write(int v){
	printf("! %d\n", v);
	fflush(stdout);
}

int n, k;

bool check(){
	vector <int> all(n - 1);
	for(int i = 2; i <= n; ++i)
		all[i - 2] = i;
	
	for(int i = 0; i + 1 < n; ++i)
		swap(all[getInt(0, i)], all[i]);
	
	int qrs = 28;
	while(qrs-- && all.size()){
		if(ask({1}, {all.back()}) == -1)
			return false;
		all.pop_back();
	}
	
	return true;
}

void solve(){
	scanf("%d %d", &n, &k);
	
	if(!check()){
		write(1);
		return;
	}
	
	int pt = 1;
	while(2 * pt <= n){
		if(ask2(1, pt, pt + 1, 2 * pt) == 1)
			break;
		pt *= 2;
	}
	
	int s = pt + 1, e = min(n, 2 * pt);
	while(s < e){
		int mid = (s + e) / 2;
		int l = mid - s;
		if(ask2(1, 1 + l, s, s + l) == 1)
			e = mid;
		else
			s = mid + 1;
	}
	
	write(s);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}