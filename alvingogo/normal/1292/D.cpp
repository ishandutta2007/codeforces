#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> pr;
	vector<int> vis(5001);
	vector<int> pp(5001);
	for(int i=2;i<5000;i++){
		if(!vis[i]){
			pp[i]=pr.size();
			pr.push_back(i);
			for(int j=i;j<=5000;j+=i){
				vis[j]=i;
			}
		}
	}
	int p=pr.size();
	vector<vector<int> > fra(5001,vector<int>(p));
	for(int i=2;i<=5000;i++){
		fra[i]=fra[i-1];
		int q=i;
		while(q>1){
			fra[i][pp[vis[q]]]++;
			q/=vis[q];
		}
	}
	vector<int> cnt(5001);
	vector<int> ab(5001,1);
	long long sum=0;
	for(int i=0;i<n;i++){
		cin >> v[i];
		if(v[i]==0){
			v[i]=1;
		}
		cnt[v[i]]++;
	}
	for(int i=1;i<=5000;i++){
		for(auto h:fra[i]){
			sum+=1ll*cnt[i]*h;
		}
	}
	for(int i=p-1;i>=0;i--){
		vector<pair<int,int> > r;
		long long ss=0;
		for(int j=1;j<=5000;j++){
			if(!ab[j]){
				continue;
			}
			if(fra[j][i]==0){
				continue;
			}
			r.push_back({fra[j][i],cnt[j]});
			ss+=cnt[j];
		}
		if(ss<=n/2){
			for(int j=1;j<=5000;j++){
				if(fra[j][i]!=0){
					ab[j]=0;
				}
			}
			continue;
		}
		for(int j=1;j<=5000;j++){
			if(fra[j][i]==0){
				ab[j]=0;
			}
		}
		sort(r.begin(),r.end(),greater<pair<int,int> >());
		int nw;
		while(ss>n/2){
			nw=r.back().fs;
			while(r.size() && r.back().fs==nw){
				ss-=r.back().sc;
				r.pop_back();
			}
		}
		for(int j=1;j<=5000;j++){
			if(ab[j]){
				sum-=1ll*min(nw,fra[j][i])*cnt[j];
				if(fra[j][i]!=nw){
					ab[j]=0;
				}
				sum+=1ll*max(0,nw-fra[j][i])*cnt[j];
			}
			else{
				sum+=1ll*cnt[j]*nw;
			}
		}
	}
	cout << sum << "\n";
    return 0;
}