#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#include <string>
#define maxn 150005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,cnt[35];
string s;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> s;
	for(int i=0;i<(int)s.size();i++){
		cnt[s[i] - 'a']++;
		if(cnt[s[i] - 'a'] > 1){
			puts("Yes");
			return 0;
		}
	}
	if(n == 1) puts("Yes");
	else puts("No");
	return 0;
}