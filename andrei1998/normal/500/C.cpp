#include <iostream>
#include <algorithm>

using namespace std;

int w[1005];
int b[1005];

bool viz[1005];
int stiva[2005];

int extract(int x) {
    int ans=0;
    while(x!=1){
        ans+=w[stiva[x-1]];
        swap(stiva[x],stiva[x-1]);
        x--;
    }

    return ans;
}

int main()
{
    int n=0,m=0;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        cin>>w[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];

    int poz=0;
    for(int i=1;i<=m;i++){
        if(!viz[b[i]]){
            viz[b[i]]=1;
            stiva[++poz]=b[i];
        }
    }

    long long int ans=0;

    int j;
    for(int i=1;i<=m;i++){
        for(j=1;j<=n;j++)
        if(stiva[j]==b[i]){
            ans+=extract(j);
            break;
        }
    }

    cout<<ans<<endl;
    return 0;
}