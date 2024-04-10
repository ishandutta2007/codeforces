#include <bits/stdc++.h>

using namespace std;

const int N = 1007;

int n, m;
int cnt;
bool was[N];
int licz[N];
string word;
bool blocked[N];

bool ok(string a){
	for(int i = 0; i < m; ++i)
		if(word[i] == '*'){
			if(blocked[a[i] - 'a'])
				return false;
		}
		else if(word[i] != a[i])
			return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> m;
	cin >> word;
	
	for(int i = 0; i < m; ++i)
		if(word[i] != '*')
			blocked[word[i] - 'a'] = true;
	
	cin >> n;
	for(int i = 0; i < n; ++i){
		string s; cin >> s;
		if(!ok(s))
			continue;
		
		++cnt;
		for(int j = 0; j < m; ++j)
			if(word[j] == '*' && !was[s[j] - 'a']){
				licz[s[j] - 'a']++;
				was[s[j] - 'a'] = true;
			}
		
		for(int j = 0; j < 50; ++j)
			was[j] = false;
	}
	
	int res = 0;
	for(int i = 0; i < 26; ++i)
		if(cnt == licz[i])
			++res;
	cout << res;
	return 0;
}