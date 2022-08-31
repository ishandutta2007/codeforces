#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
const int max1 = 1003;

char adj[max1][max1];
ll vis[max1][max1], ctt[max1][max1], vis1[max1][max1];
ll t,n,m,u,v;
ll ct;

void dfs(int i,int j){
	if(!vis[i][j]){
		vis[i][j] = 1;
		if(i != 0){
			if(adj[i-1][j] != '.') ct++;
			else dfs(i-1,j);
		}
		if(i != n-1){
			if(adj[i+1][j] != '.') ct++;
			else dfs(i+1,j);
		}
		if(j != 0){
			if(adj[i][j-1] != '.') ct++;
			else dfs(i,j-1);
		}
		if(j != m-1){
			if(adj[i][j+1] != '.') ct++;
			else dfs(i,j+1);
		}
	}

}

void dfs1(int i,int j){
	if(!vis1[i][j]){
		vis1[i][j] = 1;
		ctt[i][j] = ct;
		if(i != 0){
			if(adj[i-1][j] == '.') dfs1(i-1,j);
		}
		if(i != n-1){
			if(adj[i+1][j] == '.') dfs1(i+1,j);
		}
		if(j != 0){
			if(adj[i][j-1] == '.')  dfs1(i,j-1);
		}
		if(j != m-1){
			if(adj[i][j+1] == '.') dfs1(i,j+1);
		}
	}

}


int main(){
    cin>>n>>m>>t;
    for(int i = 0;i<n;i++){
    	for(int j = 0;j<m;j++){
    		cin>>adj[i][j];
    	}
    }

    for(int i = 0;i<n;i++){
    	for(int j = 0;j<m;j++){
    		if(!vis[i][j] && adj[i][j] == '.'){
    			ct = 0;
    			dfs(i,j);
    			dfs1(i,j);
    		}
    	}
    }
    /*
    for(int i = 0;i<n;i++){
    	for(int j = 0;j<m;j++){
    		cout<<ctt[i][j]<<" ";
    	}
    	cout<<endl;
    }
    */
	while(t--){
		cin>>u>>v;
		cout<<ctt[u-1][v-1]<<endl;
	}
	
}