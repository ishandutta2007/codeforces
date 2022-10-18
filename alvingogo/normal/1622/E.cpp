#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int main(){
	AquA;
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<int> v(n);
		vector<string> t(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
		}
		for(int i=0;i<n;i++){
			cin >> t[i];
		}
		long long ans=-9e18;
		vector<pair<int,int> > h;
		for(int i=0;i<(1<<n);i++){
			long long xx=0;
			for(int j=0;j<n;j++){
				if((i>>j)&1){
					xx-=v[j];
				}
				else{
					xx+=v[j];
				}
			}
			vector<pair<int,int> > f(m,{0,0});
			for(int j=0;j<m;j++){
				for(int k=0;k<n;k++){
					if(t[k][j]=='1'){
						if((i>>k)&1){
							f[j].fs++;
						}
						else{
							f[j].fs--;
						}
					}
				}
				f[j].sc=j;
			}
			sort(f.begin(),f.end());
			for(int i=0;i<m;i++){
				xx+=1ll*f[i].fs*(i+1);
				f[i].fs=i+1;
				swap(f[i].fs,f[i].sc);
			}
			if(xx>ans){
				ans=xx;
				h=f;
			}
		}
		sort(h.begin(),h.end());
		for(int i=0;i<m;i++){
			cout << h[i].sc << " ";
		}
		cout << "\n";
	}
	return 0;
}