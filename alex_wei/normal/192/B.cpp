#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+5;
struct node{
	int id,t;
	bool operator < (const node &v) const {
		return t<v.t;
	}
}c[N];
int n,d[N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].t;
		c[i].id=i;
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		if(c[i].id==1||c[i].id==n||d[c[i].id+1]||d[c[i].id-1]){
			cout<<c[i].t;
			exit(0);
		}
		d[c[i].id]=1;
	}
    return 0;
}