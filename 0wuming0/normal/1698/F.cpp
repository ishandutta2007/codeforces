#include<bits/stdc++.h>
using namespace std;
 
const int N=510;
typedef pair<int,int> PII;
 
int a[N], b[N];
vector<PII> ansa, ansb, pa, pb;
int n;
 
void solve(int i){
	if(a[i]!=b[i]){
		for(int j=i; j<n; ++j){//b j+1, j == a i-1,i
			if(b[j]==a[i] && b[j+1]==a[i-1]){
				ansb.push_back(PII(i-1,j+1));
				for(int l=i, r=j; l<r; l++, r--){
					swap(b[l],b[r]);
				}
				return;
			}
		}
		for(int j=i; j<n; ++j){//b j+1, j == a i-1,i
			if(a[j]==b[i] && a[j+1]==b[i-1]){
				ansa.push_back(PII(i-1,j+1));
				for(int l=i, r=j; l<r; l++, r--){
					swap(a[l],a[r]);
				}
				return;
			}
		}
		
		bool have=false;
		{
			int sl[N]={0}, sr[N]={0};
			for(int j=i; j<=n; ++j){
				if(sl[a[j]]==0){
					sl[a[j]]=j;
				}else{
					sr[a[j]]=j;
				}
			}
			for(int j=i; j<n; ++j){
				if(a[j]==b[i-1] && a[j+1]==b[i]){
					for(int k=1; k<=n; ++k) if(sr[k]){
						if(sl[k]<=j && sr[k]>=j+1){
							ansa.push_back(PII(sl[k],sr[k]));
							for(int l=sl[k], r=sr[k]; l<r; l++, r--){
								swap(a[l],a[r]);
							}
							solve(i);
							return;
						}
					}
				}
			}
		}
		{
			int sl[N]={0}, sr[N]={0};
			for(int j=i; j<=n; ++j){
				if(sl[b[j]]==0){
					sl[b[j]]=j;
				}else{
					sr[b[j]]=j;
				}
			}
			for(int j=i; j<n; ++j){
				if(b[j]==a[i-1] && b[j+1]==a[i]){
					for(int k=1; k<=n; ++k) if(sr[k]){
						if(sl[k]<=j && sr[k]>=j+1){
							ansb.push_back(PII(sl[k],sr[k]));
							for(int l=sl[k], r=sr[k]; l<r; l++, r--){
								swap(b[l],b[r]);
							}
							solve(i);
							return;
						}
					}
				}
			}
		}
	}
}
 
int main(){
	int t; cin>>t;
	while(t--){
		pa.clear();
		pb.clear();
		ansa.clear();
		ansb.clear();
		
		scanf("%d", &n);
		for(int i=1; i<=n; ++i){
			scanf("%d", a+i);
		}
		for(int i=1; i<=n; ++i){
			scanf("%d", b+i);
		}
		
		//check
		for(int i=1; i<n; ++i){
			int a1=a[i], a2=a[i+1];
			if(a1>a2) swap(a1,a2);
			pa.push_back(PII(a1,a2));
			
			a1=b[i], a2=b[i+1];
			if(a1>a2) swap(a1,a2);
			pb.push_back(PII(a1,a2));
		}
		sort(pa.begin(),pa.end());
		sort(pb.begin(),pb.end());
		if(pa!=pb || a[1]!=b[1] || a[n]!=b[n]){
			puts("NO");
			continue;
		}
		if(n<=2){
			printf("YES\n0\n");
			continue;
		}
		
		//cal
		for(int i=2; i<n; ++i){
			solve(i);
		}
		printf("YES\n%d\n", (int)ansa.size()+(int)ansb.size());
		for(int i=0; i<ansa.size(); ++i){
			printf("%d %d\n", ansa[i].first, ansa[i].second);
		}
		for(int i=(int)ansb.size()-1; i>=0; --i){
			printf("%d %d\n", ansb[i].first, ansb[i].second);
		}
	}
}