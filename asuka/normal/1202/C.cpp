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
#define N 200015
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
using namespace std;
int t;
string s;
ll Min(ll a ,ll b){return a<b?a:b;}
struct node{
	int val,id;
	bool operator < (const node & a){
		if(a.val != val) return a.val>val;
		return a.id>id;
	}
}dx[N],dy[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>s;ll ans = inf;
		int n = s.length();
		dx[0].val = dx[0].id = dy[0].val = dy[0].id = 0;
		for(int i = 1;i <= n;++i){
			dx[i].id = dy[i].id = i;
			dx[i].val = dx[i-1].val;
			dy[i].val = dy[i-1].val;
			if(s[i-1]=='W') dx[i].val++;
			if(s[i-1]=='S') dx[i].val--;
			if(s[i-1]=='A') dy[i].val--;
			if(s[i-1]=='D') dy[i].val++;	
		}
		sort(dx,dx+n+1); 
		sort(dy,dy+n+1); 
		int lx = 0,rx = n,ly = 0,ry = n;
		while(dx[lx].val == dx[0].val) lx++;
		lx--;
		while(dx[rx].val == dx[n].val) rx--;
		rx++;
		while(dy[ly].val == dy[0].val) ly++;
		ly--;
		while(dy[ry].val == dy[n].val) ry--;
		ry++;
		int l1,r1,l2,r2;
		//for(int i = 0;i <= n;++i) cout << dx[i].val << ' ' <<dx[i].id << endl;
		//for(int i = 0;i <= n;++i) cout << dy[i].val << ' ' <<dy[i].id << endl;
		l1 = max(dx[0].id,dx[rx].id);
		r1 = min(dx[n].id,dx[lx].id);
		l2 = max(dy[0].id,dy[ry].id);
		r2 = min(dy[n].id,dy[ly].id);
		//cout << l1 << ' ' << r1 << ' '<< l2 << ' '<<r2<<endl;
		ll u = dx[n].val-dx[0].val+1,v = dy[n].val-dy[0].val+1;
		//cout << u << ' ' << v << endl;
		ans = u*v;
		if(l1 > r1&&u>2)
			ans = Min(ans,(u-1)*v); 
		if(l2 > r2&&v>2)
			ans = Min(ans,u*(v-1)); 
		cout << ans << endl;
	}
	return 0;
}