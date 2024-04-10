#include<bits/stdc++.h>
using namespace std;
int T,n,nxt[100100],a[100100],sz;
deque<int>q;
vector<int>v;
bool del[100100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),v.clear(),q.clear();
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),nxt[i]=i+1,q.push_back(i),del[i]=false;nxt[n]=1;
		while(!q.empty()&&v.size()<n-1){
			int x=q.front();q.pop_front();
			if(__gcd(a[x],a[nxt[x]])==1){
				v.push_back(nxt[x]),del[nxt[x]]=true;
				int tmp=nxt[x];
				nxt[x]=nxt[tmp];
				if(!q.empty()&&q.front()==tmp)q.pop_front();
				q.push_back(x);
			}
		}
		if(v.size()==n-1){for(int i=1;i<=n;i++)if(!del[i]&&a[i]==1)v.push_back(i);}
		printf("%d ",v.size());for(auto i:v)printf("%d ",i);puts("");
	}
	return 0;
}
/*
2
5
2 3 5 7 11
5
1 3 4 5 7
*/