#include<bits/stdc++.h>
#define ll long long
#define N 200015
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
int t,stk[N],n,head;
char s[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		head = 0;
 		scanf("%s",s+1);
 		n = strlen(s+1);
 		rep(i,1,n) stk[i] = 0;
 		rep(i,1,n){
 			if(s[i] == 'A'){
 				stk[++head] = 1;
 			}else{
 				if(head == 0) stk[++head] = -1;
 				else{
 					head--;
 				}
 			}
 		}
 		printf("%d\n",head);
 	}
	return 0;
}