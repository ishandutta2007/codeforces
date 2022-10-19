#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
int qmax(int a, int b){
	return (a > b) ? a : b;
}

int n, m;
vector<int> val[12];
int suf[12];
struct node{
	map<int, node*> nxt;
	vector<int> nowdat;
	int dept;
	int ans;
};
node *rt;
int res = -1;
vector<int> ans;
void build(vector<int> ban, node *now){
	if(now->dept >= n)
		return ;
	if(!now->nxt.count(ban[now->dept])){
		now->nxt[ban[now->dept]] = new node;
		now->nxt[ban[now->dept]]->dept = now->dept + 1;
	}
	build(ban, now->nxt[ban[now->dept]]);
}
void dfs(node *now, vector<int> nowv){
//	rep(i, (int)nowv.size())
//		cout << nowv[i] << " ";
//	cout << ": " << now->ans << endl;
	if(now->dept >= n)
		return ;
	now->nxt[(int)val[now->dept].size()] = rt;
	map<int, node*>::iterator pre = now->nxt.begin();
	int mxpos = -1;
	for(map<int, node*>::iterator it = now->nxt.begin(); it != now->nxt.end(); it++){
		if((it == now->nxt.begin() && it->first != 0) || (it->first != pre->first + 1))
			mxpos = it->first - 1;
		if(it->first >= (int)val[now->dept].size())
			continue;
		it->second->ans = now->ans + val[now->dept][it->first];
		vector<int> nxtv = nowv;
		nxtv.push_back(it->first);
		dfs(it->second, nxtv);
		pre = it;
	}
	if(mxpos >= 0){
		if(now->ans + val[now->dept][mxpos] + suf[now->dept + 1] > res){
			res = now->ans + val[now->dept][mxpos] + suf[now->dept + 1];
			ans = nowv;
			ans.push_back(mxpos);
			for(int i = now->dept + 1; i < n; i++)
				ans.push_back(val[i].size() - 1);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	rt = new node;
	rt->dept = 0;
	rt->ans = 0;
	rt->nxt.clear();
	cin >> n;
	rep(i, n){
		int sz;
		cin >> sz;
		rep(j, sz){
			int nxt;
			cin >> nxt;
			val[i].push_back(nxt);
		}
	}
	for(int i = n - 1; i >= 0; i--)
		suf[i] = suf[i + 1] + val[i][(int)val[i].size() - 1];
	cin >> m;
	rep(i, m){
		vector<int> ban;
		rep(j, n){
			int pos;
			cin >> pos;
			pos--;
			ban.push_back(pos);
		}
		build(ban, rt);
	}
	vector<int> st;
	dfs(rt, st);
//	cout << res << endl;
	rep(i, n)
		cout << ans[i] + 1 <<" ";
	cout << endl; 
	return 0;
}