#include<bits/stdc++.h>
using namespace std;
int n,m,BBB,cnt[410][100100];
deque<int>q[410];
int main(){
	scanf("%d",&n),BBB=sqrt(n);
	for(int i=0,x;i<n;i++)scanf("%d",&x),q[i/BBB].push_back(x),cnt[i/BBB][x]++;
	scanf("%d",&m);
	for(int tt=1,t1,t2,t3,t4,la=0;tt<=m;tt++){
		scanf("%d%d%d",&t1,&t2,&t3),t2=(t2+la-1)%n,t3=(t3+la-1)%n;
		if(t2>t3)swap(t2,t3);
		if(t1==1){
			if(t2/BBB==t3/BBB){
				int x=q[t2/BBB][t3%BBB];
				q[t2/BBB].erase(q[t2/BBB].begin()+t3%BBB);
				q[t2/BBB].insert(q[t2/BBB].begin()+t2%BBB,x);
			}else{
				for(int i=t2/BBB;i<t3/BBB;i++){
					int x=q[i].back();q[i].pop_back();cnt[i][x]--;
					q[i+1].push_front(x),cnt[i+1][x]++;
				}
				int x=q[t3/BBB][t3%BBB+1];cnt[t3/BBB][x]--;q[t3/BBB].erase(q[t3/BBB].begin()+t3%BBB+1);
				cnt[t2/BBB][x]++,q[t2/BBB].insert(q[t2/BBB].begin()+t2%BBB,x);
			}
		}else{
			scanf("%d",&t4),t4=(t4+la-1)%n+1;
//			printf("%d %d %d\n",t2,t3,t4);
			la=0;
			if(t2/BBB==t3/BBB)for(int i=t2%BBB;i<=t3%BBB;i++)la+=(q[t2/BBB][i]==t4);
			else{
				for(int i=t2%BBB;i<q[t2/BBB].size();i++)la+=(q[t2/BBB][i]==t4);
				for(int i=0;i<=t3%BBB;i++)la+=(q[t3/BBB][i]==t4);
				for(int i=t2/BBB+1;i<=t3/BBB-1;i++)la+=cnt[i][t4];
			}
			printf("%d\n",la);
		}
//		for(int i=0;i<n;i++)printf("%d ",q[i/BBB][i%BBB]);puts("");
	}
	return 0;
}