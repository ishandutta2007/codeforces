#include <bits/stdc++.h>
using namespace std;
int res[5005],a[5005],n;
bool freq[200000005];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n&&cin>>a[i];++i)
		for(int f=2,x=a[i];f*f<=abs(x);++f)
			while(a[i]%(f*f)==0)
				a[i]/=f*f;
	for(int i=0;i<n;++i) a[i]+=100000003;
	for(int i=0,idx,j;i<n;++i){
		for(idx=0,j=i;j<n;++j){
			if(a[j]==100000003) ++res[max(idx,1)];
			else{
				if(!freq[a[j]]) freq[a[j]]=1,++idx;
				++res[idx];
			}
		}
		for(int j=i;j<n;++j) freq[a[j]] = 0;
	}
	for(int i=1;i<=n;cout<<res[i++]<<' ');
}