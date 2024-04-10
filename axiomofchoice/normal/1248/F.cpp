#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define maxn 1000010
vector<int> st,a[maxn];
int vis[maxn],instack[maxn],dfn[maxn],low[maxn],ans[maxn];
int n,m,x,y,index,f,cnt;

void dfs(int x){
    if(vis[x])return;
    vis[x]=1;
    st.push_back(x);
    instack[x]=1;
    index++;
    dfn[x]=low[x]=index;
    for(int i=0;i<a[x].size();i++){
        int p=a[x][i];
        dfs(p);if(f)return;
        if(instack[p])low[x]=min(low[x],low[p]);
    }
    if(low[x]==dfn[x]){
        int t=-1;
        while(t!=x){
        	t=st.back();
            instack[t]=0;
            ans[t]=1;
            st.pop_back();//cout<<"YYYYYYYYYY"<<endl;
            cnt++;
        }
        f=true;
    }
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;cin>>T;
	while(T--){
	    cin>>n>>m;
	    
	    repeat(i,0,n){
	    	a[i].clear();
	    	vis[i]=instack[i]=dfn[i]=low[i]=ans[i]=0;
	    }
	    index=f=cnt=0;st.clear();
	    
	    repeat(i,0,m){
	        cin>>x>>y;x--,y--;
	        if(x!=y)a[x].push_back(y);
	    }
	    
		dfs(0);
		
	    if(f && cnt!=n){
	    	cout<<"Yes"<<endl;
	    	cout<<cnt<<' '<<n-cnt<<endl;
	    	repeat(i,0,n)
	    		if(ans[i])cout<<i+1<<' ';
	    	cout<<endl;
	    	repeat(i,0,n)
	    		if(!ans[i])cout<<i+1<<' ';
	    	cout<<endl;
	    }
	    else{
	    	cout<<"No"<<endl;
	    }
	}
	return 0;
}