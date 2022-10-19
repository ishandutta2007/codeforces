#include <bits/stdc++.h>
using namespace std;

#define maxn 300300
#define pb push_back
#define pii pair<int,int>
#define pip pair<int,pii>
int ini[maxn];
int tgt[maxn];

int id[maxn];
int from[maxn];
int to[maxn];

int real_id[maxn];

int main(){

	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d",ini+i);
	
	for(int i=0;i<n;i++)
		scanf("%d",tgt+i);
		
	vector<pii> vv;
	
	for(int i=0;i<n;i++)
		vv.pb(pii(ini[i],i));
		
	sort(vv.begin(), vv.end());
	
	for(int i=0;i<n;i++)
		real_id[i] = vv[i].second;
		
	sort(ini,ini+n);
	sort(tgt,tgt+n);
	
	int A = 0, B = 0;
	
	vector<pip> ans;
	
	for(int i=0;i<n;i++){
		
		if(ini[i] == tgt[i]) continue;
		if(ini[i] < tgt[i]){
			id[B] = i;
			from[B] = ini[i];
			to[B] = tgt[i];
			B++;
		}
		else {
			int has = ini[i] - tgt[i];
			int cur = ini[i];
			
			while(A < B && has){
			
				int can = to[A] - from[A];				
				
				if(can > has){
					ans.pb(pip(has,pii(id[A],i)));
					//ans.pb(pip(id[A],i,has));
					from[A] += has;
					has = 0;
				}
				else if(can == has){
					ans.pb(pip(has,pii(id[A],i)));
					//ans.pb(id[A],i,has);
					has = 0;
					A++;
				}
				else {
					ans.pb(pip(can,pii(id[A],i)));
					//ans.pb(id[A],i,can);
					has -= can;
					A++;
				}
				
			}
			
			if(has > 0){
				printf("NO\n");
				return 0;
			}
			
		}
	}
	
	if(A < B){
		printf("NO\n");
		return 0;
	}
	
	printf("YES\n%d\n",(int)ans.size());
	
	//for(int i=0;i<n;i++)
	//	printf("readid[%d] = %d\n",i,real_id[i]);
	
	for(int i=0;i<ans.size();i++)
		printf("%d %d %d\n",real_id[ans[i].second.first]+1,real_id[ans[i].second.second]+1,ans[i].first);

}