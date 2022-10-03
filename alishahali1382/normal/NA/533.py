#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

struct DSU{
    vector<int> par;
    DSU(int n){
    	for (int i=0;i<n;i++){
        	par.push_back(i);
		}
    }
    int find(int x){
    	if (par[x]==x) return x;
        return par[x]=find(par[x]);
    }
	void join(int x,int y){
        int a=find(x),b=find(y);
		par[b]=a;
    }
};

int main(){
	//freopen("input.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	int p[n];
	for (int i=0;i<n;i++){
		cin>>p[i];
	}
	
	DSU dsu(n);
	int a,b;
	
	for (int i=0;i<m;i++){
		cin>>a>>b;
		dsu.join(a-1,b-1);
	}
	
	
	if (n==1){
		cout<<p[0]<<endl;
		return 0;
	}
	
	vector<int> components[n];
		
	for (int i=0;i<n;i++){
		components[dsu.find(i)].push_back(i);
	}
	int comp[n];
	int index[n];
	int t=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<components[i].size();j++){
			comp[t]=p[components[i][j]];
			index[t]=components[i][j];
			t++;
		}
		sort(comp,comp+t);
		reverse(comp,comp+t);
		for (int j=0;j<t;j++){
			p[index[j]]=comp[j];
		}
		t=0;
	}
	for (int i=0;i<n;i++){
		cout<<p[i]<<' ';
	}
	//cout<<endl;
	return 0;
}