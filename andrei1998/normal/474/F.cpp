#include <iostream>
#include <algorithm>
#include <vector>

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

int v[100005],n;
int din_gcd[20][100005];
int log2[100005];

void prep_log()
{
    int i;
    log2[1]=0;
    for(i=2;i<=n+1;i++)
        log2[i]=log2[i>>1]+1;
}

void prep()
{
    int i,j,lung=log2[n];
    for(i=1;i<=n;i++)
       din_gcd[0][i]=v[i];
    for(i=1;i<=lung;i++)
        for(j=1;j<=n;j++)
            if((j+((1<<i)-1))<=n)
                din_gcd[i][j]=gcd(din_gcd[i-1][j],din_gcd[i-1][j+(1<<(i-1))]);
}

int rmq(int a,int b){
    int lung=log2[b-a+1];
    return gcd(din_gcd[lung][a],din_gcd[lung][b-(1<<lung)+1]);
}

///////////////////Arbint
struct nod{
    int st;
    int dr;
    vector<int> cells;

    nod(): st(0), dr(0) {}
}arb[4*NMAX];

void build(int st,int dr,int nod=1){
    arb[nod].st=st;arb[nod].dr=dr;

    if(st==dr){
        arb[nod].cells.push_back(v[st]);
        return;
    }

    int mijl=(st+dr)>>1;
    build(st,mijl,nod<<1);
    build(mijl+1,dr,(nod<<1)+1);

    arb[nod].cells.resize(arb[nod<<1].cells.size()+arb[(nod<<1)+1].cells.size());
    merge(arb[nod<<1].cells.begin(),arb[nod<<1].cells.end(),arb[(nod<<1)+1].cells.begin(),arb[(nod<<1)+1].cells.end(),arb[nod].cells.begin());
}

int ans=0;
void query(int st,int dr,int y1,int nod=1){
    //cout<<"query("<<st<<' '<<dr<<' '<<y1<<' '<<nod<<endl;
    if(arb[nod].st==st && arb[nod].dr==dr){
        int val=(upper_bound(arb[nod].cells.begin(),arb[nod].cells.end(),y1)-lower_bound(arb[nod].cells.begin(),arb[nod].cells.end(),y1));
        if(val>0)
            ans+=val;
        return;
    }

    int mijl=(arb[nod].st+arb[nod].dr)>>1;
    if(dr<=mijl)
        query(st,dr,y1,nod<<1);
    else if(st>mijl)
        query(st,dr,y1,(nod<<1)+1);
    else{
        query(st,mijl,y1,nod<<1);
        query(mijl+1,dr,y1,(nod<<1)+1);
    }
}
///////////////////

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];

    prep_log();
    prep();
    build(1,n);

    //cout<<"da"<<endl;
    int m=0;
    cin>>m;

    int l,r;
    while(m--){
        cin>>l>>r;

        ans=0;

        query(l,r,rmq(l,r));
        cout<<r-l+1-ans<<'\n';
    }

    return 0;
}