#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,x[6005],y[6005];
int f[6][6];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",x+i,y+i);
	for(int i=1;i<=n;++i)++f[x[i]&3][y[i]&3];
	ll ans=0;
	for(int x=0;x<=2;x+=2){
		for(int y=0;y<=2;y+=2){
			ans+=f[x][y]*1ll*(f[x][y]-1ll)*(f[x][y]-2ll)/6ll;
			ans+=f[x][y]*1ll*(f[2-x][2-y])*(f[2-x][2-y]-1ll)/2ll;
			ans+=f[x][y]*1ll*(f[2-x][y])*(f[2-x][y]-1ll)/2ll;
			ans+=f[x][y]*1ll*(f[x][2-y])*(f[x][2-y]-1ll)/2ll;
		}
	}
	cout<<ans<<endl;
    return 0;
}