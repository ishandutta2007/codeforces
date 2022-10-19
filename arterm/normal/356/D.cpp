#include <iostream>
#include <string>
#include <algorithm>

#define M 70700


using namespace std;

int n,s,l[M],c[M],g[M];
pair<int,int> p[M];
bool u[M];

bool din(int k){
    for (int i=1; i<=k; ++i)
        l[i]=-1;
    l[0]=0;
    int sum=0;
    for (int j=0; j+1<n && l[k]==-1; ++j){
        int to=p[j].first;
        sum+=to;
        if (sum>=k)
            sum=k;
        for (int i=sum; i>=to; --i)
            if (l[i]==-1 && l[i-to]>=0)
                l[i]=j;
    }
    return l[k]>=0;
}

void rec(int k){
    while (k>0)
        u[l[k]]=1,k-=p[l[k]].first;
}

void read(void){
    cin>>n>>s;
    for (int i=0; i<n; ++i)
        cin>>p[i].first,p[i].second=i;
    sort(p,p+n);
    if (p[n-1].first>s){
        cout<<"-1\n";
        return;
    }

    if (!din(s-p[n-1].first)){
        cout<<"-1\n";
        return;
    }

    u[n-1]=1;
    rec(s-p[n-1].first);

    for (int i=0; i<n; ++i){
        int j=p[i].second;
        c[j]=p[i].first;
        g[j]=-1;
        int to=i-1;
        if (to>=0 && !u[to])
            g[j]=p[to].second,c[j]-=p[to].first;
    }

    for (int i=0; i<n; ++i){
        cout<<c[i]<<" ";
        if (g[i]>=0)
            cout<<"1 "<<g[i]+1;
        else
            cout<<"0";
        cout<<"\n";
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    read();
    return 0;
}