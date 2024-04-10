#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, m;
int pop[N], nast[N];

string s;
vector <int> ind;

void usun(int x){
	pop[nast[x]] = pop[x];
	nast[pop[x]] = nast[x];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	n = s.size();
	
	for(int i = 0; i + 1 < s.size(); ++i)
		if(s[i] != s[i + 1])
			ind.pb(i);
	
	for(int i = 0; i < s.size(); ++i){
		pop[i] = i - 1;
		nast[i] = i + 1;
	}
	
	int res = 0;
	while(ind.size()){
		++res;
		vector <int> poss;

		for(int v: ind){
			int x = v, y = nast[v];
			if(pop[x] != -1 && pop[x] != x)
				poss.push_back(pop[x]);
			usun(x), usun(y);
		}
		
		ind.clear();
		for(int v: poss)
			if(nast[v] < s.size() && s[v] != s[nast[v]])
				ind.push_back(v);
	}
	
	cout << res;
	return 0;
}