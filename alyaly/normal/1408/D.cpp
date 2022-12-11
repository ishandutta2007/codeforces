#include<bits/stdc++.h>
#define int long long
using namespace std;
struct dot{
	int x,y;
} a[100001],b[100001];
int n,m,ans=999999999;
vector<int> ve[1000003];
multiset<int> se;
bool comp(dot x,dot y){return x.x<y.x;}
signed main(){
cin>>n>>m;
	 for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
	 for(int i=1;i<=m;i++)cin>>b[i].x>>b[i].y;
	 
	 sort(b+1,b+m+1,comp);
	 b[m+1].x=b[m].x+1;b[0].x=-1;
	 for(int i=m-1;i>=0;i--)b[i].y=max(b[i].y,b[i+1].y);
	 for(int i=1;i<=n;i++){
	 	for(int j=0;j<=m;j++){
	 		if(b[j].x<a[i].x)continue;
		  if(b[j].y<a[i].y)continue;
	 		ve[max(0ll,b[j-1].x-a[i].x+1)].push_back(b[j].y-a[i].y+1);
	 		ve[max(0ll,b[j].x-a[i].x+1)].push_back(-(b[j].y-a[i].y+1));
		 }
	 }
	 for(int i=0;i<=b[m].x+1;i++){
	 	for(int j=0;j<ve[i].size();j++){
	 		if(ve[i][j]>=0){
	 			se.insert(-ve[i][j]);
			 }
		 }
		 for(int j=0;j<ve[i].size();j++){
	 		if(ve[i][j]<0){
	 			se.erase(se.find(ve[i][j]));
			 }
		 }
		 ans=min(ans,-*se.begin()+i);
	 }
	 printf("%lld\n",ans);
	return 0;
}