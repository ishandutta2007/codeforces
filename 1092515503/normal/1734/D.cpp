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
int n,m,a[200100];
vector<pair<ll,ll> >u,v;
void mina(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	u.clear(),v.clear();
	for(int l=m-1,r=m-1;r;r=l){
		ll sum=a[r],mn=sum;
		for(l=r-1;l&&sum<0;l--)mn=min(mn,sum+=a[l]);
		// printf("<%lld,%lld>\n",mn,sum);
		u.emplace_back(mn,sum);
	}
	for(int l=m+1,r=m+1;l<=n;l=r){
		ll sum=a[l],mn=sum;
		for(r=l+1;r<=n&&sum<0;r++)mn=min(mn,sum+=a[r]);
		// printf("[%lld,%lld]\n",mn,sum);
		v.emplace_back(mn,sum);
	}
	ll sum=a[m];
	for(int i=0,j=0;;){
		if(i==u.size()||j==v.size()){puts("YES");return;}
		if(sum+u[i].first>=0){sum+=u[i++].second;continue;}
		if(sum+v[j].first>=0){sum+=v[j++].second;continue;}
		puts("NO");return;
	}
}
int T;
int main(){scanf("%d",&T);while(T--)mina();return 0;}
/*
1
7 4
-1 -2 -4 6 -2 -4 -1
*/