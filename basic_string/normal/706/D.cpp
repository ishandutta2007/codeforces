#include<bits/stdc++.h>
using namespace std;
int id=1;
struct T{
	int c[2],s,d,e;
}t[400009];
void add(int v){
	int x=1,y,l,b,o,e;
	for(;++t[x].s,t[x].d;x=t[x].c[b],v-=t[x].e)
		if(!(y=t[x].c[b=v>>t[x].d-1&1]))t[x].c[b]=++id,t[id].e=v;
		else if((e=t[y].e)!=v-(v&(1<<t[y].d)-1)){
			o=v>e,t[l=++id].s=t[y].s,t[l].d=__lg(v^e)+1;
			t[l].c[o]=++id,t[id].e=v&(1<<t[l].d)-1;
			t[l].c[!o]=y,t[y].e=e&(1<<t[l].d)-1;
			t[x].c[b]=l,t[l].e=e-t[y].e;
		}
}
void del(int v){for(int x=1;--t[x].s,t[x].d;x=t[x].c[v>>t[x].d-1&1]);}
void qry(int v){
	int x=1,w=v,b;
	for(;t[x].d;w^=t[x].e)if(t[t[x].c[!(b=v>>t[x].d-1&1)]].s)x=t[x].c[!b];else x=t[x].c[b];
	cout<<w<<'\n';
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int q,x;
	char c;
	t[1].d=30,cin>>q,add(0);
	for(;q--;)if(cin>>c>>x,c=='+')add(x);else if(c=='-')del(x);else qry(x);
	return 0;
}