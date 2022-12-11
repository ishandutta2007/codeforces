#include<bits/stdc++.h>
#define int long long
#define N 1000000
#define mid (l+r)/2
using namespace std;
int n,a[N+1];
struct dot{
	int x,y;
}d[N+1];
int cro(dot x,dot y){return x.x*y.y-x.y*y.x;}
bool isd(int p,int q,int r){return cro((dot){d[p].y-d[q].y,d[q].x-d[p].x},(dot){d[r].x-d[q].x,d[r].y-d[q].y})<=0;}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>d[i].x>>d[i].y,a[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-2;j++){
			if(isd(a[j],a[j+1],a[j+2])){
				swap(a[j+1],a[j+2]);
			}
		}
	}
	for(int i=1;i<=n-2;i++){
		if(isd(a[i],a[i+1],a[i+2])){
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);printf("\n");
	return 0;
}