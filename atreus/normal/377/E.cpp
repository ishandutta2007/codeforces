#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;

struct Line{
	ll a;
	ll b;
	Line(ll a_ = 0, ll b_ = 0){
		a = a_, b = b_;
	}
	ll gety(ll x){
		return a * x + b;
	}
	ll getx(ll x){
		return (x - b + a - 1) / a;
	}
};


long double intersect(Line l, Line d){
	return (d.b - l.b) / (l.a - d.a);
}

int tail = 0, head = 0;
Line deq[maxn];

pair<ll,ll> get(ll y){
	while (head - tail > 1){
		ll x1 = deq[tail].getx(y), x2 = deq[tail+1].getx(y);
		if (x2 < x1 or (x1 == x2 and deq[tail].gety(x1) <= deq[tail+1].gety(x2)))
			tail ++;
		else
			break;
	}
	ll x = deq[tail].getx(y);
	return {x, deq[tail].gety(x) - y};
}

void add(Line l){
	if (tail < head and deq[head-1].a == l.a)
		return;
	while (head - tail > 1 and intersect(deq[head - 1], l) <= intersect(deq[head - 2], deq[head - 1]))
		head --;
	deq[head ++] = l;
}

ll dp[maxn], pd[maxn];
int csuf[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	ll s;
	cin >> n >> s;
	vector<pair<int,int> > a(n);
	for (int i = 0; i < n; i++){
		int v, c;
		cin >> v >> c;
		a[i] = {v, c};
	}
	sort(a.begin(), a.end(), [](pair<int,int> fi, pair<int,int> se){
		if (fi.first != se.first)
			return fi.first < se.first;
		return fi.second > se.second;
	});
	a.resize(unique(a.begin(), a.end()) - a.begin());
	
	vector<pair<int,int> > tmp;
	int mincost = 1000*1000*1000 + 1;
	for (int i = n - 1; i >= 0;i--){
		if (a[i].second < mincost){
			mincost = a[i].second;
			tmp.push_back(a[i]);
		}
	}
	a = tmp;
	sort(a.begin(), a.end());
	n = a.size();
	for (int i = 0; i < n; i++){
		int v = a[i].first, c = a[i].second;
		if (c == 0){
			dp[i] = 0;
			add(Line(v, 0));
			continue;
		}
		auto t = get(c);
		dp[i] = t.first;
		ll extra = t.second;
		add(Line(v, -1ll * dp[i] * v + extra));
		pd[i] = extra;
	}
	ll answer = s;
	for (int i = 0; i < n; i++){
		int v = a[i].first, c = a[i].second;
		Line now = Line(v, -1ll * dp[i] * v + pd[i]);
		answer = min(answer, now.getx(s));
	}
	cout << answer << '\n';
}