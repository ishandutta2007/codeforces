/**
 *    author:  Atrues
 *    created: 25.01.2019 16:46
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 10;

int c[maxn], mark[maxn], pnt[maxn];
vector <int> ans1, ans2;

void find(vector<ll> &a, vector<ll> &b){
	int n = a.size();
	int ptr = 0;
	int i, j;
	memset(mark, -1, sizeof mark);
	for (i = 0; i < n; i++){
		while (ptr < n - 1 and a[ptr + 1] <= b[i])
			ptr ++;
		c[i] = b[i] - a[ptr];
		pnt[i] = ptr;
		if (mark[c[i]] != -1){
			j = mark[c[i]];
			break;
		}
		mark[c[i]] = i;
	}
	for (int k = pnt[j] + 1; k <= pnt[i]; k++)
		ans1.push_back(k);
	for (int k = j + 1; k <= i; k++)
		ans2.push_back(k);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <ll> fi, se;
	ll parfi = 0, parse = 0;
	fi.push_back(parfi), se.push_back(parse);
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		parfi += x;
		fi.push_back(parfi);
	}
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		parse += x;
		se.push_back(parse);
	}
	if (parfi >= parse)
		find(fi, se);
	else{
		find(se, fi);
		swap(ans1, ans2);
	}
	cout << ans1.size() << '\n';
	for (auto it : ans1)
		cout << it << " ";
	cout << '\n';
	cout << ans2.size() << '\n';
	for (auto it : ans2)
		cout << it << " ";
}