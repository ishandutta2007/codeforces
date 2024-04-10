#include<bits/stdc++.h>
using namespace std;

bool Vowel(char c){
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'n';
}

int main(){
	string s;
	cin >> s;
	int n = s.size();
	if(!Vowel(s[n - 1])){
		cout << "NO\n";
		return 0;
	}
	for(int i = 0; i < n - 1; i++){
		if(!Vowel(s[i]) && (!Vowel(s[i + 1]) || s[i + 1] == 'n')){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}