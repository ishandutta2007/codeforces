#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
typedef long long ll;
int n,m;
char tu[55][55];
string ope;
int map_[4],stx,sty,edx,edy,ans;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
int a[4]={0,1,2,3};
bool judge(int x,int y){
	if(x<1||x>n||y<1||y>m) return false;
	if(tu[x][y]=='#') return false;
	return true;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>tu[i][j];
			if(tu[i][j]=='S'){
				stx=i;sty=j;
			}else if(tu[i][j]=='E'){
				edx=i;edy=j;
			}
		}
	}
	cin>>ope;
	do{
		for(int i=0;i<=3;i++) map_[i]=a[i];
		int cx=stx,cy=sty;
		bool fl=1;
		for(int i=0;i<ope.size();i++){
			cx+=dx[map_[ope[i]-'0']];
			cy+=dy[map_[ope[i]-'0']];
			if(cx==edx&&cy==edy){
				ans++;
				break;
			}
			if(!judge(cx,cy)){
				fl=0;
				break;
			}
		}
	}while(next_permutation(a,a+4));
	cout<<ans<<endl;
	return 0;
}