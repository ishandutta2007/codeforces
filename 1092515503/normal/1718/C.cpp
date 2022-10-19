/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,a[200100];
int b[200100],m;
vector<ll>u[200100];
multiset<ll>s[200100];
ll query(){
	ll mx=0;
	for(int i=1;i<=m;i++)mx=max(mx,b[i]**s[i].rbegin());
	return mx;
}
void mina(){
	scanf("%d%d",&n,&q),m=0;
	for(int i=2,x=n;i<=n;i++)if(!(x%i)){
		b[++m]=n/i,u[m].resize(n/i);
		while(!(x%i))x/=i;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		for(int j=1;j<=m;j++)u[j][i%b[j]]+=a[i];
	}
	for(int i=1;i<=m;i++)for(int j=0;j<b[i];j++)s[i].insert(u[i][j]);
	printf("%lld\n",query());
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y),x--;
		for(int j=1;j<=m;j++)s[j].erase(s[j].find(u[j][x%b[j]])),u[j][x%b[j]]-=a[x];
		a[x]=y;
		for(int j=1;j<=m;j++)u[j][x%b[j]]+=a[x],s[j].insert(u[j][x%b[j]]);
		printf("%lld\n",query());
	}
	for(int i=1;i<=m;i++)u[i].clear(),s[i].clear();
}
int T;
int main(){scanf("%d",&T);while(T--)mina();return 0;}
/*
1
6 3
1 1 1 1 1 1
1 5
4 4
3 8
*/