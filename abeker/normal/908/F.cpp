#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 5;

int N;
int x[MAXN];
char clr[MAXN];
vector <int> v[300];
int dist[300];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %c", x + i, clr + i);
}

ll calc(int lo, int hi) {
	int curr = x[hi] - x[lo];
	vector <int> red, blue;
	red.push_back(x[lo]);
	blue.push_back(x[lo]);
	for (int i = lo + 1; i < hi; i++) 
		if (clr[i] == 'R')
			red.push_back(x[i]);
		else
			blue.push_back(x[i]);
	red.push_back(x[hi]);
	blue.push_back(x[hi]);
	
	if (red.empty() && blue.empty())
		return curr;
		
	int mx_red = 0;
	for (int i = 1; i < red.size(); i++)
		mx_red = max(mx_red, red[i] - red[i - 1]);
	
	int mx_blue = 0;
	for (int i = 1; i < blue.size(); i++)
		mx_blue = max(mx_blue, blue[i] - blue[i - 1]);
	
	ll opt1 = curr;
	if (!red.empty())
		opt1 += curr - mx_red;
	if (!blue.empty())
		opt1 += curr - mx_blue;
	
	ll opt2 = 0;
	if (!red.empty())
		opt2 += curr;
	if (!blue.empty())
		opt2 += curr;
	
	return min(opt1, opt2);
}

ll solve() {
	for (int i = 0; i < N; i++)
		v[clr[i]].push_back(i);
		
	for (auto it : "RGB") 
		if (!v[it].empty())
			dist[it] = x[v[it].back()] - x[v[it][0]];
	
	if (v['G'].empty())
		return dist['R'] + dist['B'];
	
	ll sol = 0;
	for (auto it : "RB") {
		if (!v[it].empty() && v[it][0] < v['G'][0])
			sol += x[v['G'][0]] - x[v[it][0]];
		if (!v[it].empty() && v[it].back() > v['G'].back())
			sol += x[v[it].back()] - x[v['G'].back()];
	}
	
	for (int i = 1; i < v['G'].size(); i++) 
		sol += calc(v['G'][i - 1], v['G'][i]);

	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}