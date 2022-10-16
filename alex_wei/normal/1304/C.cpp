#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>

int q,n,m,t[150],l[150],r[150];
int main(){
	cin>>q;
	while(q--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>t[i]>>l[i]>>r[i];
		int lo=m,hi=m,pd=1;
		for(int i=1;i<=n;i++){
			int k=t[i]-t[i-1];
			if(hi+k<l[i]||lo-k>r[i]){
				pd=0;
				break;
			}
			lo=max(l[i],lo-k),hi=min(r[i],hi+k);
		}
		if(pd)puts("YES");
		else puts("NO");
	}
    return 0;
}