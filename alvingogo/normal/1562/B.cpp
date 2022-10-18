#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

int main(){
	fastio;	
	int t;
	cin >> t;
	while(t--){
		string s;
		int k;
		cin >> k >> s;
		int flag=0;
		int a=0,b=0;
		for(int i=0;i<k;i++){
			if(s[i]=='1' || s[i]=='4' || s[i]=='6' || s[i]=='8' || s[i]=='9'){
				cout << 1 << "\n";
				cout << s[i] << "\n";
				flag=1;
				break;
			}
		}
		if(flag==1){
			continue;
		}
		for(int i=0;i<k;i++){
			if(i!=0 && (s[i]=='2' || s[i]=='5')){
				flag=1;
				cout << 2 << "\n";
				cout << s[i-1] << s[i] << "\n";
				break;
			}
			if(s[i]=='3'){
				a++;
			}
			else if(s[i]=='7'){
				b++;
			}
		}
		if(flag==1){
			continue;
		}
		if(a>1){
			cout << 2 << "\n" << 33 << "\n";
			continue;
		}
		else if(b>1){
			cout << 2 << "\n" << 77 << "\n";
			continue;
		}
		else{
			if(s[0]=='2'){
				cout << 2 << "\n" << 27 << "\n";
				continue;
			}
			else if(s[0]=='5'){
				cout << 2 << "\n" << 57 << "\n";
				continue;
			}
		}
	}
	return 0;
}