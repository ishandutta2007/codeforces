#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

vector<char> a;
struct ST{
	char st[800000][101];
	bool bl[800000]={0};
	//vector<vector<char> > st;
	//vector<bool> bl;
	void init(int n){
		//st.resize(4*n,vector<char>(101));
		for(int i=0;i<4*n;i++){
			for(char c=1;c<=100;c++){
				st[i][c]=c;
			}
		}
		//bl.resize(4*n);
	}
	void upd(int v,char a,char b){
		for(char c=1;c<=100;c++){
			if(st[v][c]==a){
				st[v][c]=b;
			}
		}
	}
	void pudo(int v){
		for(char c=1;c<=100;c++){
			st[2*v+1][c]=st[v][st[2*v+1][c]];
			st[2*v+2][c]=st[v][st[2*v+2][c]];
		}
		for(char c=1;c<=100;c++){
			st[v][c]=c;
		}
		bl[2*v+1]=1;
		bl[2*v+2]=1;
		bl[v]=0;
	}
	void update(int v,int L,int R,int l,int r,char a,char b){
		if(l==L && r==R){
			upd(v,a,b);
			bl[v]=1;
			return;
		}
		int m=(L+R)/2;
		if(bl[v]){
			pudo(v);
		}
		if(r<=m){
			update(2*v+1,L,m,l,r,a,b);
		}
		else if(l>m){
			update(2*v+2,m+1,R,l,r,a,b);
		}
		else{
			update(2*v+1,L,m,l,m,a,b);
			update(2*v+2,m+1,R,m+1,r,a,b);
		}
	}
	void query(int v,int L,int R){
		if(L==R){
			cout << (int)st[v][a[L]] << " ";
			return;
		}
		if(bl[v]){
			pudo(v);
		}
		int m=(L+R)/2;
		query(2*v+1,L,m);
		query(2*v+2,m+1,R);
	}
};
int main(){
	AquA;
	int n;
	cin >> n;
	a.resize(n);
	ST st;
	st.init(n);
	for(int i=0;i<n;i++){
		int y;
		cin >> y;
		a[i]=y;
	}
	int q;
	cin >> q;
	while(q--){
		int l,r,a,b;
		cin >> l >> r >> a >> b;
		l--;
		r--;
		st.update(0,0,n-1,l,r,a,b);
	}
	st.query(0,0,n-1);
	cout << "\n";
	return 0;
}