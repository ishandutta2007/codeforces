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
int a,b,c;
int get(int x){
	int cnt = 0;
	while(x>0) x/=10,cnt++;
	return cnt;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	int T;
 	scanf("%d",&T);
 	while(T--){
 		scanf("%d%d%d",&a,&b,&c);
 		int A,B,C; C = 1;
 		while(get(C) < c) C *= 10;
 		A = B = C;
 		while(get(A) < a) A *= 9;
 		while(get(B) < b) B *= 7;
 		printf("%d %d\n",A,B);
 	}
	return 0;
}