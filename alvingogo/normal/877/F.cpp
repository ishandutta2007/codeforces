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
const int sqt=323;
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
	int n;
	long long k;
	cin >> n >> k;
	vector<int> aa(n),bb(n);
	vector<long long> v(n),sum(n),suma(n),sumb(n);
	for(int i=0;i<n;i++){
		cin >> aa[i];
	}
	bool f=(k==0);
	vector<long long> pp;
	for(int i=0;i<n;i++){
		cin >> bb[i];
		v[i]=(aa[i]==1)?bb[i]:-bb[i];
		sum[i]=sum[(i-1)*(i>0)]+v[i];
		suma[i]=sum[i]-k;
		sumb[i]=sum[i]+k;
		pp.push_back(sum[i]);
		pp.push_back(suma[i]);
		pp.push_back(sumb[i]);
	}
	pp.push_back(0);
	pp.push_back(k);
	sort(pp.begin(),pp.end());
	pp.erase(unique(pp.begin(),pp.end()),pp.end());
	k=lower_bound(pp.begin(),pp.end(),k)-pp.begin();
	for(int i=0;i<n;i++){
		suma[i]=lower_bound(pp.begin(),pp.end(),suma[i])-pp.begin();
		sum[i]=lower_bound(pp.begin(),pp.end(),sum[i])-pp.begin();
		sumb[i]=lower_bound(pp.begin(),pp.end(),sumb[i])-pp.begin();
	}
	int q;
	cin >> q;
	vector<qu> vq(q);
	vector<long long> ans(q);
	long long ax=0;
	for(int i=0;i<q;i++){
		cin >> vq[i].l >> vq[i].r;
		vq[i].l--;
		vq[i].r--;
		vq[i].id=i;
	}
	vector<int> ct(pp.size(),0);
	int hz=lower_bound(pp.begin(),pp.end(),0)-pp.begin();
	ct[hz]++;
	sort(vq.begin(),vq.end(),cmp);
	int l=0,r=-1;
	for(int i=0;i<q;i++){
		while(l>vq[i].l){
			--l;
			if(l>0){
				ax+=ct[sumb[l-1]];
				ct[sum[l-1]]++;
			}
			else{
				ax+=ct[k];
				ct[hz]++;
			}
		}
		while(r<vq[i].r){
			++r;
			ax+=ct[suma[r]];
			ct[sum[r]]++;
		}
		while(l<vq[i].l){
			if(l>0){
				ax-=ct[sumb[l-1]];
				if(f){
					ax++;
				}
				ct[sum[l-1]]--;
			}
			else{
				if(f){
					ax++;
				}
				ax-=ct[k];
				ct[hz]--;
			}
			l++;
		}
		while(r>vq[i].r){
			if(f){
				ax++;
			}
			ax-=ct[suma[r]];
			ct[sum[r]]--;
			r--;
		}
		//cout << l << " " << r << "\n";
		ans[vq[i].id]=ax;
	}
	for(int i=0;i<q;i++){
		cout << ans[i] << "\n";
	}
	return 0;
}