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
bool same(char c,char d){
	if(c == d) return true;
	return abs(c - d) == 2;
}
int n;
string s;
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> n >> s;
		bool ok = true;
		for(int i=0;i<n/2;i++){
			if(!same(s[i],s[n - 1 - i])){
				ok = false;
				puts("NO");
				break;
			}
		}
		if(ok) puts("YES");
	}
	return 0;
}