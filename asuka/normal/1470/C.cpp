#include<bits/stdc++.h>
#define ll long long
#define N 105
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
using namespace std;
int n,k,B;
int query(int x){
	printf("? %d\n",x);
	fflush(stdout);
	int y; scanf("%d",&y);
	return y;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&k);
	while(B*B <= n) B++; B++;
	if(n <= 100) B = 1;
	rep(_,1,B) query(1);
	int pos = n;
	for(int i = 1;i <= n;i += B){
		if(query(i) > k){
			pos = i;
			 break;
		}
	}
	while(query(pos) > k){
		pos--; if(pos == 0) pos = n;
	}
	printf("! %d\n",pos);
	fflush(stdout);
	return 0;
}