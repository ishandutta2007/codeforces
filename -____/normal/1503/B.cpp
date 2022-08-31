#include<bits/stdc++.h>
using namespace std;
const int N = 111;
int n,a[N][N];
int rd(){
	int x;
	cin>>x;
	return x;
}
void pt(int x,pair<int,int> p){
	int i=p.first,j=p.second;
	a[i][j]=x;
	cout<<x<<' '<<i<<' '<<j<<endl;
}
vector<pair<int,int> > v[2];
int main(){
	int T,i,j,x,y,o,u;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			v[(i+j)%2].push_back(make_pair(i,j));
	x=0,y=0;
	for(i=1;i<=n*n;i++){
		o=rd();
		if(o==1)
			pt(2,v[1][y++]);
		else
			pt(1,v[0][x++]);
		if(x>=v[0].size()||y>=v[1].size())
			break;
	}
	if(x>=v[0].size()){
		o=1;
		swap(v[0],v[1]);
		swap(x,y);
	}
	else
		o=2;
	for(i++;i<=n*n;i++){
		u=rd();
		if(u!=o)
			pt(u^o,v[0][x++]);
		else
			pt(3,v[0][x++]);
	}
	return 0;
}