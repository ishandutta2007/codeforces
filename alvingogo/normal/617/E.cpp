#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

struct qu{
	int l,r,id;
};
const int sqt=317;
bool cmp(qu a,qu b){
	int al=a.l/sqt,bl=b.l/sqt;
	if(al==bl){
		if(al%2){
			return a.r>b.r;
		}
		else{
			return a.r<b.r;
		}
	}
	return al<bl;
}
int main(){
	AquA;
	int n,q,k;
	cin >> n >> q >> k;
	vector<int> xo(n+1);
	for(int i=1;i<=n;i++){
		cin >> xo[i];
		xo[i]^=xo[i-1];
	}
	vector<qu> vq(q);
	for(int i=0;i<q;i++){
		cin >> vq[i].l >> vq[i].r;
		vq[i].id=i;
	}
	sort(vq.begin(),vq.end(),cmp);
	vector<int> ct(1<<20,0);
	vector<long long> ans(q);
	ct[0]++;
	int l=1,r=0;
	long long ax=0;
	for(int i=0;i<q;i++){
		while(l>vq[i].l){
			--l;
			ax+=ct[xo[l-1]^k];
			ct[xo[l-1]]++;
		}
		while(r<vq[i].r){
			++r;
			ax+=ct[xo[r]^k];
			ct[xo[r]]++;
		}
		while(l<vq[i].l){
			ct[xo[l-1]]--;
			ax-=ct[xo[l-1]^k];
			l++;
		}
		while(r>vq[i].r){
			ct[xo[r]]--;
			ax-=ct[xo[r]^k];
			r--;
		}
		ans[vq[i].id]=ax;
	}
	for(int i=0;i<q;i++){
		cout << ans[i] << "\n";
	}
	return 0;
}