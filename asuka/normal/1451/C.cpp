#include<bits/stdc++.h>
#define ll long long
#define N 1000015
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
using namespace std;
int t,n,k,ca[N],cb[N];
char a[N],b[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d%d",&n,&k);
 		scanf("%s%s",a+1,b+1);
 		rep(i,0,25) ca[i] = cb[i] = 0;
 		rep(i,1,n) ca[a[i]-'a']++,cb[b[i]-'a']++;
 	//	rep(i,0,25) cout << ca[i] << ' ';
 		rep(i,0,24){
 			if(ca[i] > cb[i]){
 				int d = ca[i]-cb[i];
 				int cc = d/k,val = cc*k;
 				ca[i] -= val; ca[i+1] += val;
 			}
 		}
 		int ff = 1;
 		rep(i,0,25){
 			if(ca[i] != cb[i]){ff = 0; break;}
 		}
 		if(ff) puts("Yes");
 		else puts("No");
 	}
	return 0;
}