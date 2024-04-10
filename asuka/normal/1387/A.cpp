/*
             ,]@@@@@@@@@@@\]            *@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@*
          /@@@@@@@@@@@@@@@@@@@\`        *@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@*
       =/@@@@@@@/[     ,[\@@@@@@@`      *[[[[[[[[[[@@@@@/[[[[[[[[[[     @@@@@*
      =@@@@@@`             *\@@@@@\                @@@@@^               @@@@@*
     /@@@@@^                 *@@@@@@*              @@@@@^               @@@@@*
    =@@@@@`                    \@@@@@              @@@@@^               @@@@@*
   *@@@@@^                     *@@@@@^             @@@@@^               @@@@@*
   =@@@@@                       =@@@@@             @@@@@^               @@@@@*
   @@@@@^                       =@@@@@             @@@@@^               @@@@@*
   @@@@@^                       =@@@@@             @@@@@^               @@@@@*
   @@@@@^                       =@@@@@             @@@@@^               @@@@@*
   =@@@@@                       =@@@@/             @@@@@^               @@@@@*
   ,@@@@@^                     *@@@@@`             @@@@@^               @@@@@*
    =@@@@@`                    @@@@@/              @@@@@^               @@@@@*
     \@@@@@^                 ,@@@@@/               @@@@@^               @@@@@*
      =@@@@@@]             ,@@@@@@^                @@@@@^               @@@@@*
        \@@@@@@@@]]]]]]]/@@@@@@@/                  @@@@@^               @@@@@@@@@@@@@@@@@@@`
          [@@@@@@@@@@@@@@@@@@@`                    @@@@@^               @@@@@@@@@@@@@@@@@@@^
              [\@@@@@@@@@[[                        [[[[[`               [[[[[[[[[[[[[[[[[[[`





         ,@@@@@\               ,@@@@@`         =@@@@@      =@@@@@@@@@@@@@@@@@@@@@@@@@@
          ,@@@@@\             ,@@@@@`          =@@@@@      =@@@@@@@@@@@@@@@@@@@@@@@@/
           ,@@@@@\           ,@@@@@`           =@@@@@                        ,@@@@@`
            *@@@@@^         ,@@@@@`            =@@@@@                       /@@@@@
             *@@@@@^       ,@@@@@`             =@@@@@                     *@@@@@^
              *@@@@@^     ,@@@@@*              =@@@@@                    ,@@@@@`
               *@@@@@^   ,@@@@@*               =@@@@@                   /@@@@/
                *@@@@@^ ,@@@@@                 =@@@@@                 ,@@@@@^
                 *@@@@@\@@@@@                  =@@@@@                =@@@@@`
                  *@@@@@@@@@                   =@@@@@               /@@@@/
                   *@@@@@@@                    =@@@@@             ,@@@@@`
                    *@@@@@                     =@@@@@            =@@@@@*
                    *@@@@@                     =@@@@@          *@@@@@/
                    *@@@@@                     =@@@@^         ,@@@@@`
                    *@@@@@                    ,@@@@@*        /@@@@@
                    *@@@@@                   ,@@@@@`       *@@@@@/
                    *@@@@@            =@@@@@@@@@@@`       ,@@@@@@@@@@@@@@@@@@@@@@@@@@^
                    *@@@@@            =@@@@@@@@/`        =@@@@@@@@@@@@@@@@@@@@@@@@@@@^
*/
#include<bits/stdc++.h>
#define ll long long
#define db double
#define N 100015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,m,head[N],cnt,vis[N],tot,flag;
db rt[N],val[N];
struct node{
	int a,b,bel;//ax+b
}x[N]; 
struct edge{
	int typ,to,next;
	edge(){}
	edge(int a,int b,int c){typ = a;to = b;next = c;}
}e[N<<2];
void add(int u,int v,int w){
	e[++cnt] = edge(w,v,head[u]);
	head[u] = cnt;
}
VI v;
void dfs(int u){
	vis[u] = 1;x[u].bel = tot;
	v.pb(-x[u].a*x[u].b);
//	cout << u << ' ' << x[u].a << ' ' << x[u].b << endl; 
	for(int i = head[u];~i;i = e[i].next){
		int v = e[i].to,t = e[i].typ,ta,tb;
		ta = -x[u].a;
		if(t==1) tb = 1-x[u].b;
		else tb = 2-x[u].b;
		if(!vis[v]){
			x[v].a = ta;x[v].b = tb;
			dfs(v);
		}else{
			if(ta-x[v].a==0.0){
				if(x[v].b-tb==0.0) continue; 
				else{
					cout << "NO\n";
					exit(0);
				}
			}else{
				db root = 1.0*(1.0*x[v].b-tb)/(1.0*(ta-x[v].a));
				if(rt[tot] == -1.0*inf){
					rt[tot] = root;
					continue;
				}
				if(rt[tot] != root){
					cout << "NO\n";
					exit(0);
				}else{
					rt[tot] = root;
					continue;
				}
			}
		}
		
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(head,-1,sizeof head);
	cin>>n>>m;
	rep(i,1,n) rt[i] = -1.0*inf;
	rep(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	rep(i,1,n){
		if(vis[i]) continue;
		v.clear();
		x[i].a = 1;
		tot++,dfs(i);
		if(rt[tot]==-1.0*inf){
			sort(v.begin(),v.end());
			rt[tot] = 1.0*v[((int)v.size()+1)/2-1];
		}
	//	cout << rt[tot] << "RTYURY\n";
	}
	cout << "YES\n";
	cout << fixed;
	rep(i,1,n){
		cout <<setprecision(6) << 1.0*x[i].a*rt[x[i].bel]+1.0*x[i].b <<  ' ';
	}
	return 0;
}