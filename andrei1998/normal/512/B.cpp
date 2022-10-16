#include <iostream>
#include <map>

#define inf 600002505
using namespace std;

int gcd (int a, int b) {
    if(!b)
        return a;

    int r=a%b;
    while(r) {
        a=b;
        b=r;
        r=a%b;
    }

    return b;
}

map<int,int> big_to_small;
map<int,int> small_to_big;
int poz;

inline void decompose (int n) {
    for(int i=1;i*i<=n;i++)
        if(n%i==0) {
            if(!big_to_small.count(i)) {
                big_to_small[i]=++poz;
                small_to_big[poz]=i;
            }

            if(!big_to_small.count(n/i)) {
                big_to_small[n/i]=++poz;
                small_to_big[poz]=n/i;
            }
        }
}

int v[305];
int c[305];
int din[305][60005];

int main()
{
    ios_base::sync_with_stdio(false);

    int n=0;
    cin>>n;

    for(int i=1;i<=n;i++) {
        cin>>v[i];
        decompose(v[i]);
    }
    for(int i=1;i<=n;i++)
        cin>>c[i];

    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=poz;j++)
            din[i][j]=inf;
    din[0][0]=0;

    int aux;
    for(i=0;i<n;i++)
        for(j=0;j<=poz;j++)
            if(din[i][j]<inf){
                aux=big_to_small[gcd(v[i+1],small_to_big[j])];
                if(din[i][j]+c[i+1]<din[i+1][aux])
                    din[i+1][aux]=din[i][j]+c[i+1];
                if(din[i][j]<din[i+1][j])
                    din[i+1][j]=din[i][j];
            }

    if(din[n][big_to_small[1]]>=inf)
        cout<<"-1\n";
    else
        cout<<din[n][big_to_small[1]]<<'\n';
    return 0;
}