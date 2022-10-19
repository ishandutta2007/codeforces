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
int n;
struct node{
	int mask,typ;
	node(){}
	node(int a,int b){mask = a;typ = b;}
};
string dis[(1<<8)+10][3]; // 0 ! , 1 & ,2 |
int ALL = (1<<8)-1;
int Not(int a){
	return (~a)&ALL;
}
int And(int a,int b){
	return a&b;
}
int Or(int a,int b){
	return a|b;
}
vector<node> opt;
queue<node> q;
int ori[11];
// char get(int x){
// 	if(x == 1) return '!';
// 	if(x == 2) return '&';
// 	if(x == 3) return '|';
// }
bool cmp(string a,string b){
	if(b == "?") return 0;
	if(a == "?") return 1;
 	if(a.length() != b.length()) return a.length() > b.length();
	return a > b;
}
#define INF "?"
int main(){
	//freopen(".in","r",stdin);
	// freopen("ook.out","w",stdout);
	scanf("%d",&n);
	/*
	x : 00001111 = 15
	y : 00110011 = 51
	z : 01010101 = 85
	*/
	// printf("%d\n",Not(51));
	// printf("%d\n",cmp("11451","111451"));
	// return 0;
	rep(i,0,255) rep(j,0,2) dis[i][j] = INF;
	dis[15][0] = "x";dis[51][0] = "y";dis[85][0] = "z";
	opt.pb(node(15,0)); opt.pb(node(51,0)); opt.pb(node(85,0));
	q.push(node(15,0)); q.push(node(51,0)); q.push(node(85,0));
	while(!q.empty()){
		node u = q.front(); q.pop();
		// printf("(%d,%d) = (%d,%d) %c (%d,%d) %d %d\n",u.typ,u.mask,from[u.mask][u.typ].fi.typ,from[u.mask][u.typ].fi.mask,get(fopt[u.mask][u.typ]),from[u.mask][u.typ].se.typ,from[u.mask][u.typ].se.mask,brac[u.mask][u.typ].fi,brac[u.mask][u.typ].se);
		// cout << dis[u.mask][u.typ] << endl;
		opt.pb(u);
		string d = dis[u.mask][u.typ];
		int bl = u.typ > 0, br = u.typ > 0;
		string res = "!" + (bl?"("+d+")":d);
		node nxt = node(Not(u.mask),0);
		// cout << res << endl;
		if(cmp(dis[nxt.mask][nxt.typ] , res )){
			dis[nxt.mask][nxt.typ] = res;
			q.push(nxt);
		}
		for(node x:opt){
			string dd = dis[x.mask][x.typ];
			// u & x / x & u
			bl = u.typ > 1;
			br = x.typ > 0;
			res = (bl?"("+d+")":d) + "&" + (br?"("+dd+")":dd); 
			nxt = node(And(u.mask,x.mask),1);
			if(cmp(dis[nxt.mask][nxt.typ],res)){
				dis[nxt.mask][nxt.typ] = res;
				q.push(nxt);
			}

			bl = x.typ > 1;
			br = u.typ > 0;
			res = (bl?"("+dd+")":dd) + "&" + (br?"("+d+")":d); 
			nxt = node(And(u.mask,x.mask),1);
			if(cmp(dis[nxt.mask][nxt.typ],res)){
				dis[nxt.mask][nxt.typ] = res;
				q.push(nxt);
			}
			// u | x
			br = x.typ > 1; bl = 0;
			res = (bl?"("+d+")":d) + "|" + (br?"("+dd+")":dd);
			nxt = node(Or(u.mask,x.mask),2);
			if(cmp(dis[nxt.mask][nxt.typ] , res)){
				dis[nxt.mask][nxt.typ] = res;
				q.push(nxt);
			}

			br = u.typ > 1; bl = 0;
			res = (bl?"("+dd+")":dd) + "|" + (br?"("+d+")":d);
			nxt = node(Or(u.mask,x.mask),2);
			if(cmp(dis[nxt.mask][nxt.typ] , res)){
				dis[nxt.mask][nxt.typ] = res;
				q.push(nxt);
			}
		}
	}
	rep(_,1,n){
		rep(i,0,7) scanf("%1d",&ori[i]);
		int cur = 0;
		rep(i,0,7) cur = cur*2 + ori[i];
		int typ = 0;
		rep(i,0,2){
			if(cmp(dis[cur][typ] , dis[cur][i])){
				// cout << dis[cur][typ] << " > " << dis[cur][i] << endl;
				typ = i; //cout << typ << endl;
			}
		}
		// cout << typ << endl;
		cout << dis[cur][typ] << endl;
	}
	return 0;
}
/*
4
00110011
00000111
11110000
00011111
*/