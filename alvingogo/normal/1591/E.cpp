#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

struct no{
	vector<int> ch;
	int dfn;
	int p;
};

struct qu{
	int vt,l,k;
	int id;
};
vector<no> v;
vector<int> ans;

bool cmp(qu a,qu b){
	return v[a.vt].dfn<v[b.vt].dfn;
}
int cnt=0;
vector<qu> vq;
int vqx=0;
vector<int> cv,dcv,ct,lb;
void dfs(int r){
	v[r].dfn=cnt;
	cnt++;
	for(auto j:v[r].ch){
		dfs(j);
	}
}
void dfs2(int r){
	int x=v[r].p;
	ct[x]++;
	swap(cv[dcv[x]],cv[lb[ct[x]]-1]);
	swap(dcv[x],dcv[cv[dcv[x]]]);
	lb[ct[x]]--;
	while(vqx<vq.size() && vq[vqx].vt==r){
		if(lb[vq[vqx].l]+vq[vqx].k-1>=cv.size()){
			ans[vq[vqx].id]=-1;
		}
		else{
			ans[vq[vqx].id]=cv[lb[vq[vqx].l]+vq[vqx].k-1]+1;
		}
		vqx++;
	}
	for(auto j:v[r].ch){
		dfs2(j);
	}
	//cout << r << endl;
	swap(cv[dcv[x]],cv[lb[ct[x]]]);
	swap(dcv[x],dcv[cv[dcv[x]]]);
	lb[ct[x]]++;
	ct[x]--;
}
int main(){
	AquA;
	int t;
	cin >> t;
	while(t--){
		int n,q;
		cin >> n >> q;
		vq.clear();
		vq.resize(q);
		v.clear();
		v.resize(n);
		//ans.clear();
		ans.resize(q);
		cv.resize(n);
		dcv.resize(n);
		ct.clear();
		ct.resize(n,0);
		lb.resize(n+1);
		cnt=0;
		vqx=0;
		for(int i=0;i<n;i++){
			cv[i]=i;
			dcv[i]=i;
			lb[i+1]=n;
		}
		for(int i=0;i<n;i++){
			cin >> v[i].p;
			v[i].p--;
		}
		for(int i=1;i<n;i++){
			int a;
			cin >> a;
			a--;
			v[a].ch.push_back(i);
		}
		dfs(0);
		for(int i=0;i<q;i++){
			cin >> vq[i].vt >> vq[i].l >> vq[i].k;
			vq[i].id=i;
			vq[i].vt--;
		}
		sort(vq.begin(),vq.end(),cmp);
		//cout << "oejfjew" << endl;
		dfs2(0);
		for(int i=0;i<q;i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
		
	return 0;
}