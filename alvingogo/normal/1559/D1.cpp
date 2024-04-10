#include <iostream>
#include <vector>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);cout.tie(0);
using namespace std;

vector<vector<int> > h(2);

int find(int x,int a){
	if(h[x][a]==a){
		return a;
	}
	h[x][a]=find(x,h[x][a]);
	return h[x][a];
}
void un(int x,int a,int b){
	int x1=find(x,a);
	int x2=find(x,b);
	h[x][x1]=x2;
}
int main(){
	fastio;
	int n,m1,m2;
	cin >> n >> m1 >> m2;
	h[0].resize(n);
	h[1].resize(n);
	for(int i=0;i<n;i++){
		h[0][i]=i;
		h[1][i]=i;
	}
	int a,b;
	for(int i=0;i<m1;i++){
		cin >> a >> b;
		a--;
		b--;
		un(0,a,b);
	}
	for(int i=0;i<m2;i++){
		cin >> a >> b;
		a--;
		b--;
		un(1,a,b);
	}
	int x=0;
	vector<pair<int,int> > v;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(find(0,i)!=find(0,j) && find(1,i)!=find(1,j)){
				un(0,i,j);
				un(1,i,j);
				v.push_back(make_pair(i+1,j+1));
				x++;
			}
		}
	}
	cout << x << "\n";
	for(int i=0;i<x;i++){
		cout << v[i].first << " " << v[i].second << "\n";
	}
	return 0;
}