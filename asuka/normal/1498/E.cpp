#include<bits/stdc++.h>
#define ll long long
#define N 505
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
char s[44];
bool query(int a,int b){
	printf("? %d %d\n",a,b);
	fflush(stdout);
	scanf("%s",s+1);
	if(s[1] == 'Y'){
		return 1;
	}
	return 0;
}
struct node{
	int a,b,val;
};
vector<node> V;
bool cmp(node u,node v){
	return u.val > v.val;
}
int n,k[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&k[i]);
	rep(i,1,n) rep(j,i+1,n){
		if(k[i]> k[j]) V.pb((node){i,j,abs(k[i]-k[j])});
		else V.pb((node){j,i,abs(k[i]-k[j])});
	}
	sort(all(V),cmp);
	for(node u:V){
		if(query(u.a,u.b)){
			printf("! %d %d\n",u.a,u.b);
			fflush(stdout);
			return 0;
		}
	}
	printf("! 0 0\n");
	fflush(stdout);
	return 0;
}