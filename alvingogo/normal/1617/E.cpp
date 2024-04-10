#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int f(int x){
	if(x==1){
		return 0;
	}
	int a=(1<<(__lg(x-1)+1))-x;
	return a;
}
int cnt(int x,int y){
	if(x==y){
		return 0;
	}
	if(x<y){
		swap(x,y);
	}
	return 1+cnt(f(x),y);
}
int main(){
	AquA;
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	pair<int,int> a={0,0};
	for(int i=1;i<n;i++){
		a=max(a,{cnt(v[0],v[i]),i});
	}
	pair<int,int> b={0,0};
	for(int i=0;i<n;i++){
		b=max(b,{cnt(v[a.sc],v[i]),i});
	}
	cout << a.sc+1 << " " << b.sc+1 << " " << b.fs << "\n";
	return 0;
}