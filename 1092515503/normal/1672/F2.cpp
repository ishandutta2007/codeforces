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
int T,a[200100],b[200100],n,c[200100],mxc,in[200100];
vector<int>v[200100];
queue<int>q;
void mina(){
	scanf("%d",&n),mxc=0;
	for(int i=1;i<=n;i++)v[i].clear(),c[i]=in[i]=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),c[a[i]]++;
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)if(c[i]>c[mxc])mxc=i;
	for(int i=1;i<=n;i++)if(a[i]!=mxc&&b[i]!=mxc)v[a[i]].push_back(b[i]),in[b[i]]++;
	for(int i=1;i<=n;i++)if(!in[i])q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(auto y:v[x])if(!--in[y])q.push(y);
	}
	bool ok=true;
	for(int i=1;i<=n;i++)ok&=!in[i];
	puts(ok?"AC":"WA");
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}