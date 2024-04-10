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
		int n;
		cin >> n;
		int minx=2e9,maxx=0,lx=2e9+7,rx=2e9+7;
		int flag=2e9+7;
		for(int i=0;i<n;i++){
			int l,r,c;
			cin >> l >> r >> c;
			int ans=2e9+7;
			if(l<minx){
				lx=c;
			}
			else if(l==minx){
				lx=min(lx,c);
			}
			if(r>maxx){
				rx=c;
			}
			else if(r==maxx){
				rx=min(rx,c);
			}
			if((l>minx && r>maxx) || (l<minx && r<maxx)){
				flag=-1;
			}
			if(l<=minx && r>=maxx){
				if(flag<0){
					flag=c;
				}
				else{
					if(l!=minx || r!=maxx){
						flag=c;
					}
					else{
						flag=min(flag,c);
					}
				}
			}
			if(flag<0){
				ans=lx+rx;
			}
			else{
				ans=min(flag,lx+rx);
			}
			//cout << flag << " " << ans << "\n";
			
			minx=min(minx,l);
			maxx=max(maxx,r);
			cout << ans << "\n";
		}
	}
	return 0;
}