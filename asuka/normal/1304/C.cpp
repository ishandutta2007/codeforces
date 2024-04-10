#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<queue>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#define ll long long
#define N 205
using namespace std;
int t,n,m;
struct node{
	int t,l,r;
}c[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i = 1;i <= n;++i)
			cin>>c[i].t>>c[i].l>>c[i].r;
		c[0].t = 0;
		int l,r;
		bool flag = 0;
		l = r = m;
		for(int i = 1;i <= n;++i){
			int d = (c[i].t-c[i-1].t);
			l-=d; r+=d;
			l = max(c[i].l,l);
			r = min(c[i].r,r);
			//cout << l << ' ' << r << endl;
			if(l>r){
				flag = 1;
				break;
			}
		}
		if(flag) puts("NO");
		else puts("YES");
	}
    return 0;
}