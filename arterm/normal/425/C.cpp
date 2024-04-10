#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define K 307
#define M 100100

int n,m,a[M],b[M],e,s;
vector<int> v[M];
int d[K];

void read(void){
    cin>>n>>m>>s>>e;
    for (int i=0; i<n; ++i)
        cin>>a[i];
        
    for (int j=0; j<m; ++j){
        cin>>b[j];
        v[b[j]].push_back(j);
    }
    for (int i=0; i<M; ++i)
        v[i].push_back(m+100);
}

void kill(void){
    d[0]=-1;
    for (int i=1; i<K; ++i)
    d[i]=m;
    
    int pos,ans=0;
    
    for (int i=0; i<n; ++i){
        for (int j=K-1; j>0; --j){
            pos=*lower_bound(v[a[i]].begin(),v[a[i]].end(),d[j-1]+1);
            d[j]=min(d[j],pos);
        }
        
        for (int j=0; j<K; ++j)
        if (d[j]<m && j*e+(i+1)+(d[j]+1)<=s)
        ans=max(ans,j);
    }
    
    cout<<ans<<"\n";
}

int main()
{
#ifdef TROLL
    freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
#else
    ios_base::sync_with_stdio(0);
#endif
    
    read();
    kill();
    
    return 0;
}