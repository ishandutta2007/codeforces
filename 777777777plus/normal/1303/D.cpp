#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
ll n;
int m,cnt[61];

int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		ll tot=0;
		memset(cnt,0,sizeof(cnt));
		for(int i=1,x,c;i<=m;++i){
			cin>>x;
			tot+=x;
			for(c=0;x;x>>=1,c++);
			cnt[c-1]++;
		}
		if(tot<n){
			cout<<-1<<endl;
			continue;
		}
		ll ans=0;
		for(int i=0;i<60;++i){
			if(n&1ll<<i){
				if(cnt[i])cnt[i]--;
				else{
					for(int j=i+1;j<60;++j)
					if(cnt[j]){
						ans+=j-i;
						cnt[j]--;
						for(int k=i;k<j;++k)cnt[k]++;
						break;
					}
				}
			}
			cnt[i+1]+=cnt[i]/2;
		}
		cout<<ans<<endl;
		
	}
}