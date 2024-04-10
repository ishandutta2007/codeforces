#include <iostream>
#include <string>

#define M 300300

using namespace std;

int n,a[M],m,l[M],r[M];

void read(void){
    cin>>n>>m;

    for (int i=1; i<M; ++i)
        l[i]=i-1,r[i]=i+1;

    r[0]=1;

    for (int i=0,le,re,w; i<m; ++i){
        cin>>le>>re>>w;
        int li=w;
        int ri=w;
        for (int j=w; j>=le; ){
            j=l[j];
            if (j>=le)
                a[j]=w;
            else
                li=j;
        }

        for (int j=w; j<=re; ){
            j=r[j];
            if (j<=re)
                a[j]=w;
            ri=j;
        }
        l[w]=li;
        r[w]=ri;
        r[li]=w;
        l[ri]=w;
    }

    for (int i=1; i<=n; ++i)
        cout<<a[i]<<" ";
    cout<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    read();
    return 0;
}