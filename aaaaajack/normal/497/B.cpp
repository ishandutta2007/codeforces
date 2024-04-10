#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#define N 100100
using namespace std;
vector<pair<int,int> > ans,ans2;
int s1[N],s2[N];
int main(){
	int n,x,i,j,k,t1,t2,p1,p2,r1,r2;
	int last;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		if(x==1){
			s1[i]=i?s1[i-1]+1:1;
			s2[i]=i?s2[i-1]:0;
		}
		else{
			s1[i]=i?s1[i-1]:0;
			s2[i]=i?s2[i-1]+1:1;
		}
	}
	for(i=1;i<=n;i++){
		t1=0,t2=0;
		r1=0,r2=0;
		while(t1+t2<n){
			p1=lower_bound(s1,s1+n,t1+i)-s1;
			p2=lower_bound(s2,s2+n,t2+i)-s2;
			if(p1==n&&p2==n) break;
			t1=s1[min(p1,p2)];
			t2=s2[min(p1,p2)];	
			if(p1<p2) r1++,last=1;
			else r2++,last=2;
		}
		if(t1+t2==n){
			if(r1==r2) continue;
			else if(r1>r2&&last==2) continue;
			else if(r1<r2&&last==1) continue;
			ans.push_back(make_pair(max(r1,r2),i));
		}
	}
	printf("%d\n",ans.size());
	sort(ans.begin(),ans.end());
	for(i=0;i<ans.size();i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;	
}