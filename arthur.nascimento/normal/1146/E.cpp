#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define debug 
#define maxn 400400

int v[maxn];

char type[maxn];
int num[maxn];


int ans[maxn];

int T[2][maxn];

int sum(int id,int idx){
	int r = 0;
	idx += 200200;
	while(idx){
		r += T[id][idx];
		idx -= idx&-idx;
	}
	return r;
}

void upd(int id,int idx,int val){
	idx += 200200;
	while(idx < maxn){
		T[id][idx] += val;
		idx += idx&-idx;
	}
}

int main(){
	
	int n,q;
	set<pii> S;
	scanf("%d%d",&n,&q);
	
	for(int i=0;i<n;i++){
		scanf("%d",v+i);
		ans[i] = v[i];
		S.insert(pii(abs(v[i]),i));
	}
	
	for(int i=0;i<q;i++){
		scanf(" %c%d",type+i,num+i);
		if(type[i] == '>') num[i]++;
		else num[i]--;
	}
	
	for(int i=q-1;i>=0;i--){
	
		debug("i %d\n",i);
		
		int upto = abs(num[i]);
		
		if(num[i] > 0 && type[i] == '<') upto++;
		if(num[i] < 0 && type[i] == '>') upto++;
		
		while(S.size() > 0  && (--S.end()) -> first >= upto){
		
			pii u = *--S.end();
			if(u.first == 0) break;
			S.erase(u);
			
			int id = u.second;
			
			int val = abs(v[id]);
			
			debug("go %d (id %d)\n",val,id);
			
			if(type[i] == '>')
				val = -val;
				
			int ch = sum(0,-abs(val));
			ch += sum(1,200020) - sum(1,abs(val)-1);
			
			if(ch&1) val = -val;
			
			ans[id] = val;
			
		}
		
		if(type[i] == '>')
			upd(0,num[i],1);
		else
			upd(1,num[i],1);
		
	}
	
	while(S.size()){
		pii u = *--S.end();
		S.erase(u);
		int id = u.second;
		int val = v[id];
		int ch = sum(0,-abs(val)) + sum(1,200020) - sum(1,abs(val)-1);
		if(ch&1) val = -val;
		ans[id] = val;
	}
	
	for(int i=0;i<n;i++)
		printf("%d\n",ans[i]);
}