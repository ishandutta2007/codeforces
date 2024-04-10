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
using namespace std;
int n;
char l[N],r[N];
bool check(){
	rep(i,1,n) if(l[i] != r[i]) return 0;
	return 1;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	scanf("%s%s",l+1,r+1);
	if(l[1] != r[1]){
		rep(i,1,n) putchar('1');
		return 0;
	}
	if(check()){
		printf("%s",l+1);
		return 0;
	}
	l[n]++;
	per(i,1,n) if(l[i] == '2') l[i] = '0',l[i-1]++;
	if(check()){
		printf("%s",l+1);
		return 0;
	}
	r[n] = '1';
	printf("%s",r+1);
	return 0;
}