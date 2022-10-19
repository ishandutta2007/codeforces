#include<bits/stdc++.h>
#define ll long long
#define N 515
using namespace std;
int n,m,opt,x,y,u,v,red[N][N],green[N][N],yellow[N][N],blue[N][N],d[N][N],f[N][N][20][20];
char s[N][N]; 
bool check(int cur){
	int x1=x+cur-1,y1=y+cur-1,u1=u-cur,v1=v-cur;
	int k1,k2,res;
	k1 = k2 = res = 0;
	while((1<<(k1+1))<=(u1-x1+1)) k1++;
	while((1<<(k2+1))<=(v1-y1+1)) k2++;
	res = max(max(f[x1][y1][k1][k2],f[u1-(1<<k1)+1][v1-(1<<k2)+1][k1][k2]),
	max(f[x1][v1-(1<<k2)+1][k1][k2],f[u1-(1<<k1)+1][y1][k1][k2]));
//	cout << x1 << ' '<< y1 << endl;
//	cout << u1 << ' '<< v1 << endl;
//	cout << k1 << ' '<< k2 << endl;
//	cout << f[x1][y1][k1][k2] << ' '<<f[u1-(1<<k1)+1][v1-(1<<k2)+1][k1][k2]<<' '<<f[x1][v1-(1<<k2)+1][k1][k2]<<' '<<f[u1-(1<<k1)+1][y1][k1][k2]<<endl;
//	cout <<"res: " << res<<endl;
	return res>=cur;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d",&n,&m,&opt);
	for(int i = 1;i <= n;++i)scanf("%s",s[i]+1);
	for(int i = 1;i <= n;++i){
		//cout << i << endl;
		for(int j = 1;j <= m;++j)
			if(s[i][j]=='R') red[i][j] = min(red[i-1][j-1],min(red[i-1][j],red[i][j-1]))+1;
		for(int j = m;j > 0;--j)
			if(s[i][j]=='G') green[i][j] = min(green[i-1][j+1],min(green[i-1][j],green[i][j+1]))+1;
	}
	for(int i = n;i > 0;--i){
		for(int j = 1;j <= m;++j)
			if(s[i][j]=='Y') yellow[i][j] = min(yellow[i+1][j-1],min(yellow[i+1][j],yellow[i][j-1]))+1;
		for(int j = m;j > 0;--j)
			if(s[i][j]=='B') blue[i][j] = min(blue[i+1][j+1],min(blue[i+1][j],blue[i][j+1]))+1;
	}
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= m;++j)
			f[i][j][0][0] = d[i][j] = min(min(red[i][j],green[i][j+1]),min(blue[i+1][j+1],yellow[i+1][j]));
//	for(int i = 1;i <= n;++i){
//		for(int j = 1;j <= m;++j){
//			cout << d[i][j] <<' ';
//		}
//		cout << endl;
//	}
	for(int i = 1;i <= 10;++i)
		for(int p = 1;p + (1<<(i-1)) <= n;++p)
			for(int q = 1;q <= m;++q)
				f[p][q][i][0] = max(f[p][q][i-1][0],f[p+(1<<(i-1))][q][i-1][0]);
	for(int i = 1;i <= 10;++i)
		for(int p = 1;p <= n;++p)
			for(int q = 1;q + (1<<(i-1))<= m;++q)
				f[p][q][0][i] = max(f[p][q][0][i-1],f[p][q+(1<<(i-1))][0][i-1]);
	for(int i = 1;i <= 10;++i)
		for(int j = 1;j <= 10;++j)
			for(int p = 1;p + (1<<(i-1)) <= n;++p)
				for(int q = 1;q + (1<<(j-1)) <= m;++q)
					f[p][q][i][j] = max(max(f[p][q][i-1][j-1],f[p+(1<<(i-1))][q+(1<<(j-1))][i-1][j-1]),
					max(f[p+(1<<(i-1))][q][i-1][j-1],f[p][q+(1<<(j-1))][i-1][j-1]));
	for(int i = 1;i <= opt;++i){
		scanf("%d%d%d%d",&x,&y,&u,&v);
		int l = 0,r = min(u-x+1,v-y+1)/2,mid;
		while(l+3<=r){
			mid = (l+r)>>1;
			if(check(mid)) l = mid;
			else r = mid;			
		}
		for(int i = r;i >= l;--i)
			if(check(i)){
				printf("%d\n",i*i*4);
				break;
			}
//		cout << check(1) << endl;
	}
	return 0;
}