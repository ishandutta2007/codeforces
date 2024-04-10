#include <iostream>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		cin >> n >> s;
		int l=-1,r=-1;
		for(int i=1;i<n;i++){
			if(s[i]!=s[i-1]){
				l=i;
				r=i+1;
				break;
			}
		}
		cout << l << " " << r << "\n";
	}
	return 0;
}