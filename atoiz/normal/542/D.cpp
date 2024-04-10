#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef pair< ll, vector<ll> > itType;

ll A;
unordered_map< ll, vector<ll> > divMap;
unordered_map<ll, int> toIdx;
vector<ll> toVal(0);


ll check(ll n)
{
	if (n == 1) return -1;

//    if (n == 3) cout << "S" << endl;

    ll div = 2;
    ll root = sqrt(n);
    while (div <= root) {
		if (n % div == 0) {
			break;
		}
		++div;
    }

    if (div > root) { // n is prime
		return n;
    } else {
        while (n > 1 && n % div == 0) n /= div;
		if (n == 1) return div;
		else {
			return -1;
		}
    }

    return -1;
}

void initMap() // remember: 1 does not count
{
	ll p = check(A-1);
    if (p > 0) {
		if (divMap.find(p) == divMap.end()) divMap[p] = vector<ll>(0);
		divMap[p].push_back(A);
    }

	toIdx[A] = toVal.size();
	toVal.push_back(A);
	toIdx[1] = toVal.size();
	toVal.push_back(1);

	ll root = sqrt(A);

    for (ll i = 2; i <= root; ++i) {
        if (A % i == 0) {
			ll p1 = check(i-1);
			if (divMap.find(p1) == divMap.end()) divMap[p1] = vector<ll>(0);
			if (p1 > 0) {
				divMap[p1].push_back(i);
			}
			toIdx[i] = toVal.size();
			toVal.push_back(i);


			ll p2 = check(A/i - 1);
			if (divMap.find(p2) == divMap.end()) divMap[p2] = vector<ll>(0);
			if (i * i != A && p2 > 0) {
				divMap[p2].push_back(A/i);
			}
			if (i * i != A) {
				toIdx[A/i] = toVal.size();
				toVal.push_back(A/i);
			}
        }
    }
	if (divMap.find(-1) != divMap.end()) divMap.erase( divMap.find(-1) );
}

int main()
{
	cin >> A;
	initMap();

    vector< vector<ll> > dp(divMap.size() + 1, vector<ll>(toVal.size(), 0));

    dp[0][toIdx[A]] = 1;
    int i = 1;
    for (itType it : divMap) {
		vector<ll> v = it.second;
		for (int j = 0; j < toVal.size(); ++j) {
			for (ll val : v) {
				if (toVal[j] % val != 0) continue;
				dp[i][ toIdx[ toVal[j] / val ] ] += dp[i-1][j];
//				cout << i << ": " << toVal[j] << " / " << val << " = " << toVal[j]/val << ", " << dp[i-1][j] << endl;
			}
			dp[i][j] += dp[i-1][j];
//			cout << i << ": " << toVal[j] << ", " << dp[i-1][j] << endl;
		}
		++i;
    }

    cout << dp[divMap.size()][1] << endl;
}