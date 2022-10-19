#include<bits/stdc++.h>
using namespace std;

void UpperToLower(string &s, int n){
	for(int i = 0; i < n; i++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			s[i] += ('a' - 'A');
		}
	}
}

void DeleteVowel(string &s, int &n){
	for(int i = 0; i < n; i++){
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y'){
			for(int j = i; j < n - 1; j++){
				s[j] = s[j + 1];
			}
			n--;
			i--;
		}
	}
}

void OutWithDots(string &s, int n){
	for(int i = 0; i < n; i++){
		cout << "." << s[i];
	}
	cout << endl;
}

int main(){
	string s;
	cin >> s;
	int n = s.size();
	UpperToLower(s, n);
	DeleteVowel(s, n);
	OutWithDots(s, n);
	return 0;
}