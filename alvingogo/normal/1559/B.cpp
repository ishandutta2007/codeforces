#include <iostream>
#include <vector>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);cout.tie(0);
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
		int r=-1;
		for(int i=0;i<n;i++){
			if(s[i]!='?'){
				if(s[i]=='B'){
					for(int j=i-1;j>=0;j--){
						if((i-j)%2){
							s[j]='R';
						}
						else{
							s[j]='B';
						}
					}
				}
				else{
					for(int j=i-1;j>=0;j--){
						if((i-j)%2){
							s[j]='B';
						}
						else{
							s[j]='R';
						}
					}
				}	
				r=i;
				break;
			}
		}
		if(r==-1){
			s[0]='B';
			r=0;
		}
		for(int i=r+1;i<n;i++){
			if(s[i]=='?'){
				if(s[i-1]=='B'){
					s[i]='R';
				}
				else{
					s[i]='B';
				}
			}
		}
		cout << s << "\n";
	}
		
	return 0;
}