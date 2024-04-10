#include<bits/stdc++.h>
using namespace std;
int n,q,BBB,acc[510][4],BLK[100100],LP[510],mp[100100];
void func(int ip){
	for(int i=1;i<4;i++){
		int state=i;
		for(int j=LP[ip];j<LP[ip+1];j++){
			state&=mp[j];
			if(!state)break;
			if(mp[j]==3)state=3;
		}
		acc[ip][i]=state;
	}
}
bool calc(){
	int state=1;
//	for(int i=0;i<n;i++)printf("%d ",mp[i]);puts("");
	for(int i=0;i<=BLK[n-1];i++)state=acc[i][state];
	return state&2;
}
int main(){
	scanf("%d%d",&n,&q),BBB=sqrt(n),BBB=max(BBB,1);
	for(int i=0;i<n;i++)BLK[i]=i/BBB,mp[i]=3;
	for(int i=0;i<=BLK[n-1];i++)LP[i]=i*BBB;
	LP[BLK[n-1]+1]=n;
	for(int i=0;i<=BLK[n-1];i++)for(int j=1;j<4;j++)acc[i][j]=3;
	for(int i=1,x,y;i<=q;i++)scanf("%d%d",&y,&x),mp[x-1]^=1<<(y-1),func(BLK[x-1]),puts(calc()?"YES":"NO");
	return 0;
}