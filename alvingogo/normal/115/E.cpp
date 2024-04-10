#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0);ios_base::sync_with_stdio(false);cout.tie(0);

using namespace std;
vector<long long int> dp;
vector<long long int> c;
struct P{
	long long int lb,rb,p;
};
vector<P> vp;
int pvp=0;

vector<long long int> st,tag;

void pudo(int v){//push_down
	st[2*v+1]+=tag[v];
	tag[2*v+1]+=tag[v];
	st[2*v+2]+=tag[v];
	tag[2*v+2]+=tag[v];
	tag[v]=0;
	//st[v]=max(st[2*v+1],st[2*v+2]);
}
void moin(int l,int r,long long int k,int v,int L,int R){//modify_interval
	if(l==L && r==R){
		//cout << v << " ";
		//cout << st[v] << " ";
		st[v]+=k;
		//cout << st[v] << endl;
		tag[v]+=k;
		return;
	}
	if(l>R || L>r){
		return;
	}
	if(tag[v]!=0){
		pudo(v);
	}
	int M=(L+R)/2;
	
	if(r<=M){
		moin(l,r,k,2*v+1,L,M);
	}
	else if(l>M){
		moin(l,r,k,2*v+2,M+1,R);
	}
	else{
		moin(l,M,k,2*v+1,L,M);
		moin(M+1,r,k,2*v+2,M+1,R);
	}
	st[v]=max(st[2*v+1],st[2*v+2]);
}
long long int query(int l,int r,int L,int R,int v){
	if(l>=L && r<=R){
		//cout << v << " " << st[v] << endl;
		
		return st[v];
	}
	if(l>R || L>r){
		//cout << l << r << L << R << endl;
		return 0;
	}
	if(tag[v]!=0){
		pudo(v);
	}
	
	int M=(L+R)/2;
	if(r<=M){
		//cout << v << M << " ";
		return query(l,r,L,M,2*v+1);
	}
	else if(l>M){
		//cout << v << M << " ";
		return query(l,r,M+1,R,2*v+2);
	}
	else{
		//cout << v << M << " ";
		return max(query(l,M,L,M,2*v+1),query(M+1,r,M+1,R,2*v+2));
	}
}
bool cmpr(P a,P b){
	return a.rb<b.rb;
}
int main(){
	fastio;
	int n,m;
	cin >> n >> m;
	c.resize(n);
	dp.resize(n);
	for(int i=0;i<n;i++){
		cin >> c[i];
	}
	P temp;
	long long int tlb,trb,tp;
	for(int i=0;i<m;i++){
		cin >> tlb >> trb >> tp;
		tlb--;
		trb--;
		temp.lb=tlb;
		temp.rb=trb;
		temp.p=tp;
		vp.push_back(temp);
	}
	sort(vp.begin(),vp.end(),cmpr);
	
	st.resize(4*n);
	tag.resize(4*n);
	//dp[i]=max(max_all_j<i{dp[j]+profit(j+1,r)-cost(j+1,r)},dp[i-1]);
	for(int i=0;i<n;i++){
		while(pvp<m && vp[pvp].rb<=i){
			moin(0,vp[pvp].lb,vp[pvp].p,0,0,n-1);//
			pvp++;
		}
		moin(0,i,-c[i],0,0,n-1);//
		/*
		for(int i=0;i<4*n;i++){
			cout << st[i] << " ";
		}
		cout << endl;
		for(int i=0;i<4*n;i++){
			cout << tag[i] << " ";
		}
		cout << endl;
		*/
		dp[i]=query(0,i,0,n-1,0);//
		/*
		for(int i=0;i<4*n;i++){
			cout << st[i] << " ";
		}
		cout << endl;
		for(int i=0;i<4*n;i++){
			cout << tag[i] << " ";
		}
		cout << endl;
		*/
		dp[i]=max(dp[i],(long long)0);//
		if(i>0){
			dp[i]=max(dp[i],dp[i-1]);
			
		}
		moin(i+1,n-1,dp[i]-(i>0)*dp[i-1],0,0,n-1);
		/*
		for(int i=0;i<4*n;i++){
			cout << st[i] << " ";
		}
		cout << endl;
		for(int i=0;i<4*n;i++){
			cout << tag[i] << " ";
		}
		cout << endl << endl;*/
	}
	/*
	for(int i=0;i<n;i++){
		cout << dp[i] << " ";
	}
	cout << endl;*/
	
	cout << dp[n-1] << "\n";
	return 0;
}