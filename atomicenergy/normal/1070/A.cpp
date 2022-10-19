#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 5005;
static ll dp[505][maxn];
static ll para[505][maxn];
static ll parb[505][maxn];
static ll parc[505][maxn];
ll s, d;

int main(){
	std::cin >> d >> s;
	
	memset(dp, -1, sizeof(dp));
	
	std::queue<int> qa, qb;
	qa.push(0);
	qb.push(s);
	
	while(!qa.empty()){
		int frd = qa.front();
		int frs = qb.front();
		qa.pop();
		qb.pop();
		
		for(int i = 0; i < 10; i++){
			if(frs - i >= 0 and dp[(frd * 10 + i) % d][frs - i] == -1){
				dp[(frd * 10 + i) % d][frs - i] = dp[frd][frs] + 1;
				qa.push((frd * 10 + i) % d);
				qb.push(frs - i);
				para[(frd * 10 + i) % d][frs - i] = frd;
				parb[(frd * 10 + i) % d][frs - i] = frs;
				parc[(frd * 10 + i) % d][frs - i] = i;
			}
		}
	}
	
	if(dp[0][0] == -1){
		std::cout << -1 << std::endl;
		return 0;
	}
	
	int pa = 0;
	int pb = 0;
	
	std::string res = "";
		
	for(int i = 0; i < dp[0][0]; i++){
		res.push_back((char) ('0' + parc[pa][pb]));
		int tpa = para[pa][pb];
		int tpb = parb[pa][pb];
		pa = tpa, pb = tpb;
	}
	
	std::reverse(res.begin(), res.end());
	std::cout << res << std::endl;
}