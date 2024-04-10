#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int t,x,y,ans;
int get(int x,int y){
	if(y==1) return orz;
	int cnt=0;
	while(x)x/=y,++cnt;
	return cnt;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&x,&y);
		ans=orz;
		for(int i=0;i<ans;++i)ans=min(ans,i+get(x,y+i));
		printf("%d\n",ans);
	}
    return 0;
}