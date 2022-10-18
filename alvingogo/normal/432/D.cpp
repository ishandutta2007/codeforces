#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstring>
#include <set>
#include <map>
#define fastio cin.tie(0);ios_base::sync_with_stdio(false);cout.tie(0);
using namespace std;

int main(){
	fastio;
	string s;
	cin >> s;
	int n=s.length();
	vector<int> kmp(n+1),dp(n+1),l;
	s="$"+s;
	kmp[0]=-1;
	kmp[1]=0;
	for(int i=2;i<=n;i++){
		int w=kmp[i-1];
		while(w>=0 && s[w+1]!=s[i]){
			w=kmp[w];
		}
		kmp[i]=w+1;
	}
	for(int i=n;i>0;i--){
		dp[i]++;
		dp[kmp[i]]+=dp[i];
	}
	int w=n;
	while(w>0){
		l.push_back(w);
		w=kmp[w];
	}
	int m=l.size();
	cout << m << endl;
	for(int i=m-1;i>=0;i--){
		cout << l[i] << " " << dp[l[i]] << "\n";
	}
	return 0;
}