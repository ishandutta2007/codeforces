#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 300005
using namespace std;
typedef long long ll;
int n,k,a[maxn],b[maxn],cnt[maxn];
string s;
void calc(int i){
	k = 0;
	for(int j=0;j<s.size();j++){
		if(s[j] == '(') k++;
		else{
			if(k == 0) a[i]++;
			else k--;
		}
	}
	b[i] = k;
	if(k == 0) cnt[a[i]]++;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> s;
		calc(i);
	}
	ll ans = 0;
	for(int i=1;i<=n;i++){
		if(a[i]) continue;
		ans += cnt[b[i]];
	}
	cout << ans << endl;
	return 0;
}