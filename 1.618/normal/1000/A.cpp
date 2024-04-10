#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
int n;
string s;
map <string,int> mp,mp2;
int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> s;
		mp[s]++;
	}
	for(int i=1;i<=n;i++){
		cin >> s;
		mp2[s]++;
	}
	int ans = 0;
	ans += abs(mp["XXXS"] - mp2["XXXS"]);
	ans += abs(mp["XXS"] - mp2["XXS"]);
	ans += abs(mp["XS"] - mp2["XS"]);
	ans += (abs(mp["S"] - mp2["S"]) + abs(mp["M"] - mp2["M"]) + abs(mp["L"] - mp2["L"])) / 2;
	printf("%d\n",ans);
	return 0;
}