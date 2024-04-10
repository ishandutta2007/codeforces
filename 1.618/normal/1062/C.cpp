#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define mp make_pair
#define maxn 100005
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q;
char s[maxn];
int sum[maxn];
int modpow(int x,int y){
	int res = 1;
	while(y){
		if(y & 1) res = (ll)res * x % mod;
		y >>= 1;
		x = (ll)x * x % mod;
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",s + 1);
	for(int i=1;i<=n;i++){
		sum[i] = sum[i - 1] + (s[i] - '0');
	}
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int cnt = sum[r] - sum[l - 1],len = r - l + 1;
		printf("%d\n",(modpow(2,len) - modpow(2,len - cnt) + mod) % mod);
	}
	return 0;
}