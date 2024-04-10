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
#define N 15001000
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,q,rt,seg[N],li[N],ri[N],lazy[N],tot;
inline void up(int root){seg[root] = seg[li[root]]+seg[ri[root]];}
inline void down(int root,int L,int R){
	if(~lazy[root]){
		int mid = L+R>>1;
		if(!li[root]) li[root] = ++tot;
		seg[li[root]] = lazy[root]*(mid-L+1); lazy[li[root]] = lazy[root];
		if(!ri[root]) ri[root] = ++tot;
		seg[ri[root]] = lazy[root]*(R-mid); lazy[ri[root]] = lazy[root];
		lazy[root] = -1;
	}
}
inline void change(int &root,int L,int R,int l,int r,int val){
	if(!root) root = ++tot;
	if(l <= L&&R <= r){
		seg[root] = (R-L+1)*val;
		lazy[root] = val;
		return;
	}
	down(root,L,R);
	int mid = L+R>>1;
	if(l <= mid) change(li[root],L,mid,l,r,val);
	if(mid+1 <= r) change(ri[root],mid+1,R,l,r,val);
	up(root);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&q);
	memset(lazy,-1,sizeof lazy);
	change(rt,1,n,1,n,0);
	while(q--){
		int l,r,val;
		scanf("%d%d%d",&l,&r,&val);
		change(rt,1,n,l,r,2-val);
		printf("%d\n",n-seg[1]);
	}
	return 0;
}