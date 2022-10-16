#include <iostream>

using namespace std;

int v1[200010];
int v2[200010];

int pi[200010];

int main()
{
    ios_base::sync_with_stdio(false);
    int n=0,m=0;

    cin>>n>>m;

    if(n==1 && m==1){
        cout<<"1\n";
        return 0;
    }
    else if(m==1){
        cout<<n<<'\n';
        return 0;
    }
    else if(n==1){
        cout<<"0\n";
        return 0;
    }

    for(int i=0;i<n;i++)
        cin>>v1[i];
    for(int i=n-1;i>=1;i--)
        v1[i]-=v1[i-1];
    n--;

    for(int i=0;i<m;i++)
        cin>>v2[i];
    for(int i=m-1;i>=1;i--)
        v2[i]-=v2[i-1];
    m--;

    int k=0;
    for(int i=2;i<=m;i++){
        while(k>0 && v2[k+1]!=v2[i])
            k=pi[k];

        if(v2[k+1]==v2[i])
            k++;
        pi[i]=k;
    }

    k=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        while(k>0 && v2[k+1]!=v1[i])
            k=pi[k];

        if(v2[k+1]==v1[i])
            k++;

        if(k==m){
            ans++;
            k=pi[k];
        }
    }

    cout<<ans<<'\n';
    return 0;
}