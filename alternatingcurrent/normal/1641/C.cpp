#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, nq;
struct change{
	int l, r, x;
	int ind;
	change(){}
	change(int L, int R, int X, int Ind){
		l = L, r = R, x = X, ind = Ind;
	}
};
int ansval[200200];
bool anstp[200200];
vector<change> c;
vector< pair<int, int> > q;
int cnt[800800], mx[800800], cntlaz[800800], mxlaz[800800];
void pushdown(int l, int r, int k){
	int mid = (l + r) >> 1;
	if(cntlaz[k]){
		cntlaz[k + k] = cntlaz[k + k + 1] = 1;
		cnt[k + k] = mid - l + 1;
		cnt[k + k + 1] = r - (mid + 1) + 1;
	}
	mxlaz[k + k] = min(mxlaz[k + k], mxlaz[k]);
	mxlaz[k + k + 1] = min(mxlaz[k + k + 1], mxlaz[k]);
	mx[k + k] = min(mx[k + k], mxlaz[k]);
	mx[k + k + 1] = min(mx[k + k + 1], mxlaz[k]);
}
void update(int tl, int tr, int val, int l, int r, int k){
//	cout << "update " << tl << " " << tr << " " << val << " " << l << " " << r << " " << k << endl;
	if(tl > r || l > tr)
		return ;
	if(tl <= l && r <= tr){
		cntlaz[k] = 1;
		cnt[k] = r - l + 1;
		mxlaz[k] = min(mxlaz[k], val);
		mx[k] = min(mx[k], val);
		return ;
	}
	pushdown(l, r, k);
	int mid = (l + r) >> 1;
	update(tl, tr, val, l, mid, k + k);
	update(tl, tr, val, mid + 1, r, k + k + 1);
	cnt[k] = cnt[k + k] + cnt[k + k + 1];
	mx[k] = max(mx[k + k], mx[k + k + 1]);
}
pair<int, int> query(int tl, int tr, int l, int r, int k){
//	cout << "query " << tl << " " << tr << " " << l << " " << r << " " << k << endl;
	if(tl <= l && r <= tr)
		return make_pair(cnt[k], mx[k]);
	if(tl > r || l > tr)
		return make_pair(0, 0);
	pushdown(l, r, k);
	int mid = (l + r) >> 1;
	pair<int, int> lans = query(tl, tr, l, mid, k + k);
	pair<int, int> rans = query(tl, tr, mid + 1, r, k + k + 1);
	return make_pair(lans.first + rans.first, max(lans.second, rans.second));
}
int getnope(int tl, int tr, int l, int r, int k){
//	cout << "getnope " << tl << " " << tr << " " << l << " " << r << " " << k << endl;
	if(tl > r || l > tr)
		return -1;
	int mid = (l + r) >> 1;
	if(tl <= l && r <= tr){
		if(cnt[k] == (r - l + 1))
			return -1;
		if(l == r)
			return l;
		pushdown(l, r, k);
		if(cnt[k + k] != (mid - l + 1))
			return getnope(tl, tr, l, mid, k + k);
		else
			return getnope(tl, tr, mid + 1, r, k + k + 1);
	}
	pushdown(l, r, k);
	return max(getnope(tl, tr, l, mid, k + k), getnope(tl, tr, mid + 1, r, k + k + 1));
}

int main(){
	memset(mx, 0x3f, sizeof(mx));
	memset(mxlaz, 0x3f, sizeof(mxlaz));
	ios::sync_with_stdio(false);
	cin >> n >> nq;
	rep(i, nq){
		int tp;
		cin >> tp;
		if(tp == 0){
			int l, r, x;
			cin >> l >> r >> x;
			l--, r--;
			c.push_back(change(l, r, x, i));
		} else {
			int pos;
			cin >> pos;
			pos--;
			q.push_back(make_pair(pos, i));
		}
	}
	rep(i, (int)c.size())
		if(c[i].x == 0)
			update(c[i].l, c[i].r, c[i].ind, 0, n - 1, 1);
//	cout << "99" << endl;
	memset(ansval, 0x3f, sizeof(ansval));
	rep(i, (int)c.size())
		if(c[i].x == 1){
			pair<int, int> res = query(c[i].l, c[i].r, 0, n - 1, 1);
//			cout << c[i].l << " to " << c[i].r << ": " << res.first << " " << res.second << endl;
			if(res.first == c[i].r - c[i].l){
				int pos = getnope(c[i].l, c[i].r, 0, n - 1, 1);
				anstp[pos] = 1;
				ansval[pos] = min(ansval[pos], max(max(query(c[i].l, pos - 1, 0, n - 1, 1).second, query(pos + 1, c[i].r, 0, n - 1, 1).second), c[i].ind));
//				cout << pos << ": " << anstp[pos] << " " << ansval[pos] << endl;
			}
		}
//	cout << "109" << endl;
	rep(i, n)
		if(!anstp[i])
			ansval[i] = query(i, i, 0, n - 1, 1).second;
//	cout << "112" << endl;
	rep(i, (int)q.size()){
		if(ansval[q[i].first] < q[i].second)
			cout << (anstp[q[i].first] ? "YES" : "NO") << endl;
		else
			cout << "N/A" << endl;
	}
	return 0;
}