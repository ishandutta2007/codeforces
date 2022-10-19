#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	bool ok = true;
		int count = 0;
		char cur = '-';
	for(int i=0; i<s.size(); i++){
		
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u'){
			cout << s[i];
			ok = true;
			cur = '-';
			count = 0;
		}else{
			if(cur == '-'){
				count++;
				cur = s[i];
				cout << s[i];
			}else{
				if(cur == s[i] && ok){
					count++;
					cur = s[i];
					cout << s[i];
				}else{
					ok = false;
					if(count < 2){
						cout << s[i];
						count++;
						
					}else{
						cout << " "<<s[i];
						count = 1;
						ok = true;
						cur = s[i];
					}
				}
			}
			
		}
	}
	return 0;
}