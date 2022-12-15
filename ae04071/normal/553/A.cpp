#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <utility>
#include <queue>
#include <functional>

#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;

const lli mod=1e9+7;

int n;
lli arr[1000],cache[1001],combi[2001][2001];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",arr+i);

	combi[0][0]=1;
	for(int i=1;i<=2000;i++) for(int j=0;j<=i;j++) {
		if(i==j || j==0) combi[i][j]=1;
		else combi[i][j] = (combi[i-1][j-1]+combi[i-1][j])%mod;
	}

	cache[0]=1;
	for(int i=1;i<n;i++) arr[i] += arr[i-1];
	for(int i=1;i<n;i++) {
		cache[i] = cache[i-1] * combi[arr[i]-1][arr[i]-arr[i-1]-1] % mod;
	}
	printf("%lld\n",cache[n-1]);
	
	
	return 0;
}