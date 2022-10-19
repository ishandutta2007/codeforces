#include<bits/stdc++.h>
#define ll long long
#define N
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int mod = 1e9+7;
int n = 7,w[9];
struct mat{
	int a[135][135];
	int len;
	mat(){memset(a,0,sizeof a);}
	void print(){
		rep(i,0,len-1) rep(j,0,len-1){
			printf("%d%c",a[i][j],(j==len-1)?'\n':' ');
		} 
		printf("\n");
	}
	int* operator[](int i){return a[i];}
	mat operator *(mat lhs) const{
		mat t;
		rep(i,0,len-1) rep(j,0,len-1) rep(k,0,len-1) t[i][k] = (t[i][k] + (1ll*a[i][j]*lhs[j][k])%mod)%mod;
		return t;
	}
}base[9],cur;
void init(int x){
	base[x].len = (1<<x);
	int all = (1<<x)-1,All = (1<<(x+x+1))-1;
	rep(s,0,All){
		if(!(s&1) || !((s>>(x+x))&1)) continue;
		rep(ss,0,all){
			bool flag = 1;
			rep(i,1,x) if((1<<(i-1))&ss){
				if((1<<(i+i-1))&s){ flag = 0; break; }
			}
			if(!flag) continue;
			int ts = 0;
			rep(i,1,x) if(((s>>(i+i-2))&1) && ((s>>(i+i-1))&1) && ((s>>(i+i))&1)) ts += (1<<(i-1));
			base[x][ss][ts]++;
		}
	}
}
mat qpow(mat a,int b){
	mat res; int len = a.len;
	res.len = len;
	rep(i,0,len-1) res[i][i] = 1;
	while(b){
		if(b&1) res = a*res,res.len = len;
		a = a*a; a.len = len;
		b >>= 1;
	}
	return res;
}
void trans(mat &X,int x,mat &Y,int y){
	int ax = (1<<x)-1,ay = (1<<(y+y+1))-1;
	rep(sy,0,ay){
		bool flag = 1;
		flag &= (sy&1) && ((sy>>(y+y))&1);
		rep(i,x+1,y) flag &= ((sy>>(i+i-1))&1);
		if(!flag) continue;
		rep(sx,0,ax){
			bool Flag = 1;
			rep(i,1,x) if((1<<(i-1))&sx){
				if((1<<(i+i-1)&sy)) {Flag = 0; break; }
			}
			if(!Flag) continue;
			int ty = 0;
			rep(i,1,y) if((sy>>(i+i-2)&1) && ((sy>>(i+i-1))&1) && ((sy>>(i+i))&1)) ty += (1<<(i-1));
			Y[0][ty] = (Y[0][ty] + X[0][sx])%mod;
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	rep(i,1,n) scanf("%d",&w[i]);
	rep(i,1,n) init(i);
	int lst = 0;
	cur[0][0] = cur[0][1] = 1;
	// base[2].print();
	rep(i,1,n){
		if(w[i] > 0){
			mat tmp;
			trans(cur,lst,tmp,i); lst = i; cur = tmp; cur.len = (1<<i);
			// cur.print();
			if(w[i] > 1){
				assert(cur.len == base[i].len);
				cur = cur*qpow(base[i],w[i]-1);
				cur.len = (1<<i);
				// printf("qpow\n");
				// cur.print();
			}
		}
	}
	printf("%d\n",cur[0][0]);
	return 0;
}