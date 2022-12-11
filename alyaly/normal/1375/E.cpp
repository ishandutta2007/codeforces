#include<bits/stdc++.h>
using namespace std;
int n,a[2001],pans,fl[2001];
pair<int,int> pa[1000001],b[2001];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=make_pair(a[i],i);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		for(int j=n;j>=b[i].second+1;j--){
			if(fl[j]&&a[j]!=a[b[i].second]){
				pa[++pans]=make_pair(b[i].second,j);
			}
		}
		fl[b[i].second]=1;
	}
	printf("%d\n",pans);
	for(int i=1;i<=pans;i++) printf("%d %d\n",pa[i].first,pa[i].second);
	return 0;
}
/*

*/