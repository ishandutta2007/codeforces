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
const int mod=998244353;
int T,n,m;
int a[1010],res;
long long A[1010],B[1010];
vector<int>v[1010];
int in[1010];
queue<int>q;
void mina(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&A[i]),v[i].clear(),in[i]=0;
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),v[x].push_back(y),in[y]++;
	for(res=0;res<n;res++){
		if(!*max_element(A+1,A+n+1)){printf("%d\n",(int)(res%mod));return;}
		for(int i=1;i<=n;i++)B[i]=A[i];
		for(int i=1;i<=n;i++)if(A[i]){B[i]--;for(auto j:v[i])B[j]++;}
		for(int i=1;i<=n;i++)A[i]=B[i];
	}
	for(int i=1;i<=n;i++)a[i]=A[i]%mod;
	for(int i=1;i<=n;i++)if(!in[i])q.push(i);
	// for(int i=1;i<=n;i++)printf("%lld ",a[i]);puts("");
	int x;
	while(!q.empty()){
		x=q.front();q.pop();
		for(auto y:v[x]){
			(a[y]+=a[x])%=mod;
			if(!--in[y])q.push(y);
		}
	}
	printf("%d\n",(res+a[x])%mod);
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}
/*
1
6 15
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
1 2
1 3
1 4
1 5
1 6
2 3
2 4
2 5
2 6
3 4
3 5
3 6
4 5
4 6
5 6
*/