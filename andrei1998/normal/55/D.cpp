#include <iostream>
#include <algorithm>

#define lint long long int
using namespace std;

inline int gcd(int a,int b){
    if(!b)
        return a;

    int r=a%b;
    while(r){
        a=b;
        b=r;
        r=a%b;
    }

    return b;
}

int lcms[49][49];

inline int lcm(int a,int b){
    return (a*b/gcd(a,b));
}

int frecv[2525];
int direct[2525];
int invers[2525];

int precalc[2525][10];
lint din[2][2][49][2525];

lint ans(lint x){
    if(!x)
        return 1;

    int v[22];
    int lung=0;

    lung=0;
    while(x){
        v[++lung]=x%10;
        x/=10;
    }
    reverse(v+1,v+lung+1);

    int i,j,k,l;
    for(i=0;i<2;i++)
        for(j=0;j<49;j++)
            for(k=0;k<2520;k++)
                din[0][i][j][k]=din[1][i][j][k]=0;
    din[1][0][1][0]=1;

    bool h=0;
    for(i=0;i<lung;i++,h^=1){
        for(j=0;j<49;j++)
            for(k=0;k<2525;k++)
                din[0][h^1][j][k]=din[1][h^1][j][k]=0;

        for(j=1;j<49;j++)
            for(k=0;k<2520;k++){
                for(l=0;l<v[i+1];l++)
                    if(din[1][h][j][k])
                        din[0][h^1][(l>0)?lcms[l][j]:j][precalc[k][l]]+=din[1][h][j][k];
                din[1][h^1][(l>0)?lcms[l][j]:j][precalc[k][l]]+=din[1][h][j][k];

                for(l=0;l<=9;l++)
                    if(din[0][h][j][k])
                        din[0][h^1][(l>0)?lcms[l][j]:j][precalc[k][l]]+=din[0][h][j][k];
            }
    }

    lint rez=0;
    for(j=1;j<49;j++)
        for(k=0;k<2520;k++)
            if(k%invers[j]==0)
                rez+=(din[0][h][j][k]+din[1][h][j][k]);
    return rez;
}


int main()
{
    int i,j;

    int mod;
    for(i=0;i<256;i++){
        mod=1;
        for(j=0;j<8;j++)
            if(i&(1<<j))
                mod=lcm(mod,j+2);
        frecv[mod]=1;
    }

    int poz=0;
    for(i=1;i<=2520;i++)
        if(frecv[i]){
            direct[i]=++poz;
            invers[poz]=i;
        }

    for(i=1;i<49;i++)
        for(j=1;j<49;j++)
            lcms[i][j]=direct[lcm(invers[i],invers[j])];

    for(i=0;i<2520;i++)
        for(j=0;j<10;j++)
            precalc[i][j]=(10*i+j)%2520;

    int t=0;
    cin>>t;

    while(t--){
        lint a,b;

        cin>>a>>b;
        cout<<ans(b)-ans(a-1)<<'\n';
    }

    return 0;
}