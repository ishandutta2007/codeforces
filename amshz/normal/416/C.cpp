# include <bits/stdc++.h>

using namespace std;

const int xn = 1e3+10;
pair <int, pair<int,int> > a[xn];
pair <int,int> b[xn];
bool f[xn];

bool cmp(pair <int,int> q, pair <int,int> w){
	return q.first > w.first;
}

int main(){
	int n, k;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i].first >> a[i].second.first, a[i].second.second = i;
	cin >> k;
	for (int i=0; i<k; i++) cin >> b[i].first, b[i].second = i;
	int p = 0;
	sort(a, a+n), sort(b, b+k);
	vector < pair <int,int> > vec;
	int ans = 0;
	pair <int,int> pr;
	for (int i=0; i<k; i++){
		int mx = -1;
		int dx = -1;
		while (a[p].first <= b[i].first and p < n){
			if (a[p].second.first > mx and f[p] == 0) mx = a[p].second.first, dx = p;
			p++;
		}
		mx = dx;
		if (mx >  -1 and mx < n and a[mx].first <= b[i].first and f[mx] == 0) pr.first = a[mx].second.second+1, pr.second = b[i].second+1, ans += a[mx].second.first, vec.push_back(pr), f[mx] = true;
		p = 0;
	}
	cout << vec.size() << ' ' << ans << endl;
	for (int i=0; i<vec.size(); i++) cout << vec[i].first << ' ' << vec[i].second << endl;
	return 0;
}