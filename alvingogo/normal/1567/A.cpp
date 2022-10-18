#include <iostream>
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
		int y=0;
		for(int i=0;i<n;i++){
			if(s[i]=='U'){
				y=1;
				break;
			}
			else if(s[i]=='D'){
				y=2;
				break;
			}
		}
		if(y==0){
			for(int i=0;i<n;i++){
				if(i%2==0){
					cout << "L";
				}
				else{
					cout << "R";
				}
			}
			cout << "\n";
			continue;
		}
		if(y==1){
			int j=0;
			for(int i=0;i<n;i++){
				if(s[i]=='U'){
					cout << "D";
				}
				else if(j%2==0){
					cout << "L";
					j++;
				}
				else{
					cout << "R";
					j++;
				}
			}
			cout << "\n";
			continue;
		}
		if(y==2){
			int j=0;
			for(int i=0;i<n;i++){
				if(s[i]=='D'){
					cout << "U";
				}
				else if(j%2==0){
					cout << "L";
					j++;
				}
				else{
					cout << "R";
					j++;
				}
			}
			cout << "\n";
			continue;
		}
	}
	return 0;
}