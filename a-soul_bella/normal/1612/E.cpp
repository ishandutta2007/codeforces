#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

const int maxn=2e5; 
int n;
double f[maxn+5][21];  
int trans[maxn+5][21]; 
vector<int> P[maxn+5]; 
vector <int> num; 
int id[maxn+5]; 
double sum[maxn+5],s[maxn+5];
int maxk;
int m[maxn+5],k[maxn+5]; 
int main() {
	scanf("%d",&n); 
	for (int i=1;i<=maxn;i++) id[i]=i; 
	for (int i=1;i<=n;i++) {
		scanf("%d %d",&m[i],&k[i]); 
		maxk=max(maxk,k[i]); 
		P[m[i]].push_back(k[i]); 
	}
	double ans=0; 
	for (int t=1;t<=maxk;t++) {
		for (int i=1;i<=maxn;i++) id[i]=i,s[i]=0;  
		for (int i=1;i<=maxn;i++) {
			double num=0; 
			for (auto x:P[i]) {
				if (t<=x) num+=1.0; else num+=1.0*x/t;  
			}
			s[i]=num; 
		}
		sort(id+1,id+maxn+1,[&](int x,int y){
			return s[x]>s[y]; 
		}); 
		for (int i=1;i<=t;i++) sum[i]=sum[i-1]+s[id[i]];  
	//	for (int t=maxk+1;t<=maxn;t++) {
			if (1.0*sum[t]>ans) {
				ans=1.0*sum[t]; 
				num.clear();
				for (int j=1;j<=t;j++) num.push_back(id[j]); 
			}
	//	}
	} 
	for (int i=1;i<=maxn;i++) id[i]=i,s[i]=0;  
	for (int i=1;i<=n;i++) s[m[i]]+=k[i]; 
	sort(id+1,id+maxn+1,[&](int x,int y){
		return s[x]>s[y]; 
	});
	for (int i=1;i<=maxn;i++) sum[i]=sum[i-1]+s[id[i]]; 
	
	for (int t=maxk+1;t<=maxn;t++) {
		if (1.0*sum[t]/t>ans) {
			ans=1.0*sum[t]/t; 
			num.clear();
			for (int j=1;j<=t;j++) num.push_back(id[j]); 
		}
	}
	printf("%d\n",num.size());
	sort(num.begin(),num.end()); 
	for (auto x:num) printf("%d ",x); 
	return 0;
}