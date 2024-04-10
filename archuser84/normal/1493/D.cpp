#include <bits/stdc++.h>

using namespace std;

int m = 1e9 + 7;

vector<int> processFactors(int x, map<int,int> &factors){
	int f = 2;
	int tmp = x;
	vector<int> ret;
	while(f <= sqrt(tmp)){
		if(x % f == 0) ret.push_back(f);
		while(x % f == 0){
			x /= f;
			if(!factors.count(f)) factors[f] = 0;
			factors[f]++;
		}
		f++;
	}
	if(x > 1){
		if(!factors.count(x)) factors[x] = 0;
		factors[x]++;
		ret.push_back(x);
	}

	return ret;
}

void merge(map<int,int> &L, map<int,int> &R, map<int,int> &T, vector<int> &primes){
	for(int i=0;i<primes.size();i++){
		if (L.count(primes[i]) + R.count(primes[i]) == 2)
			T[primes[i]] = min(L[primes[i]],R[primes[i]]);
	}
}

vector<int> combine(int k, int x, vector<map<int,int>> &tree, int n){
	k += n;
	auto primes = processFactors(x,tree[k]);

	for(k /= 2; k >= 1; k /= 2){
		if (2*k+1 >= 2*n) continue;
		if (tree[2*k].size() == 0 || tree[2*k+1].size() == 0) continue;

		merge(tree[2*k],tree[2*k+1],tree[k],primes);
	}
	return primes;
}

long long mypow(long long x, int e, int mod)
{
    if(e == 0) return 1;
    long long ret = mypow(x, e/2, mod);
    ret = ret*ret % mod;
    if(e%2 == 1) ret = ret*x % mod;
    return ret;
}

int main(){
	int n,q;
	cin >> n >> q;
	vector<map<int,int>> tree (2*n,map<int,int>());

	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		processFactors(x,tree[i+n]);
	}

	for(int i=n-1;i>=1;i--){
		vector<int> elements;
		for(auto const& imap: tree[2*i]){
			elements.push_back(imap.first);
		}
		for(auto const& imap: tree[2*i+1]){
			elements.push_back(imap.first);
		}

		merge(tree[2*i],tree[2*i+1],tree[i],elements);
	}

	long long int total = 1;
	for(auto const& imap: tree[1]){
		total *= mypow(imap.first,imap.second,m);
		total %= m;
	}

	auto c = map<int,int> (tree[1]);

	while(q--){
		int i,x;
		cin >> i >> x;

		auto primes = combine(i-1,x,tree,n);
		for(int i=0;i<primes.size();i++){
			if (c.count(primes[i]))
				total *= mypow(primes[i],tree[1][primes[i]] - c[primes[i]],m);
			else
				total *= mypow(primes[i],tree[1][primes[i]],m);
			total %= m;
			c[primes[i]] = tree[1][primes[i]];
		}

		/*long long int total = 1;
		for(auto const& imap: tree[1]){
			total *= (int)(pow(imap.first,imap.second));
			total %= m;
		}*/

		cout << total << endl;
	}
	return 0;
}