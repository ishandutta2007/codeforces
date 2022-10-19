#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int> >v[2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)v[(i+j)&1].push_back(make_pair(i,j));
	for(int i=1,x;i<=n*n;i++){
		scanf("%d",&x);
		if(x==1){
			if(!v[1].empty()){printf("%d %d %d\n",2,v[1].back().first,v[1].back().second);v[1].pop_back();}
			else{printf("%d %d %d\n",3,v[0].back().first,v[0].back().second);v[0].pop_back();}
		}
		if(x==2){
			if(!v[0].empty()){printf("%d %d %d\n",1,v[0].back().first,v[0].back().second);v[0].pop_back();}
			else{printf("%d %d %d\n",3,v[1].back().first,v[1].back().second);v[1].pop_back();}
		}
		if(x==3){
			if(!v[1].empty()){printf("%d %d %d\n",2,v[1].back().first,v[1].back().second);v[1].pop_back();}
			else{printf("%d %d %d\n",1,v[0].back().first,v[0].back().second);v[0].pop_back();}
		}
		fflush(stdout);
	}
	return 0;
}