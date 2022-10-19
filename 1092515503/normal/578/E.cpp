#include<bits/stdc++.h>
using namespace std;
char s[100100];
int n,nex[100100],las[100100],res;
vector<int>v[2],u[2][2];
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=1;i<=n;i++){
		v[s[i]=='R'].push_back(i),las[i]=i;
		if(v[s[i]=='L'].empty())res++;
		else las[i]=las[v[s[i]=='L'].back()],nex[v[s[i]=='L'].back()]=i,v[s[i]=='L'].pop_back();
	}
//	for(int i=1;i<=n;i++)printf("[%d,%d]",nex[i],las[i]);puts("");
	printf("%d\n",res-1);
	for(int i=1;i<=n;i++)if(!nex[i])u[s[las[i]]=='R'][s[i]=='R'].push_back(i);
	while(u[0][1].size()>=2){
		int x=u[0][1].back();u[0][1].pop_back();
		int y=u[0][1].back();
		nex[x]=las[y],las[y]=las[x];
	}
	while(u[1][0].size()>=2){
		int x=u[1][0].back();u[1][0].pop_back();
		int y=u[1][0].back();
		nex[x]=las[y],las[y]=las[x];
	}
	if(!u[1][1].empty()&&!u[0][1].empty()){
		int x=u[1][1].back();u[1][1].pop_back();
		int y=u[0][1].back();u[0][1].pop_back();
		nex[x]=las[y],las[y]=las[x];
		u[1][1].push_back(y);
	}
	if(!u[0][0].empty()&&!u[1][0].empty()){
		int x=u[0][0].back();u[0][0].pop_back();
		int y=u[1][0].back();u[1][0].pop_back();
		nex[x]=las[y],las[y]=las[x];
		u[0][0].push_back(y);
	}
	if(!u[0][0].empty()&&!u[0][1].empty()){
		int x=u[0][0].back();u[0][0].pop_back();
		int y=u[0][1].back();u[0][1].pop_back();
		nex[y]=las[x],las[x]=las[y];
		u[0][0].push_back(x);
	}
	if(!u[1][1].empty()&&!u[1][0].empty()){
		int x=u[1][1].back();u[1][1].pop_back();
		int y=u[1][0].back();u[1][0].pop_back();
		nex[y]=las[x],las[x]=las[y];
		u[1][1].push_back(x);
	}
	if(!u[0][1].empty()&&!u[1][0].empty()){
		int x=u[0][1].back(),y=u[1][0].back(),z;u[0][1].pop_back(),u[1][0].pop_back();
		if(x<y){
			for(z=1;z<=n;z++)if(nex[z]==y)break;
			nex[z]=0,las[z]=las[y];
			nex[x]=y,las[y]=las[x];
			u[0][0].push_back(y),u[1][1].push_back(z);
		}else{
			for(z=1;z<=n;z++)if(nex[z]==x)break;
			nex[z]=0,las[z]=las[x];
			nex[y]=x,las[x]=las[y];
			u[1][1].push_back(x),u[0][0].push_back(z);
		}
	}
	for(int i=0;i<min(u[0][0].size(),u[1][1].size());i++){
		nex[u[0][0][i]]=las[u[1][1][i]];
		if(i+1<u[0][0].size())nex[u[1][1][i]]=las[u[0][0][i+1]];
	}
	if(u[1][1].size()>u[0][0].size()&&!u[0][0].empty())nex[u[1][1].back()]=las[u[0][0][0]];
	memset(las,0,sizeof(las));
	for(int i=1;i<=n;i++)if(nex[i])las[nex[i]]=i;
	for(int i=1;i<=n;i++)if(!las[i]){for(int j=i,k=1;k<=n;k++,j=nex[j])printf("%d ",j);break;}
	return 0;
}