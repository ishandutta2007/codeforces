#include<bits/stdc++.h>
using namespace std;
struct sp{
	int mx[10],mn[10];
	int sz;
}s[500100];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	map<int,sp> tm;
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			scanf("%d",&s[i].mx[j]);
			s[i].mn[j]=s[i].mx[j];
		}
		s[i].sz=1;
	}
	for(int i=0;i<n;i++){
		tm[s[i].mn[0]]=s[i];
		auto it = tm.find(s[i].mn[0]),nit=it;
		++nit;
		while(nit!=tm.end()){
			bool mg=false;
			for(int j=0;j<k;j++){
				if(nit->second.mn[j]<it->second.mx[j]){
					mg=true;
					break;
				}
			}
			if(mg){
				for(int j=0;j<k;j++){
					it->second.mn[j]=min(it->second.mn[j],nit->second.mn[j]);
					it->second.mx[j]=max(it->second.mx[j],nit->second.mx[j]);
				}
				it->second.sz+=nit->second.sz;
				nit=tm.erase(nit);
			}
			else break;
		}
		nit=it;
		while(nit!=tm.begin()){
			--nit;
			bool mg=false;
			for(int j=0;j<k;j++){
				if(nit->second.mx[j]>it->second.mn[j]){
					mg=true;
					break;
				}
			}
			if(mg){
				for(int j=0;j<k;j++){
					it->second.mn[j]=min(it->second.mn[j],nit->second.mn[j]);
					it->second.mx[j]=max(it->second.mx[j],nit->second.mx[j]);
				}
				it->second.sz+=nit->second.sz;
				nit=tm.erase(nit);
			}
			else break;
		}
		printf("%d\n",tm.rbegin()->second.sz);
	}
	return 0;
}