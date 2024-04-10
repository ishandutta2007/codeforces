#include<bits/stdc++.h>
#define int long long
const int N=2002;
using namespace std;
struct edge{
    int from,to,len;
    const bool operator < (edge b) const{
        return this->len>b.len;
    }
};
priority_queue <edge> que;
int n,a[N][N],w[N],fa[N],ans,x[N],y[N],k[N];
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
vector <edge> as;
int mst()
{
    while(!que.empty()){
        edge p=que.top();
        if(find(p.from)!=find(p.to))
        {
            fa[fa[p.to]]=fa[p.from];
            ans+=p.len;
            as.push_back(p);
        }
        que.pop();
    }
    return ans;
}
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++)
    	cin>>w[i];
    for(int i=1;i<=n;i++)
    	cin>>k[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
			if(i!=j)que.push((edge){i,j,abs((k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])))});
    n++;
    for(int i=1;i<n;i++){
        que.push((edge){i,n,w[i]});
        que.push((edge){n,i,w[i]});
    }
    for(int i=1;i<=n;i++)fa[i]=i;
	cout<<mst()<<endl;
    int a=0,b=0;
    for(int i=0;i<n-1;i++){
    	edge p=as[i];
    	if(p.from==n||p.to==n)a++;
    	else b++;
	}
	cout<<a<<endl;
	for(int i=0;i<n-1;i++){
		edge p=as[i];
		if(p.from==n)cout<<p.to<<" ";
		else if(p.to==n)cout<<p.from<<" ";
	}
	cout<<endl<<b<<endl;
	for(int i=0;i<n-1;i++){
		edge p=as[i];
		if(p.from!=n&&p.to!=n)
			cout<<p.from<<" "<<p.to<<endl;
	}
    return 0;
}