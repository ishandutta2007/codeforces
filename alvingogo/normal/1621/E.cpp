#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
#define int long long
using namespace std;

struct no{
	vector<int> v;
	int sum,k,ba,id;
	void init(int nn){
		v.resize(nn);
		sum=ba=0;
		k=nn;
	}
};
bool cmpx(no a,no b){
	double j=a.sum/(a.k*1.0);
	double k=b.sum/(b.k*1.0);
	return j>k;
}
bool cmpid(no a,no b){
	return a.id<b.id;
}
signed main(){
	AquA;
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<int> tr(n);
		for(int i=0;i<n;i++){
			cin >> tr[i];
		}
		sort(tr.begin(),tr.end(),greater<int>());
		vector<no> vs(m);
		for(int i=0;i<m;i++){
			int k;
			cin >> k;
			vs[i].init(k);
			for(int j=0;j<k;j++){
				cin >> vs[i].v[j];
				vs[i].sum+=vs[i].v[j];
			}
			vs[i].id=i;
		}
		sort(vs.begin(),vs.end(),cmpx);
		bool flag=0;
		for(int i=0;i<m;i++){
			if(vs[i].sum>tr[i]*vs[i].k){
				flag=1;
				break;
			}
		}
		if(!flag){
			vector<int> able(m);
			for(int i=0;i<m-1;i++){
				if(vs[i].sum<=tr[i+1]*vs[i].k){
					able[i]=1;
				}
			}
			int z=tr[0];
			for(int i=0;i<m;i++){
				vs[i].ba=z;
				if(!able[i] && i<m-1){
					z=tr[i+1];
				}
			}
			sort(vs.begin(),vs.end(),cmpid);
			for(int i=0;i<m;i++){
				for(auto e:vs[i].v){
					if((vs[i].sum-e)<=vs[i].ba*(vs[i].k-1)){
						cout << 1;
					}
					else{
						cout << 0;
					}
				}
			}
			cout << "\n";
		}
		else{
			vector<int> able(m);
			vector<int> ll;
			int uu=-1;
			for(int i=1;i<m;i++){
				if(vs[i].sum>tr[i-1]*vs[i].k){
					ll.push_back(i);
				}
			}
			for(int i=0;i<m;i++){
				if(vs[i].sum>tr[i]*vs[i].k){
					uu=i;
					break;
				}
			}
			//cout << uu << "\n";
			if(ll.size()==0){
				for(int i=m-1;i>=0;i--){
					if(vs[i].sum>tr[i]*vs[i].k){
						for(int p=uu;p>=0;p--){
							vs[p].ba=tr[i];
						}
						break;
					}
				}
			}
			else if(ll.size()==1 && uu==ll[0]){
				for(int i=m-1;i>=0;i--){
					if(vs[i].sum>tr[i]*vs[i].k){
						vs[uu].ba=tr[i];
						break;
					}
				}
			}
			sort(vs.begin(),vs.end(),cmpid);
			for(int i=0;i<m;i++){
				for(auto e:vs[i].v){
					if((vs[i].sum-e)<=vs[i].ba*(vs[i].k-1)){
						cout << 1;
					}
					else{
						cout << 0;
					}
				}
			}
			cout << "\n";
		}
	}
	return 0;
}