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
#define N 100015
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
using namespace std;
int t,n,m,lk[N],vis[N];
vector<int> e[N];
bool check(){
	for(int i = 1;i <= n;++i){
		if(lk[i] != -1) continue;
		for(int j = 1;j <= n;++j){
			if(!vis[j]){
				puts("IMPROVE");
				cout << i << ' ' << j << endl;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1;i <= n;++i) lk[i] = -1,vis[i] = 0;
		for(int i = 1;i <= n;++i) e[i].clear();
		for(int i = 1;i <= n;++i){
			int u;
			cin >> m;
			for(int j = 1;j <= m;++j){
				cin>>u;e[i].pb(u);
			}
		}
		for(int i = 1;i <= n;++i){
			for(int j = 0;j < e[i].size();++j){
				int v = e[i][j];
				if(vis[v]==0){
					lk[i] = v;
					vis[v] = 1;
					break;
				}
			}
		}
		if(!check())puts("OPTIMAL");
	}
	return 0;
}