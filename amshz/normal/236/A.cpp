# include <bits/stdc++.h>

using namespace std;

map <char,int> mp;

int main(){
	string a;
	cin >> a;
	int t = 0;
	for (int i=0; i<a.size(); i++){
		mp[a[i]]++;
		if (mp[a[i]] == 1) t++;
	}
	if (t%2 == 0) cout << "CHAT WITH HER!";
	else cout << "IGNORE HIM!";
	cout << endl;
}