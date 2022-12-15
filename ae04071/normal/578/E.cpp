#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstring>
#include <vector>
#include <set>

using namespace std;
char str[100100];
int n,nxt[100100],lst[100100],vis[100001],st[100001];

set<int> Lt,Rt;
int main() {
	scanf("%s",str);
	n=strlen(str);
	
	memset(nxt,-1,sizeof(nxt));

	for(int i=0;i<n;i++) st[i] = lst[i] = i;
	
	for(int i=0;i<n;i++) {
		if(str[i]=='R') Rt.insert(i);
		else Lt.insert(i);
	}

	int ans=n-1;
	for(int i=0;i<n;i++) {
		if(str[i]=='R') {
			auto it=Lt.lower_bound(i);
			if(it!=Lt.end()) {
				nxt[i] = *it;
				lst[st[i]] = lst[*it];
				st[*it] = st[i];
				vis[*it]=1;
				Lt.erase(it);
				ans--;
			}
		} else {
			auto it=Rt.lower_bound(i);
			if(it!=Rt.end()) {
				nxt[i] = *it;
				lst[st[i]] = lst[*it];
				st[*it] = st[i];
				vis[*it]=1;
				Rt.erase(it);
				ans--;
			}
		}
	}
	
	//for(int i=0;i<n;i++) printf("(%d %d)\n",nxt[i],lst[i]);

	vector<int> LL,LR,RL,RR;
	for(auto &it:Lt) {
		if(vis[it]) continue;
		if(str[lst[it]]=='R') LR.push_back(it);
		else LL.push_back(it);
	}
	for(auto &it:Rt) {
		if(vis[it]) continue;
		if(str[lst[it]]=='L') RL.push_back(it);
		else RR.push_back(it);
	}
	
	for(int i=1;i<(int)LR.size();i++) {
		nxt[lst[LR[0]]] = LR[i];
		lst[LR[0]] = lst[LR[i]];
	}
	for(int i=1;i<(int)RL.size();i++) {
		nxt[lst[RL[0]]] = RL[i];
		lst[RL[0]] = lst[RL[i]];
	}
	if(!LL.empty()) {
		if(!LR.empty()) {
			nxt[lst[LR[0]]] = LL[0];
			lst[LR[0]] = lst[LL[0]];
			LL[0] = LR[0];
		}
		if(!RL.empty()) {
			nxt[lst[LL[0]]] = RL[0];
			lst[LL[0]] = lst[RL[0]];
		}
	} else if(!RR.empty()) {
		if(!LR.empty()) {
			nxt[lst[RR[0]]] = LR[0];
			lst[RR[0]] = lst[LR[0]];
		}
		if(!RL.empty()) {
			nxt[lst[RL[0]]] = RR[0];
			lst[RL[0]] = lst[RR[0]];
			RR[0] = RL[0];
		}
	}
	
	int s=0;
	if(LL.empty() && RR.empty()) {
		if(!LR.empty()) s=LR[0];
		else s=RL[0];
	} else {
		if(LL.size() >= RR.size()) {
			int i=0;
			for(;i<(int)RR.size();i++) {
				nxt[lst[LL[i]]] = RR[i];
				lst[LL[i]] = lst[RR[i]];
			}
			for(i=1;i<(int)LL.size();i++) {
				nxt[lst[LL[0]]] = LL[i];
				lst[LL[0]] = lst[LL[i]];
			}
			s=LL[0];
		} else {
			for(int i=0;i<(int)LL.size();i++) {
				nxt[lst[RR[i]]] = LL[i];
				lst[RR[i]] = lst[LL[i]];
			}
			for(int i=1;i<(int)RR.size();i++) {
				nxt[lst[RR[0]]] = RR[i];
				lst[RR[0]] = lst[RR[i]];
			}
			s=RR[0];
		}
	}

	printf("%d\n",ans);
	for(int i=0;i<n;i++) printf("%d ",s+1),s=nxt[s];
	
	return 0;
}