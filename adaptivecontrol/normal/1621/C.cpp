#include<bits/stdc++.h>
using namespace std;
int T;
int query(int x){
	printf("? %d\n",x);
	fflush(stdout);
	int ret;scanf("%d",&ret);
	return ret;
}
int p[10003],n;
int main(){
	cin>>T;
	while(T--){
		memset(p,-1,sizeof(p));
		cin>>n;
		for(int i=1;i<=n;i++)
			if(p[i]==-1){
				vector<int>v; 
				int fst=query(i),nw;
				do{
					nw=query(i);
					v.push_back(nw);
				}while(nw!=fst);
				for(int j=0;j<v.size();j++)
					p[v[j]]=v[(j+1)%v.size()];
			}
		cout<<"! ";
		for(int i=1;i<=n;i++)
			printf("%d ",p[i]);
		cout<<endl;fflush(stdout);
	}
}