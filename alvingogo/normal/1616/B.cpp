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
		string s,t="";
		cin >> s;
		t+=s[0];
		for(int i=1;i<n;i++){
			if(s[i]>s[i-1] || (i==1 && s[i]==s[i-1])){
				break;
			}
			t+=s[i];
		}
		cout << t;
		reverse(t.begin(),t.end());
		cout << t << "\n";
	}
	return 0;
}