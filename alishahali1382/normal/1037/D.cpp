#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=200 * 1000 + 10;

int n, x, y, tmp;
int A[MAXN];
int B[MAXN];
int par[MAXN];
int level[MAXN];
bool mark[MAXN];

vector<int> G[MAXN];
queue<int> Q;

bool check(int node){/*
	if (mark[x]) return false ;
	mark[x]=true;*/
	
	int s=0;
	int a=MAXN, b=0;
	
	for (int v : G[node]){
		if (v==par[node]) continue ;
		//if (B[v]<B[node]+1 || B[node]+s<B[v]) return false ;
		if (!check(v)) return false ;
		
		s++;
		if (B[v]<a) a=B[v];
		if (B[v]>b) b=B[v];
	}
	//cout<<node<<' '<<' '<<endl;
	return (b-a+1==s) || !s;
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n-1; i++){
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for (int i=1; i<=n; i++){
		cin>>A[i];
		B[A[i]]=i;
	}
	for (int i=1; i<=n; i++){
		if (!A[i]){
			cout<<"No"<<endl;
			return 0;
		}
	}
	
	Q.push(1);
	mark[1]=true;
	while (!Q.empty()){
		tmp=Q.front();
		level[tmp]=level[par[tmp]]+1;
		Q.pop();
		for (int v : G[tmp]){
			if (v==par[tmp] || mark[v]) continue ;
			par[v]=tmp;
			Q.push(v);
			mark[v]=true;
		}
		//cout<<tmp<<endl;	
	}
	for (int i=2; i<n; i++){
		if (par[A[i-1]]==par[A[i+1]] && par[A[i-1]]!=par[A[i]]){
			cout<<"No"<<endl;
			return false ;
		}
	}
	for (int i=1; i<n; i++){
		if (level[A[i]]>level[A[i+1]] || B[par[A[i]]]>B[par[A[i+1]]]){
			cout<<"No"<<endl;
			return false ;
		}
	}
	/*
	vector<int> child;
	for (int i=1; i<=n; i++){
		for (int v : G[i]){
			if (v==par[i]) continue ;
			child.push_back(B[v]);
		}
		if (max_element())
	}*/
	
	memset(mark, false, sizeof(mark));
	
	//for (int i=1; i<=n; i++) cout<<par[i]<<endl;
	
	if (A[1]==1 && check(1)){
		cout<<"Yes"<<endl;
		return 0;
	}
	cout<<"No"<<endl;
	//cout<<check(2)<<endl;
	
	return 0;
}