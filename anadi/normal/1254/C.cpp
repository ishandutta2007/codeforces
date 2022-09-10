#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

LL ask1(int a, int b, int c){
	printf("1 %d %d %d\n", a, b, c);
	fflush(stdout);
	
	LL ans;
	scanf("%lld", &ans);
	return ans;
}

int ask2(int a, int b, int c){
	printf("2 %d %d %d\n", a, b, c);
	fflush(stdout);
	
	int ans;
	scanf("%d", &ans);
	return ans;
}

int n;

vector <int> solve(int s, int e, vector <int> cur){
	vector <PLL> tmp;
	vector <int> Left, Right;

	for(auto v: cur)
		tmp.push_back({ask1(s, e, v), v});
	sort(tmp.begin(), tmp.end());
	
	for(int i = 0; i + 1 < (int)tmp.size(); ++i){
		if(ask2(s, tmp[i].nd, tmp[i + 1].nd) < 0)
			Left.push_back(tmp[i].nd);
		else
			Right.push_back(tmp[i].nd);
	}
	
	if(tmp.size())
		Left.push_back(tmp.back().nd);
	
	while(Right.size()){
		Left.push_back(Right.back());
		Right.pop_back();
	}
	
	return Left;
}

int main(){
	scanf("%d", &n);
	vector <int> Left, Right;
	
	for(int i = 3; i <= n; ++i){
		int cur = ask2(1, 2, i);
		if(cur > 0)
			Left.push_back(i);
		else
			Right.push_back(i);
	}
	
	vector <int> ans1 = solve(1, 2, Left);
	vector <int> ans2 = solve(2, 1, Right);
	
	vector <int> ans = {1};
	while(ans2.size()){
		ans.push_back(ans2.back());
		ans2.pop_back();
	}
	
	ans.push_back(2);
	while(ans1.size()){
		ans.push_back(ans1.back());
		ans1.pop_back();
	}

	printf("0 ");
	for(auto v: ans)
		printf("%d ", v);
	puts("");
	fflush(stdout);
	return 0;
}