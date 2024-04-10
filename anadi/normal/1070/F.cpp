#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1e6 + 7;

int n, res;
vector <int> t[4];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		char s[5]; int val;
		scanf("%s %d", s, &val);
		
		int nr = (s[0] - '0') * 2 + s[1] - '0';
		t[nr].push_back(val);
	}
	
	for(int i = 0; i < 4; ++i)
		sort(t[i].begin(), t[i].end());
	
	for(int v: t[3])
		res += v;

	while(t[2].size() && t[1].size()){
		res += t[2].back() + t[1].back();
		t[1].pop_back(); t[2].pop_back();
	}
	
	while(t[1].size() || t[2].size()){
		if(t[1].size()){
			t[0].push_back(t[1].back());
			t[1].pop_back();
		}
		
		if(t[2].size()){
			t[0].push_back(t[2].back());
			t[2].pop_back();			
		}
	}
	
	int canTake = t[3].size();
	sort(t[0].begin(), t[0].end());

	while(canTake && t[0].size()){
		res += t[0].back();
		t[0].pop_back();
		canTake--;
	}
	
	printf("%d\n", res);
	return 0;
}