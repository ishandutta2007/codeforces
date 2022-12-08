#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;

int n,a[N],b[N];
int f[N],last[N];

struct ST{
    int tot;
    int ls[N<<1],rs[N<<1];
    int mn[N<<1],pp[N<<1];

    void up(int x){
        mn[x]=min(mn[ls[x]],mn[rs[x]]);
        if(mn[ls[x]]<mn[rs[x]]){
        	pp[x]=pp[ls[x]];
		}
		else{
			pp[x]=pp[rs[x]];
		}
    }

    int build(int l,int r){
        int x=++tot;
        if(l==r){
        	mn[x]=2e9;
        	pp[x]=l;
            return x;
        }
        int mid=l+r>>1;
        ls[x]=build(l,mid);
        rs[x]=build(mid+1,r);
        up(x);
        return x;
    }

    void change(int x,int l,int r,int p){
        if(l==r){
        	mn[x]=f[l];
            return;
        }
        int mid=l+r>>1;
        if(p<=mid)change(ls[x],l,mid,p);
        else change(rs[x],mid+1,r,p);
        up(x);
    }

    pair<int,int> getmn(int x,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            return {mn[x],pp[x]};
        }
        int mid=l+r>>1;
        pair<int,int> ret={2e9,-1};
        if(L<=mid)ret=min(ret,getmn(ls[x],l,mid,L,R));
        if(R>mid)ret=min(ret,getmn(rs[x],mid+1,r,L,R));
        up(x);
        return ret;
    }
}T;

int main(){
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	T.mn[0]=2e9;
	int rt=T.build(0,n);
	f[0]=0;
	T.change(1,0,n,0);
	for(int i=1;i<=n;++i){
		int x=i;
		if(i!=n)x+=b[x];
		x=min(x,n);
		int r=x,l=x-a[x];
		l=max(l,0);
		r=min(r,i-1);
		if(l<=r){
			pair<int,int> t=T.getmn(1,0,n,l,r);
			f[i]=t.first+1;
			last[i]=t.second;
		}
		else{
			f[i]=2e9;
			last[i]=-1;
		}
		T.change(1,0,n,i);
	}
	if(f[n]>1e9){
		cout<<-1<<endl;
	}
	else{
		cout<<f[n]<<endl;
		while(n){
			cout<<last[n]<<" ";
			n=last[n];
		}
		cout<<endl;
	}
}