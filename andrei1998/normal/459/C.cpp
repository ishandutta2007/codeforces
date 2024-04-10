//#include <fstream>
#include <iostream>

using namespace std;

bool posibil(int n,int d,int k)
{
    if(d==1)
        return (k>=n);
    return posibil(n/k+(bool)(n%k),d-1,k);
}

int what[1005][1005];
void arrange(int st,int dr,int d,int k){
    //cout<<st<<' '<<dr<<' '<<d<<' '<<k<<endl;
    if(!d)
        return;

    int poz=st;
    int n=dr-st+1;
    int part=n/k;
    int rest=n%k;

    int curent;
    int l,r;

    for(int i=1;i<=k;i++){
        curent=part+(i<=rest);

        if(curent==0)
            break;

        l=poz;
        while(curent--)
            what[d][poz++]=i;
        r=poz-1;

        if(l<=r)
            arrange(l,r,d-1,k);
    }

}

int main()
{
    ios::sync_with_stdio(0);
    //ofstream cout("fis.out");
    int n,d,k;
    cin>>n>>k>>d;
    if(k>1000)
        k=1000;

    if(!posibil(n,d,k)){
        cout<<"-1\n";
        return 0;
    }

    arrange(1,n,d,k);
    int j;

    for(int i=1;i<=d;i++){
        cout<<what[i][1];
        for(j=2;j<=n;j++)
            cout<<' '<<what[i][j];
        cout<<'\n';
    }

    return 0;
}