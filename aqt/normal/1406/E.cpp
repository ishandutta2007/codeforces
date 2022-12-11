#include <bits/stdc++.h>

using namespace std;

int N;
bool sieve[100005];
vector<int> pr;

int query(char c, long long n){
	cout << c << " " << n << endl;
	if(c == 'C'){
		return 0;
	}
	int t;
	cin >> t;
	return t;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int n = 2; n<=N; n++){
		if(!sieve[n]){
			pr.push_back(n);
			for(int k = 2*n; k<=N; k+=n){
				sieve[k] = 1;
			}
		}
		sieve[n] = 0;
	}
	for(int p : pr){
		if(p * p > N){
			break;
		}
		query('B', p);
		for(int k = p; k<=N; k+=p){
			sieve[k] = 1;
		}
	}
	int n = query('A', 1);
	int cnt = 0;
	for(int i = 1; i<=N; i++){
		cnt += !sieve[i];
	}
	if(cnt == n){
		while(pr.size()){
			for(int i = 0; i<=pr.size()/2; i++){
				query('B', pr[i]);
				for(int k = pr[i]; k<=N; k+=pr[i]){
					sieve[k] = 1;
				}
			}
			int t = query('A', 1);
			cnt = 0;
			for(int i = 1; i<=N; i++){
				cnt += !sieve[i];
			}
			if(t == cnt){
				pr.erase(pr.begin(), pr.begin()+(pr.size()/2) + 1);
			}
			else{
				for(int i = 0; i<=pr.size()/2; i++){
					if(query('A', pr[i]) == 1){
						return query('C', pr[i]);
					}
				}
			}
		}
		return query('C', 1);
	}
	else{
		int ans = 1;
		for(int p : pr){
			if(1LL*p*p <= N){
				for(long long k = p; k<=N; k *= p){
					if(query('A', k) == 1){
						ans *= p;
					}
					else{
						break;
					}
				}
			}
			else{
				if(query('A', p) == 2){
					ans *= p;
				}
			}
		}
		return query('C', ans);
	}
}