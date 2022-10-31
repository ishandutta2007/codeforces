#include<bits/stdc++.h>
using namespace std;
#define N 200100
char s[N];
int f[N],nxt[N],head[N],ed[N],len[N];
//a and b means "gap right after i-th character"
int find(int x){
	if(head[x]==x) return x;
	return head[x]=find(head[x]);
}
void link(int a,int b){
	nxt[a]=b+1;
	head[b+1]=a;
}
int sum(int x){
	int r=0;
	while(x){
		r+=f[x];
		x-=x&-x;
	}
	return r;
}
void del(int x){
	while(x<N){
		f[x]--;
		x+=x&-x;
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		vector<int> v;
		for(int i=1;i<=n;i++){
			head[i]=i;
			f[i]=i&-i;
			nxt[i]=0;
		}
		int c[26]={};
		for(int i=1;i<n;i++){
			if(s[i]!=s[i+1]){
				link(i,i);
			}
			else{
				v.push_back(i);
				c[s[i]-'a']++;
			}
		}
		int half=v.size()/2;
		char mx=-1;
		vector<int> stk;
		for(auto x:v){
			if(mx<0){
				for(int i=0;i<26;i++){
					if(c[i]>=half){
						mx='a'+i;
						break;
					}
				}
			}
			if(!stk.empty() && s[stk.back()]!=s[x] && (mx<0 || s[stk.back()]==mx || s[x]==mx)){
				link(stk.back(),x);
				c[s[stk.back()]-'a']--;
				c[s[x]-'a']--;
				stk.pop_back();
				half--;
			}
			else{
				stk.push_back(x);
			}
		}
		set<int> alive;
		int op=0;
		priority_queue<int> q;
		for(int i=1;i<=n;i++){
			alive.insert(i);
			if(head[i]==i){
				op++;
				len[i]=1;
				ed[i]=i;
				for(int j=i;nxt[j];j=nxt[j]){
					ed[i]=nxt[j];
					len[i]++;
				}
				if(ed[i]-i+1==len[i]) q.push(i);
			}
		}
		printf("%d\n",op);
		for(int i=0;i<op;i++){
			int h=q.top();
			q.pop();
			printf("%d %d\n",sum(h),sum(ed[h]));
			for(int j=h;j>0;j=nxt[j]){
				alive.erase(j);
				del(j);
			}
			auto it=alive.upper_bound(ed[h]);
			if(it!=alive.end()){
				int ph=find(*it);
				if(ph<h){
					len[ph]+=ed[h]-h+1;
					if(len[ph]==ed[ph]-ph+1) q.push(ph);
				}
			}
		}
	}
	return 0;
}