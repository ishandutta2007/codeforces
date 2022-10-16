#include <iostream>
#include <algorithm>
#include <map>

#define NMAX 100005
using namespace std;

int gcd(int a,int b){
    int r=a%b;
    while(r){
        a=b;
        b=r;
        r=a%b;
    }

    return b;
}

int n;
int v[NMAX];

int lg[NMAX];
int din[18][NMAX];

inline void prec(){
    for(int i=2;i<NMAX;i++)
        lg[i]=lg[i/2]+1;

    for(int i=1;i<=n;i++)
        din[0][i]=v[i];

    int j;
    for(int i=1;(1<<i)<=n;i++)
        for(j=1;j+(1<<i)-1<=n;j++)
            din[i][j]=gcd(din[i-1][j],din[i-1][j+(1<<(i-1))]);
}

inline int rmq(int st,int dr){
    int l=lg[dr-st+1];
    return gcd(din[l][st],din[l][dr-(1<<l)+1]);
}

map<int,long long int> Map;

inline int cb(int start,int start2){
    int st=start2;
    int dr=n;
    int mijl=(st+dr)>>1;
    int rasp=st;
    int cons=rmq(start,start2);

    while(st<=dr){
        if(rmq(start,mijl)!=cons)
            dr=mijl-1;
        else{
            st=mijl+1;
            rasp=mijl;
        }

        mijl=(st+dr)>>1;
    }

    return rasp;
}

inline void calc(){
    int j;
    int ans;

    for(int i=1;i<=n;i++){
        for(j=i;j<=n;){
            ans=cb(i,j);
            Map[rmq(i,j)]+=(ans-j+1);

            j=ans+1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    prec();

    calc();

    int q=0;
    cin>>q;

    int x;
    while(q--){
        cin>>x;

        cout<<Map[x]<<'\n';
    }

    return 0;
}