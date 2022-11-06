#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <string>
#include <cmath>
#include <utility>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <stack>
#include <queue>
using namespace std;
#define rep(i,a,b) for(int i = int(a); i < (b); ++i)
#define rrep(i,a,b) for(int i = int(b)-1; i >= int(a); --i)
#define allof(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define max(a,b) ((a)<(b)?(b):(a))
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	vi a(n);
	rep(i,0,n)
		scanf("%d",&a[i]);
	sort(allof(a));

	int l = n/k;
	int an1 = n%k;
	int an0 = k-an1;

	int dp[5001][5001];
	dp[0][0] = dp[0][1] = dp[1][0] = 0;
	rep(i,0,an0+1)
		rep(j,i==0?2:i==1?1:0,an1+1){
			dp[i][j] = max(j?dp[i][j-1]+ a[l*(i+j-1)+j-1]-a[l*(i+j-1)+j-2] : 0
				,		i?dp[i-1][j]+ a[l*(i+j-1)+j]-a[l*(i+j-1)+j-1]: 0);
		}

	cout << a[n-1] - a[0] - dp[an0][an1] << endl;
}