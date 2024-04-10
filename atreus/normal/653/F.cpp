/**
 *    author:  Atrues
 *    created: 24.01.2019 17:36
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 5e5 + 100;

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
		pos[i] = (s[i] == ')');
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

int par[maxn], nex[maxn][20];

int get(int l, int r){
	int ret = 0;
	for (int i = 17; i >= 0; i--){
		if (nex[l][i] <= r){
			l = nex[l][i] + 1;
			ret += (1 << i);
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> s;
	buildSA();
	buildLCP();
	for (int i = 0; i < n; i++){
		if (i != 0)
			par[i] = par[i - 1];
		par[i] += (s[i] == '(') - (s[i] == ')');
	}
	par[n] = -(n + 1);
	stack<int> stck;
	stck.push(n);
	nex[n][0] = n;
	for (int i = n - 1; i >= 0; i--){
		int x = i == 0 ? 0 : par[i - 1];
		while (par[stck.top()] > x)
			stck.pop();
		nex[i][0] = stck.top();
		if (par[stck.top()] < x or par[i] < x)
			nex[i][0] = n;
		stck.push(i);
	}
	for (int i = 1; i <= 18; i++){
		for (int j = 0; j <= n; j++){
			if (nex[j][i - 1] == n)
				nex[j][i] = n;
			else
				nex[j][i] = nex[nex[j][i - 1] + 1][i - 1];
		}
	}
	ll answer = 0;
	for (int i = 0; i < n; i++){
		int idx = suf[i];
		int len = lcp[i];
		answer += get(idx, n - 1) - get(idx, idx + len - 1);
	}
	cout << answer << endl;
}