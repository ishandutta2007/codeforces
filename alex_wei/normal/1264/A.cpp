#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,p[400005],cnt,a[400005],sum[400005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		int l=0;
		cnt=0;
		for(int i=1;i<=n;i++){
			cin>>p[i];
			if(i>1&&p[i]!=p[i-1])a[++cnt]=l,l=1;
			else l++;
		}
		a[++cnt]=l;
		for(int i=1;i<=cnt;i++)
			sum[i]=sum[i-1]+a[i];
		if(cnt<=3||sum[3]>n/2){
			cout<<"0 0 0\n";
			continue;
		}
		int pos=0;
		for(int i=1;i<=n;i++){
			if(sum[i]>n/2){
				pos=i-1;
				break;
			}
		}
		int tmp=pos;
		while(tmp>=3&&sum[pos]-sum[tmp-1]<=a[1])tmp--;
		int b=sum[pos]-sum[tmp-1],s=sum[tmp-1]-sum[1],g=sum[1];
		if(g>=s||g>=b)cout<<"0 0 0\n";
		else cout<<g<<" "<<s<<" "<<b<<endl;
	}
    return 0;
}