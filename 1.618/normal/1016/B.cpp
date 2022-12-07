#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 1005
using namespace std;
typedef long long ll;
int n,m,q,sum[maxn];
string s,t;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	cin >> s >> t;
	if(n < m){
		for(int i=1;i<=q;i++){
			int x,y;
			cin >> x >> y;
			printf("0\n");
		}
		return 0;
	}
	for(int i=1;i<=n - m + 1;i++){
		if(s.substr(i-1,m) == t) sum[i] = sum[i-1] + 1;
		else sum[i] = sum[i-1];
	}
	for(int i=n - m + 2;i<=n;i++) sum[i] = sum[i-1];
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		if(y - x + 1 < m) printf("0\n");
		else if(x == 0) printf("%d\n",sum[y - m + 1]);
		else printf("%d\n",sum[y - m + 1] - sum[x-1]);
	}
	return 0;
}