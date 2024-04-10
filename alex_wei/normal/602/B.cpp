#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
const int inf=1e9+7;
int n,a[N],ans,pos=1;
struct Treap{
	int son[N][2],cnt[N],siz[N],rd[N],val[N],R,num;
	void push(int x){siz[x]=cnt[x]+siz[son[x][0]]+siz[son[x][1]];}
	void rotate(int &x,int d){
		int k=son[x][d^1];
		son[x][d^1]=son[k][d];
		son[k][d]=x;
		push(x); push(k);
		x=k;
	}
	void ins(int &x,int v){
		if(!x){
			x=++num;
			siz[num]=cnt[num]=1;
			rd[num]=rand();
			val[num]=v;
		}
		else if(val[x]==v)siz[x]++,cnt[x]++;
		else{
			int d=v>val[x];
			ins(son[x][d],v);
			if(rd[x]<rd[son[x][d]])rotate(x,d^1);
			push(x);
		}
	}
	void del(int &x,int v){
		if(!x)return;
		if(v>val[x])del(son[x][1],v);
		else if(v<val[x])del(son[x][0],v);
		else if(!son[x][0]&&!son[x][1]){
			siz[x]--,cnt[x]--;
			if(siz[x]==0)x=0;
		}
		else if(son[x][0]&&!son[x][1]){
			rotate(x,1); del(son[x][1],v);
		}
		else if(son[x][1]&&!son[x][0]){
			rotate(x,0); del(son[x][0],v);
		}
		else{
			int d=rd[son[x][0]]>rd[son[x][1]];
			rotate(x,d);
			del(son[x][d],v);
		}
		push(x);
	}
	int pre(int x,int v){
		if(!x)return -inf;
		if(v<=val[x])return pre(son[x][0],v);
		else return max(val[x],pre(son[x][1],v));
	}
	int suf(int x,int v){
		if(!x)return inf;
		if(v>=val[x])return suf(son[x][1],v);
		else return min(val[x],suf(son[x][0],v));
	}
	int getdif(){
		return pre(R,inf)-suf(R,-inf);
	}
}tr;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		tr.ins(tr.R,a[i]);
		while(tr.getdif()>1)tr.del(tr.R,a[pos++]);
		ans=max(ans,i-pos+1);
	}
	cout<<ans<<endl;
    return 0;
}