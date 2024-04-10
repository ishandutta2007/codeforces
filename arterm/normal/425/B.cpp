#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define M 110
#define N 23

int n,k,m,p[M],a[M][M];

void pre(void){
    p[0]=1;
    for (int i=1; i<N; ++i)
    p[i]=2*p[i-1];
}

int sum(int mask){
    int s=0;
    for (int i=0; i<n; ++i){
        int k=0;
        for (int j=0; j<m; ++j)
        if (mask&p[j])
        k+=1-a[i][j];
        else
        k+=a[i][j];
        
        s+=min(k,m-k);
    }
    return s;
}

void read(void){
    cin>>n>>m>>k;
    for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j)
        cin>>a[i][j];
}

void kill(void){
    int ans=k+1;
    if (m<=k){
        for (int s=0; s<p[m]; ++s)
            ans=min(ans,sum(s));
        
        
        if (ans<=k)
        cout<<ans<<"\n";
        else
        cout<<"-1\n";
        return;
    }
    
    
    for (int x=0; x<m; ++x){
        int s=0;
        for (int j=0; j<m; ++j){
            int k=0;
            for (int i=0; i<n; ++i)
            if (a[i][x])
            k+=1-a[i][j];
            else
            k+=a[i][j];
            s+=min(k,n-k);
        }
        ans=min(ans,s);
    }
    
    if (ans<=k)
    cout<<ans<<"\n";
    else
    cout<<"-1\n";
    
}


int main()
{
#ifdef TROLL
    freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
#else
    ios_base::sync_with_stdio(0);
#endif
    
    pre();
    read();
    kill();
    
    return 0;
}