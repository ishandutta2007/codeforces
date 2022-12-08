#include <bits/stdc++.h>

using namespace std;

#define N 201010
#define ALF 30

typedef long long ll;

struct state{
	
	int nxt[ALF], link, len, cnt, grau;
	
	state(){
		memset(nxt, 0, sizeof nxt);
		link=-1;
		len=cnt=grau=0;
	}
}st[N<<1];


int n, cont, last;
char s[N], forbid[N];

void add(char letra,int i){
	
	int c = letra-'a';
	int p, q, clone, novo = cont++;
	
	for(p = last; p>=0 && !st[p].nxt[c]; p = st[p].link) st[p].nxt[c] = novo;
	
	if(p==-1){
		st[novo].link = 0;
	}else{
		
		q = st[p].nxt[c];
		
		if(st[q].len == st[p].len+1){
			st[novo].link = q;
		}else{
			
			
			clone = cont++;
			
			st[clone] = st[q];
			
			st[q].link = st[novo].link = clone;
			st[clone].len = st[p].len+1;
			st[clone].cnt = 0;
			for(; p>=0; p = st[p].link){
				if(st[p].nxt[c]) st[p].nxt[c] = clone;
			}
		}
	}
	
	st[novo].cnt = !(forbid[i]-'0');
	st[novo].len = st[last].len+1;
	last = novo;
}


ll build(){
	cont=1;
	last=0;
	
	for(int i=0; i<n; i++){
		add(s[i], i);
	}
	
	queue<int> q;
	for(int i=1; i<cont; i++){
		st[st[i].link].grau++;
	}
	
	for(int i=1; i<cont; i++){
		if(!st[i].grau) q.push(i);
	}
	
	ll answer = 0;
	while(q.size()){
		int u = q.front(); q.pop();
		if(!u) break;
		
		int pai = st[u].link;
		st[pai].cnt+=st[u].cnt;
		answer = max(answer, (ll)st[u].cnt*(ll)st[u].len);
		if(!(--st[pai].grau)) q.push(pai);
	}
	return answer;
}

int main(){
	cin>>n;
	cin>>s;
	cin>>forbid;
	cout<<build()<<endl;
}