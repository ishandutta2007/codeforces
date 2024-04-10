#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<pair<vector<int>,int> > v(n);
		for(int i=0;i<n;i++){
			v[i].fs.resize(m);
		}
		vector<vector<int> > lu(n,vector<int>(m)),ru=lu,ld=lu,rd=lu;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> v[i].fs[j];
			}
			v[i].sc=i;
		}
		sort(v.begin(),v.end());
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				lu[i][j]=v[i].fs[j];
				if(i){
					lu[i][j]=max(lu[i][j],lu[i-1][j]);
				}
				if(j){
					lu[i][j]=max(lu[i][j],lu[i][j-1]);
				}
			}
			for(int j=m-1;j>=0;j--){
				ru[i][j]=v[i].fs[j];
				if(i){
					ru[i][j]=min(ru[i][j],ru[i-1][j]);
				}
				if(j<m-1){
					ru[i][j]=min(ru[i][j],ru[i][j+1]);
				}
			}
		}
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<m;j++){
				ld[i][j]=v[i].fs[j];
				if(i<n-1){
					ld[i][j]=min(ld[i][j],ld[i+1][j]);
				}
				if(j){
					ld[i][j]=min(ld[i][j],ld[i][j-1]);
				}
			}
			for(int j=m-1;j>=0;j--){
				rd[i][j]=v[i].fs[j];
				if(i<n-1){
					rd[i][j]=max(rd[i][j],rd[i+1][j]);
				}
				if(j<m-1){
					rd[i][j]=max(rd[i][j],rd[i][j+1]);
				}
			}
		}
		
		int flag=0;
		for(int i=0;i<n-1;i++){
			for(int j=0;j<m-1;j++){
				if(lu[i][j]<ld[i+1][j] && ru[i][j+1]>rd[i+1][j+1]){
					cout << "YES\n";
					string ans(n,'R');
					for(int p=0;p<=i;p++){
						ans[v[p].sc]='B';
					}
					cout << ans << " " << j+1 << "\n";
					flag=1;
					break;
				}
			}
			if(flag){
				break;
			}
		}
		if(!flag){
			cout << "NO\n";
		}
	}
    return 0;
}