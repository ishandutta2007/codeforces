#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10;

ll l[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> l[i];
	string s;
	cin >> s;
	
	ll answer = 0;
	ld swim = 0, walk = 0;
	bool anywater = 0, anygrass = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == 'G'){
			if (2ll * swim <= l[i]){
				l[i] -= 2ll * swim;
				answer += 4ll * swim; 
				walk += 2ll * swim;
				swim = 0;
			}
			else{
				answer += l[i] * 2;
				swim -= 1. * l[i] / 2;
				walk += l[i];
				continue;
			}

			anygrass = 1;
			walk += 1. * l[i] / 2;
			answer += l[i] * 3;
		}
		else if (s[i] == 'W'){
			anywater = 1;
			swim += 1. * l[i] / 2;
			answer += l[i] * 2;
		}
		else{
			if (2ll * swim <= l[i]){
				l[i] -= 2ll * swim;
				answer += 4ll * swim; 
				swim = 0;
			}
			else{
				answer += l[i] * 2;
				swim -= 1. * l[i] / 2;
				continue;
			}

			if (2 * walk <= l[i]){
				l[i] -= 2ll * walk;
				answer += 6ll * walk;
				walk = 0;
			}
			else{
				answer += l[i] * 3;
				walk -= 1. * l[i] / 2;
				continue;
			}
			
			if (anywater)
				answer += l[i] * 4;
			else
				answer += l[i] * 6;
		}
	}
	cout << answer << endl;
}