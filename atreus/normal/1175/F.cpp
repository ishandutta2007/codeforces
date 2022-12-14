#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

const int maxn = 3e5 + 10;
const int maxl = 20;

int a[maxn], LOG[maxn], RMQ[maxl][maxn], LMQ[maxl][maxn], nex[maxn], dpn[maxn], pre[maxn], dpp[maxn], last[maxn];

ll answer = 0;

void find(int L, int R){
	if (L >= R)
		return;
	int len = LOG[R - L];
	int fi = RMQ[len][L], se = LMQ[len][R-1];
	if (a[fi] < a[se])
		fi = se;
	
//	cout << "find " << L << " " << R << " -> " << fi << endl;
	if (fi - L < R - fi){
		int now = min(dpn[fi], R);
		if (now - fi == a[fi]){
			answer ++;
//			cout << "[" << fi << ", " << now << ")\n";
		}
		for (int i = fi - 1; i >= max(L, fi - a[fi] + 1) and now > fi; i--){
			now = min(now, nex[i]);
			if (now > fi and now - i == a[fi]){
				answer ++;
//				cout << "[" << i << ", " << now << ")\n";
			}
		}
	}
	else{
		int now = max(L - 1, dpp[fi]);
		if (fi - now == a[fi]){
			answer ++;
//			cout << "[" << now+1 << ", " << fi+1 << ")\n";
		}
		for (int i = fi + 1; i < min(R, fi + a[fi]) and now < fi; i++){
			now = max(now, pre[i]);
			if (fi > now and i - now == a[fi]){
				answer ++;
//				cout << "[" << now+1 << ", " << i + 1 << ")\n";
			}
		}
	}
	find(L, fi);
	find(fi + 1, R);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	// RMQ
	for (int len = 1; len <= n; len++)
		LOG[len] = log2(len);
	for (int i = 0; i < n; i++){
		RMQ[0][i] = i;
		LMQ[0][i] = i;
	}
	for (int i = 0; i < 18; i++){
		for (int j = 0; j + (1 << i) < n; j++){
			int fi = RMQ[i][j], se = RMQ[i][(1 << i) + j];
			if (a[fi] >= a[se])
				RMQ[i + 1][j] = fi;
			else
				RMQ[i + 1][j] = se;
		}
		for (int j = (1 << i); j < n; j++){
			int fi = LMQ[i][j], se = LMQ[i][j - (1 << i)];
			if (a[fi] > a[se])
				LMQ[i + 1][j] = fi;
			else
				LMQ[i + 1][j] = se;
		}
	}
	// Find Next and Prev
	memset(last, -1, sizeof last);
	for (int i = n - 1; i >= 0; i--){
		nex[i] = (last[a[i]] == -1 ? n : last[a[i]]);
		dpn[i] = (i == n - 1 ? n : min(nex[i], dpn[i + 1]));
		last[a[i]] = i;
	}
	memset(last, -1, sizeof last);
	for (int i = 0; i < n; i++){
		pre[i] = last[a[i]];
		dpp[i] = (i == 0 ? -1 : max(pre[i], dpp[i - 1]));
		last[a[i]] = i;
	}
	find(0, n);
	cout << answer << endl;
}