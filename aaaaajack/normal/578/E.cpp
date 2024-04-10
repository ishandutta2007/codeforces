#include<cstdio>
#include<vector>
#include<cstring>
#define N 100100
using namespace std;
vector<int> ll,lr,rl,rr;
char s[N];
int nxt[N],h[N],t[N];
inline void print(int st){
	for(int i=st;i!=-1;i=nxt[i]) printf("%d ",i+1);
}
int main(){
	int lc=0,rc=0;
	scanf("%s",s);
	for(int i=0;s[i];i++){
		if(s[i]=='L'){
			lc++;
			if(!lr.empty()){
				int u=lr.back();
				nxt[t[u]]=i;
				t[u]=i;
				lr.pop_back();
				ll.push_back(u);
			}
			else if(!rr.empty()){
				int u=rr.back();
				nxt[t[u]]=i;
				t[u]=i;
				rr.pop_back();
				rl.push_back(u);
			}
			else t[i]=i,ll.push_back(i);
		}
		else{
			rc++;
			if(!rl.empty()){
				int u=rl.back();
				nxt[t[u]]=i;
				t[u]=i;
				rl.pop_back();
				rr.push_back(u);
			}
			else if(!ll.empty()){
				int u=ll.back();
				nxt[t[u]]=i;
				t[u]=i;
				ll.pop_back();
				lr.push_back(u);
			}
			else t[i]=i,rr.push_back(i);
		}
		nxt[i]=-1;
	}
	printf("%d\n",(int)(ll.size()+rr.size()+lr.size()+rl.size()-1));
	if(lc>rc){
		for(int i=0;i<lr.size();i++) print(lr[i]);
		for(int i=0;i<ll.size()-1;i++) print(ll[i]),print(rr[i]);
		print(ll.back());
		for(int i=0;i<rl.size();i++) print(rl[i]);
	}
	else if(rc>lc){
		for(int i=0;i<rl.size();i++) print(rl[i]);
		for(int i=0;i<rr.size()-1;i++) print(rr[i]),print(ll[i]);
		print(rr.back());
		for(int i=0;i<lr.size();i++) print(lr[i]);
	}
	else{
		if(ll.empty()){
			for(int i=0;i<rl.size();i++) print(rl[i]);
			for(int i=0;i<lr.size();i++) print(lr[i]);
		}
		else{
			for(int i=0;i<rl.size();i++) print(rl[i]);
			for(int i=0;i<rr.size()-1;i++) print(rr[i]),print(ll[i]);
			print(rr.back());
			for(int i=0;i<lr.size();i++) print(lr[i]);
			print(ll.back());
		}
	}
	return 0;
}