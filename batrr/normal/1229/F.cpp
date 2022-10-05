#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 100500;

int n;
int L[N], R[N];
ll ans = 1e18;


ll check(ll X){
	ll shiftA = 0, shiftB = 0;
	multiset< ll > A;
	multiset< ll > B;
	for(int i = 0; i < n + n + n; i++){
		A.insert(X);
		B.insert(X);
	}
	ll res = 0;
	for(int i = 0; i < n; i++){
		shiftA += L[i];
		shiftB += R[i];                  
		ll zeroL = *A.rbegin() + shiftA;
		ll zeroR = *B.begin() + shiftB;
		if(zeroL <= 0 && 0 <= zeroR){
			A.insert(-shiftA);
			B.insert(-shiftB);
		}	
		if(0 < zeroL){        
			res += *A.rbegin() + shiftA;
			B.insert(*A.rbegin() + shiftA - shiftB);
			A.erase(A.find(*A.rbegin()));
			A.insert(-shiftA);
			A.insert(-shiftA);
		}
		if(zeroR < 0){
			res -= *B.begin() + shiftB;
			A.insert(*B.begin() + shiftB - shiftA);
			B.erase(B.find(*B.begin()));
			B.insert(-shiftB);
			B.insert(-shiftB);
		}
	}
	while(*A.rbegin() + shiftA > X){
		res += *A.rbegin() + shiftA - X;
		A.erase(A.find(*A.rbegin()));
	}
	while(*B.begin() + shiftB < X){
		res += X - *B.begin() - shiftB;
		B.erase(B.find(*B.begin()));
	}
	ans = min(ans, res);
	return res;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x >> R[i] >> L[i];
		L[i] = x - L[i];
		R[i] = x - R[i];
	}
	ll l = -1225000000 - 1000, r = 1225000000 + 1000;
	while(l <= r){
		ll m = (l + r) / 2;
		if(check(m) > check(m + 1))
			l = m + 1;
		else
			r = m - 1;
	}
	for(ll i = l - 10; i < r + 10; i++)
		check(i);
	cout << ans;
	return 0;
}