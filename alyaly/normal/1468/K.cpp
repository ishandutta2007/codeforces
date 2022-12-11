#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a),i##z=(b);i<=i##z;i++)
#define ROF(i,a,b) for(int i=(a),i##z=(b);i<=i##z;i--)
#define temT template<typename T>
using namespace std;
const int N=int(5e3)+10;

int n,Q; int a[N][2];

void mread(int ar[N][2],int &len){
	len=0; char t=getchar();
	while(!isalpha(t)) t=getchar();
	while(isalpha(t)){
		len++;
		if(t=='L') ar[len][0]=-1,ar[len][1]=0;
		if(t=='R') ar[len][0]=1,ar[len][1]=0;
		if(t=='U') ar[len][0]=0,ar[len][1]=1;
		if(t=='D') ar[len][0]=0,ar[len][1]=-1;
		t=getchar();
	}
}

bool dfs(int p,int x,int y,int bx,int by){
	if(p==n+1) return x==0 && y==0;
	int tx=x+a[p][0],ty=y+a[p][1];
	if(tx==bx && ty==by)
		return dfs(p+1,x,y,bx,by);
	else
		return dfs(p+1,tx,ty,bx,by);
}

int main(){
	
	scanf("%d",&Q);
	
	while(Q--){
		
		mread(a,n);
		int x=0,y=0; bool flag=0;
		
		FOR(i,1,n){
			int tx=x+a[i][0],ty=y+a[i][1];
			if(dfs(1,0,0,tx,ty))
				cout<<tx<<" "<<ty<<"\n",flag=1;
			if(flag) break; else x=tx,y=ty;
		}
		
		if(!flag) cout<<0<<" "<<0<<"\n";
		
	}
	
	return 0;
}