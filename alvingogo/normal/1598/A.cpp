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
		string a,b;
		cin >> a >> b;
		int flag=0;
		for(int i=0;i<n;i++){
			if(a[i]=='1' && b[i]=='1'){
				flag=1;
			}
		}
		if(flag){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
		
	return 0;
}