#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	int n, d, s;
	cin >> n >> d >> s;
	vector<pair<int,int>> A;
	vector<int> B;
	vector<int> C;
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		int c, f, l;
		cin >> c >> f >> l;
		if (l >= d and c > 0)
			A.push_back({f, c});
		if (l >= d and c == 0)
			B.push_back(f);
		if (l < d and c > 0)
			C.push_back(c);
		if (l < d and c == 0)
			cnt ++;
	}
	sort(B.begin(), B.end());
	for (int i = 1; i < B.size(); i++)
		B[i] = min(s+1, B[i] + B[i-1]);
	sort(A.begin(), A.end());
	int tA = 0, tC = 0;
	for (auto it : A)
		tA = min(n, tA + it.second);
	for (auto it : C)
		tC = min(n, tC + it);
	int maxrob = 0, fuel = 0;
	int lo = 0, hi = B.size() + 1;
	while (hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if (B[mid-1] <= s)
			lo = mid;
		else
			hi = mid;
	}
	if (lo > 0)
		maxrob = lo, fuel = B[lo-1];
	int justsum = 0, sum = 0, now = 0;
	for (auto it : A){
		now ++;
		justsum += it.first;
		sum = justsum;
		if (sum > s)
			break;
		int tmp = tA - (int)A.size() + now;
		tmp += tC - (int)C.size();
		int sumrob = (int)A.size() + (int)C.size();
		int mnm = min(tmp, cnt);
		sumrob += mnm;
		tmp -= mnm;
		if (tmp >= B.size())
			sumrob += B.size();
		else{
			sumrob += tmp;
			int lo = 0, hi = B.size() - tmp + 1;
			while (hi - lo > 1){
				int mid = (lo + hi) >> 1;
				if (B[mid-1] <= s - sum)
					lo = mid;
				else
					hi = mid;
			}
			sumrob += lo;
			if (lo > 0)
				sum += B[lo-1];
		}
		if (make_pair(maxrob, -fuel) < make_pair(sumrob, -sum)){
			maxrob = sumrob;
			fuel = sum;
		}
	}
	cout << maxrob << " " << fuel << endl;
}