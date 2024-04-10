#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <bitset>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans=0;
		for(int i=0;i<n;i++){
			ans+=(s[i]-'0');
			if(i!=n-1 && s[i]!='0'){
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}