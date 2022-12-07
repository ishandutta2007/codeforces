#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector <ll> ans;
ll n;
ll calc(ll k){
	ll num = n / k;
	return num + (num - 1) * num / 2 * k;
}
int main(){
	scanf("%I64d",&n);
	for(int i=1;i * i <= n;i++){
		if(n % i == 0){
			ans.push_back(calc(i));
			if(i * i != n) ans.push_back(calc(n / i));
		}
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<(int)ans.size();i++){
		printf("%I64d%c",ans[i],i == (int)ans.size() - 1 ? '\n' : ' ');
	}
	return 0;
}