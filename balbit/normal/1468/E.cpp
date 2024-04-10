//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[10];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		for(llo i=0;i<4;i++){
			cin>>it[i];
		}
		llo ans=0;
		for(llo i=0;i<4;i++){
			for(llo j=i+1;j<4;j++){
				vector<llo> ss;
				for(llo k=0;k<4;k++){
					if(k!=i and k!=j){
						ss.pb(k);
					}
				}
				ans=max(ans,min(it[i],it[j])*min(it[ss[0]],it[ss[1]]));
			}
		}
		cout<<ans<<endl;
	}




 
	return 0;
}