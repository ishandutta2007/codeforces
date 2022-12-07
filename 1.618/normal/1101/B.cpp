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
string s;
int ans;
int main(){
	ios::sync_with_stdio(false);
	cin >> s;
	int n = s.size();
	int i=0;
	for(i = 0;i < n;i++){
		if(s[i] == '[') break;
	}
	ans++;
	for(i = i + 1;i < n;i++){
		if(s[i] == ':') break;
	}
	ans++;
	if(i == n){
		puts("-1");
		return 0;
	}
	int j = n - 1;
	for(j = n - 1;j > i;j--){
		if(s[j] == ']') break;
	}
	ans++;
	for(j = j - 1;j > i;j--){
		if(s[j] == ':') break;
	}
	ans++;
	if(j <= i){
		puts("-1");
		return 0;
	}
	for(i = i + 1;i < j;i++){
		ans += (s[i] == '|');
	}
	printf("%d\n",ans);
	return 0;
}