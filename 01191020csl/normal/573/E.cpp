#include<bits/stdc++.h>
#define inf 9223372036854775807
using namespace std;
int read() {
	char c=getchar();while(c!='-'&&!isdigit(c)) c=getchar();
	int neg=0;if(c=='-') neg=1,c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return neg?-num:num;
}
struct node {
	long long k, b0;
	int p;
	struct Info {
		long long a, b;
		int id, vis;
	};
	vector<Info> info, hull;
}nd[501];
bool cmp(node::Info &i, node::Info &j, node::Info &k) {
	return (i.b-j.b)*(k.a-j.a)<(j.b-k.b)*(j.a-i.a);
}
bool operator<(const node::Info &a, const node::Info &b) {
	return a.a < b.a;
}
int S, a[100001], id[100001];
void build(node &n) {
	n.hull.clear();
	for (int i = 0; i < n.info.size(); i++)
		if (!n.info[i].vis) {
			
			while ((n.hull.size()>=1&&(n.hull.end()-1)->a==n.info[i].a&&(n.hull.end()-1)->b<=n.info[i].b)||(n.hull.size()>=2&&!cmp(*(n.hull.end()-2),*(n.hull.end()-1),n.info[i]))) n.hull.pop_back();
			n.hull.push_back(n.info[i]);
		}
	n.p = 0;
}
pair<long long, int> query(node &n) {
	if (n.hull.empty()) return make_pair(-inf, 0);
	while (n.p<n.hull.size()-1 && n.hull[n.p+1].a*n.k+n.hull[n.p+1].b>n.hull[n.p].a*n.k+n.hull[n.p].b) ++n.p; 
	return make_pair(n.hull[n.p].a*n.k+n.hull[n.p].b+n.b0, n.hull[n.p].id);
}
int main() {
	int n = read(), t = 1;
	S = sqrt(n);
	for (int i = 1; i <= n; i += S, t++) {
		nd[t].k = 1;
		for (int j = i; j < i + S && j <= n; j++)
			id[j] = t, nd[t].info.push_back(node::Info{a[j]=read(),0,j,0});
		sort(nd[t].info.begin(), nd[t].info.end());
		build(nd[t]);
	}
	--t;
	long long ans = 0, now = 0;
	for (int i = 1; i <= n; i++) {
		pair<long long, int> res = make_pair(-inf, 0);
		for (int j = 1; j <= t; j++) res = max(res, query(nd[j]));
		now += res.first, ans = max(ans, now);
		int i0 = id[res.second];
		for (int j = 1; j < i0; j++) nd[j].b0 += a[res.second];
		for (int j = i0 + 1; j <= t; j++) nd[j].k += 1;
		for (int j = 0; j < nd[i0].info.size(); j++) {
			int d = nd[i0].info[j].id;
			if (d < res.second) nd[i0].info[j].b += a[res.second];
			else nd[i0].info[j].b += a[d];
			if (d == res.second) nd[i0].info[j].vis = 1;
		}
		build(nd[i0]);
	}
	cout << ans << endl;
}