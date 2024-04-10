#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

struct ST{
	vector<int> st;
	void init(int x){
		st.resize(4*x,-2);
	}
	void update(int v,int L,int R,int p,int x){
		if(L==R){
			st[v]=x;
			return;
		}
		int m=(L+R)/2;
		if(p<=m){
			update(2*v+1,L,m,p,x);
		}
		else{
			update(2*v+2,m+1,R,p,x);
		}
		st[v]=min(st[2*v+1],st[2*v+2]);
	}
	int query(int v,int L,int R,int r){
		if(L==R){
			return st[v];
		}
		int m=(L+R)/2;
		if(r<=m){
			return query(2*v+1,L,m,r);
		}
		else{
			return min(st[2*v+1],query(2*v+2,m+1,R,r));
		}
	}
}st;
int main(){
    AquA;
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> ans(n+3);
	st.init(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
		v[i]--;
	}
	for(int i=0;i<n;i++){
		if(v[i]!=0){
			ans[0]=1;
		}
	}
	vector<int> lst(n+1,-1);
	for(int i=0;i<n;i++){
		if(v[i] && st.query(0,0,n-1,v[i]-1)>lst[v[i]]){
			ans[v[i]]=1;
		}
		st.update(0,0,n-1,v[i],i);
		lst[v[i]]=i;
	}
	int tmp=0;
	for(int i=0;i<=n;i++){
		if(lst[i]>=0){
			if(i==0){
				continue;
			}
			if(st.query(0,0,n-1,i-1)>lst[i]){
				ans[i]=1;
			}
		}
		else{
			if(tmp){
				continue;
			}
			ans[i]=1;
			tmp=1;
		}
	}
	for(int i=0;i<=n+2;i++){
		if(!ans[i]){
			cout << i+1 << "\n";
			return 0;
		}
	}
    return 0;
}