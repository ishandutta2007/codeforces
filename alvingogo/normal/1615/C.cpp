#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int main(){
	AquA;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s,t;
		cin >> s >> t;
		int a[2][2]={0};
		for(int i=0;i<n;i++){
			a[s[i]-'0'][t[i]-'0']++;
		}
		int ans=99999993;
		if(a[1][1]==a[0][0]+1){
			ans=min(ans,a[1][1]*2-1);
		}
		if(a[0][1]==a[1][0]){
			ans=min(ans,a[0][1]*2);
		}
		if(ans==99999993){
			cout << -1 << "\n";
		}
		else{
			cout << ans << "\n";
		}
	}
	return 0;
}