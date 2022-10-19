#include<bits/stdc++.h>
using namespace std;
int n,p;
long long tot,a[100001],mn=0x3f3f3f3f;
vector<int>v;
int main(){
	scanf("%d%d",&n,&p),p--;
	for(int i=0;i<n;i++)scanf("%lld",&a[i]),mn=min(mn,a[i]);
	for(int i=0;i<n;i++)if(a[i]==mn)v.push_back(i);
	for(int i=0;i<v.size();i++){
		if(i+1!=v.size()){
			if(v[i]<=p&&p<v[i+1]){
				for(int j=(v[i]+1)%n;j!=(p+1)%n;j++,j%=n)a[j]--,tot++;
		//		for(int j=0;j<n;j++)printf("%lld ",a[j]);puts("");
				long long t=a[v[i]];
				for(int j=0;j<n;j++)a[j]-=t,tot+=t;
				a[v[i]]=tot;
				for(int j=0;j<n;j++)printf("%lld ",a[j]);puts("");
				return 0;
			}
		}else{
			if(v[i]<=p||p<v[0]){
				for(int j=(v[i]+1)%n;j!=(p+1)%n;j++,j%=n)a[j]--,tot++;
		//		for(int j=0;j<n;j++)printf("%lld ",a[j]);puts("");
				long long t=a[v[i]];
				for(int j=0;j<n;j++)a[j]-=t,tot+=t;
				a[v[i]]=tot;
				for(int j=0;j<n;j++)printf("%lld ",a[j]);puts("");
				return 0;
			}
		}
	}
	return 0;
}