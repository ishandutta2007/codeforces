#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LL long long
const LL INF=1e18;
int n,m;
int S[10];
void MAIN(){
	cin>>n>>m;
	cout<<"SCAN "<<1<<" "<<1<<endl;
	cin>>S[1];//x1+x2+y1+y2-4
	cout<<"SCAN "<<n<<" "<<1<<endl;
	cin>>S[2];//-x1-x2+y1+y2-2+n+n
	int Y=(S[1]+S[2]-n-n+6)/2;//y1+y2
	int X=(S[1]-Y+4);//x1+x2
	
//	cout<<X<<" "<<Y<<endl;
	int L=n+1,R=0;
	for(int i=1,j;i<=n;++i){
		j=X-i;
		if(j>=1&&j<=n){
			L=min(i,L);
			R=max(i,R);
		}
	}
	int mid;
	mid=(L+R)>>1;
	cout<<"SCAN "<<mid<<" "<<1<<endl;
	cin>>S[3];//(x1-mid)+(x2-mid)+y1+y2-2
	S[3]+=2;//(x1-mid)+(x2-mid)+y1+y2
	S[3]-=Y;//(x1-mid)+(x2-mid)
	int x[2],y[2];
	for(int i=1,j;i<=n;++i){
		j=X-i;
		if(abs(i-mid)+abs(j-mid) == S[3]){
			x[0]=i;
			x[1]=j;
		}
	}
	L=m+1;R=0;
	for(int i=1,j;i<=m;++i){
		j=Y-i;
		if(j>=1&&j<=m){
			L=min(i,L);
			R=max(i,R);
		}
	}
	mid=(L+R)>>1;
	cout<<"SCAN "<<1<<" "<<mid<<endl;
	cin>>S[4];//x1+x2-2+(y2-mid)+(y1-mid)
	S[4]+=2;//x1+x2+(y2-mid)+(y1-mid)
	S[4]-=X;//(y2-mid)+(y1-mid)
	for(int i=1,j;i<=m;++i){
		j=Y-i;
		if(abs(i-mid)+abs(j-mid) == S[4]){
			y[0]=i;
			y[1]=j;
		}
	}
	cout<<"DIG "<<x[0]<<" "<<y[0]<<endl;
	cin>>S[5];
	if(S[5]==1){
		cout<<"DIG "<<x[1]<<" "<<y[1]<<endl;
		cin>>S[6];
	}
	else{
		cout<<"DIG "<<x[0]<<" "<<y[1]<<endl;
		cin>>S[6];
		cout<<"DIG "<<x[1]<<" "<<y[0]<<endl;
		cin>>S[7];
	}
	return;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int ttt=1;cin>>ttt;
	while(ttt--) MAIN();
	return 0;
}