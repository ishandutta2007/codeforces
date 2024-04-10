#include<bits/stdc++.h>
using namespace std;
int T,X,Y,dx[8]={0,1,1,1,0,-1,-1,-1},dy[8]={1,1,0,-1,-1,-1,0,1};
string s;
bool g[10][10],h[10][10];
bool func(){
	cout<<X<<' '<<Y<<endl,cout.flush();
	cin>>s;
	if(s=="Done")return true;
	int tp;
	if(s=="Right")tp=0;
	if(s=="Down-Right")tp=1;
	if(s=="Down")tp=2;
	if(s=="Down-Left")tp=3;
	if(s=="Left")tp=4;
	if(s=="Up-Left")tp=5;
	if(s=="Up")tp=6;
	if(s=="Up-Right")tp=7;
	for(int i=1;i<=8;i++)for(int j=1;j<=8;j++)h[i+dx[tp]][j+dy[tp]]=g[i][j];
	memcpy(g,h,sizeof(h));
	for(tp=0;tp<8;tp++){
		int i=X,j=Y;
		while(i<=8&&j<=8&&i&&j)g[i][j]=false,i+=dx[tp],j+=dy[tp];
	}
	return false;
}
int main(){
	cin>>T;
	while(T--){
		for(int i=1;i<=8;i++)for(int j=1;j<=8;j++)g[i][j]=true;
		X=1,Y=1;if(func())continue;
		while(true){
			int t=1;
			while(t<=8&&!g[X+1][t])t++;
			if(t>8){
				X++;
				if(func())break;
				continue;
			}
			Y=t;if(func())break;
		}
	}
	return 0;
}