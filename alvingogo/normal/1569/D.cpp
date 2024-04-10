#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n,m,k;
		cin >> n >> m >> k;
		vector<map<int,int> > vmx(n+1),vmy(m+1);
		vector<int> sx(m),sy(n);
		vector<int> vx,vy;
		int x,y;
		for(int i=0;i<n;i++){
			cin >> x;
			vx.push_back(x);
		}
		for(int i=0;i<m;i++){
			cin >> y;
			vy.push_back(y);
		}
		long long ans=0;
		int a=0,b=0;
		for(int i=0;i<k;i++){
			cin >> x >> y;
			a=lower_bound(vx.begin(),vx.end(),x)-vx.begin();
			b=lower_bound(vy.begin(),vy.end(),y)-vy.begin();
			if(vx[a]==x && vy[b]==y){
				continue;
			}
			if(vx[a]==x){
				if(vmx[a].find(b)!=vmx[a].end()){
					ans+=sx[b]-vmx[a][b];
					vmx[a][b]++;
				}
				else{
					ans+=sx[b];
					vmx[a][b]=1;
				}
				sx[b]++;
			}
			else{
				if(vmy[b].find(a)!=vmy[b].end()){
					ans+=sy[a]-vmy[b][a];
					vmy[b][a]++;
				}
				else{
					ans+=sy[a];
					vmy[b][a]=1;
				}
				sy[a]++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}