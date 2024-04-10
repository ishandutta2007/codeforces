#include <bits/stdc++.h>
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
		int flag=0;
		for(int i=0;i<n/2;i++){
			if(s[i]=='0'){
				cout << i+1 << " " << n << " " << i+2 << " " << n << "\n";
				flag=1;
				break;
			}
		}
		if(flag==1){
			continue;
		}
		for(int i=n/2;i<n;i++){
			if(s[i]=='0'){
				cout << 1 << " " << i+1 << " " << 1 << " " << i << "\n";
				flag=1;
				break;
			}
		}
		if(flag==1){
			continue;
		}
		cout << 1 << " " << n-1 << " " << 2 << " " << n << "\n";
	}
	return 0;
}