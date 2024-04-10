#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int T = 3 * N + 7;

const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n;
int exam;

int type[N];
bool Free[N];
string cur[N];

set <int> S;
queue <int> who[2];

string toS(int x){
	string ret;
	while(x > 0){
		ret.pb(x%10 + '0');
		x /= 10;
	}
	
	reverse(ret.begin(), ret.end());
	return ret;
}

int toI(string s){
	for(int i = 0; i < s.size(); ++i)
		if(s[i] < '0' || s[i] > '9')
			return -1;
	
	if(s[0] == '0')
		return -1;

	int cur = 0;
	for(int i = 0; i < s.size(); ++i)
		cur *= 10, cur += s[i] - '0';
	return cur <= n ? cur : -1;
}

inline bool correct(int x, bool t){
	if(x == -1)	return false;
	return t ? x <= exam : x > exam;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> cur[i] >> type[i],
		exam += type[i];
	
	int res = n + 1;
	for(int i = 1; i <= n; ++i){
		int now = toI(cur[i]);

		if(now != -1){
			Free[now] = true;
			if(correct(now, type[i]))
				--res;
		}
	}
	
	if(res == 1){
		puts("0");
		return 0;
	}
	
	bool change = false;
	for(int i = 1; i <= n; ++i)
		if(!Free[i]){
			change = true;
			--res;
			break;
		}
	
	cout << res << "\n";
	if(!change){
		for(int i = 1; i <= n; ++i)
			if(!correct(toI(cur[i]), type[i])){
				cout << "move " << cur[i] << " " << toS(n + 1) << "\n";
				Free[toI(cur[i])] = false;
				cur[i] = toS(n + 1);
				--res;
				break;
			}
	}

	for(int i = 1; i <= n; ++i){
		if(!Free[i])
			S.insert(i);

		if(!correct(toI(cur[i]), type[i]) && toI(cur[i]) != -1)
			who[type[i]].push(i);
	}

	for(int i = 1; i <= n; ++i)
		if(!correct(toI(cur[i]), type[i]) && toI(cur[i]) == -1)
			who[type[i]].push(i);

	while(res--){
		if(*(S.begin()) <= exam){
			int k = who[1].front();
			cout << "move " << cur[k] << " " << *S.begin() << "\n";
			
			who[1].pop();
			S.erase(S.begin());
			if(toI(cur[k]) != -1)
				S.insert(toI(cur[k]));
		}
		else{
			int k = who[0].front();
			cout << "move " << cur[k] << " " << *S.begin() << "\n";
			
			who[0].pop();
			S.erase(S.begin());
			if(toI(cur[k]) != -1)
				S.insert(toI(cur[k]));
		}
	}

	return 0;
}