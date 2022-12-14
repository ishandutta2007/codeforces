/**
 *    author:  Atreus
 *    created: 07.02.2019 11:39
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 21;
const int maxn = 1500 + 10;
int n;
string s;

int pos[maxn], suf[maxn], tmp[maxn];

int gap;
bool sufCmp(int i,int j){
	if (pos[i] != pos[j])
		return pos[i] < pos[j];
	i += gap, j += gap;
	return (i < n && j < n) ? pos[i] < pos[j] : i > j;
}

void buildSA(){
	for (int i = 0; i < n; i++){
		suf[i] = i;
		pos[i] = (s[i] - 'a');
	}
	for (gap = 1; ; gap *= 2){
		sort(suf, suf + n, sufCmp);
		for (int i = 0; i < n - 1; i++)
			tmp[i + 1] = tmp[i] + sufCmp(suf[i], suf[i + 1]);
		for (int i = 0; i < n; i++)
			pos[suf[i]] = tmp[i];
		if (tmp[n - 1] == n - 1)
			break;
	}
}

int lcp[maxn];

void buildLCP(){
	for (int i = 0, k = 0; i < n; i++){
		if (pos[i] != n - 1){
			for (int j = suf[pos[i] + 1]; s[i + k] == s[j + k];)
				k ++;
			lcp[pos[i] + 1] = k;
			if (k > 0) 
				k --;
		}
	}
}

int par[maxn], par2[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	string goods;
	int k;
	cin >> s >> goods >> k;
	n = s.size();
	buildSA();
	buildLCP();
	for (int i = 0; i < n; i++){
		par[i] = (goods[int(s[i] - 'a')] == '0');
		if (i > 0)
			par[i] += par[i - 1];
		par2[i] = i == 0 ? 0 : par[i - 1];
	}
	int answer = 0;
	for (int i = 0; i < n; i++){
		int lo = -1, hi = n - suf[i];
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (par[suf[i] + mid] - par2[suf[i]] <= k)
				lo = mid;
			else
				hi = mid;
		}
		answer += max(hi - lcp[i], 0);
	}
	cout << answer << endl;
}