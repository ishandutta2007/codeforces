#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 150005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[maxn],b[maxn];
vector <int> ans;
int gcd(int x,int y){
	if(y == 0) return x;
	return gcd(y,x % y);
}
void fenjie(int x){
	for(int i=2;i * i <= x;i++){
		int cnt = 0;
		while(x % i == 0){
			x /= i;
			cnt++;
		}
		if(cnt > 0) ans.push_back(i);
	}
	if(x > 1){
		ans.push_back(x);
		x = 1;
	}
}
bool judge(int x){
	for(int i=2;i<=n;i++){
		if(a[i] % x > 0 && b[i] % x > 0) return false;
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	if(n == 1){
		printf("%d\n",a[1]);
		return 0;
	}
	fenjie(a[1]),fenjie(b[1]);
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	for(int i=0;i<ans.size();i++){
		if(judge(ans[i])){
			printf("%d\n",ans[i]);
			return 0;
		}
	}
	puts("-1");
	return 0;
}