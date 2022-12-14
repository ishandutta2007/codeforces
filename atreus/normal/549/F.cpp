#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 3e5 + 10;
const int maxk = 1e6 + 10;

int k, a[maxn], occur[maxk];
ll answer;

void find(int L, int R){
	if (R - L == 1)
		return;
	int mid = (L + R) >> 1;
	find(L, mid);
	find(mid, R);
	int mxsuf = 0, sumsuf = 0, mxpre = 0, sumpre = 0, ptr = mid - 1;
	for (int i = mid - 1; i >= L; i--){
		mxsuf = max(mxsuf, a[i]);
		sumsuf = (sumsuf + a[i]) % k;
		while (ptr < R - 1 and a[ptr + 1] <= mxsuf){
			ptr ++;
			sumpre = (sumpre + a[ptr]) % k;
			occur[sumpre] ++;
		}
		answer += occur[(mxsuf - sumsuf + k) % k];
	}
	sumpre = 0;
	for (int i = mid; i <= ptr; i++){
		sumpre = (sumpre + a[i]) % k;
		occur[sumpre] --;
	}
	mxsuf = 0, sumsuf = 0, mxpre = 0, sumpre = 0, ptr = mid;
	for (int i = mid; i < R; i++){
		mxpre = max(mxpre, a[i]);
		sumpre = (sumpre + a[i]) % k;
		while (ptr > L and a[ptr - 1] < mxpre){
			ptr --;
			sumsuf = (sumsuf + a[ptr]) % k;
			occur[sumsuf] ++;
		}
		answer += occur[(mxpre - sumpre + k) % k];
	}
	sumsuf = 0;
	for (int i = mid - 1; i >= ptr; i--){
		sumsuf = (sumsuf + a[i]) % k;
		occur[sumsuf] --;
	}
}

int main(){
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	find(0, n);
	cout << answer << endl;
}