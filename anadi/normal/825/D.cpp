#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PII pair <int, int>

string a, b;
int cnt[30];
int cur[30];
vector <int> pos;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> a >> b;
	for(int i = 0; i < a.size(); ++i)
		if(a[i] == '?')
			pos.pb(i);
		else
			cur[a[i] - 'a']++;
	
	for(int i = 0; i < b.size(); ++i)
		cnt[b[i] - 'a']++;
	
	for(int j = 1; j <= a.size(); ++j){
		int miss = 0;
		for(int i = 0; i < 26; ++i)
			miss += max(0, cnt[i] * j - cur[i]);
		
		if(miss > pos.size())
			break;

		for(int i = 0; i < 26; ++i)
			while(cnt[i] * j > cur[i]){
				a[pos.back()] = 'a' + i;
				++cur[i];
				pos.pop_back();
			}
	}
	
	while(pos.size() > 0){
		a[pos.back()] = 'a';
		pos.pop_back();
	}

	cout << a;
	return 0;
}