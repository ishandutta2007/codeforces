#include <iostream>
using namespace std;
int Z,A,B,V,W,Q,x,y,q,w,X[999],Y[999];
string S;
main()
{
    cin>>A>>B>>S;
    X[Q]=Y[Q++]=0;
    for(char c:S)
    {
        V=V+(c=='R')-(c=='L'),W=W+(c=='U')-(c=='D');
        X[Q]=V,Y[Q++]=W;
    }
    for(int i=0;i<Q;i++)
    {
        q=V?(A-X[i])/V:0,w=W?(B-Y[i])/W:0;
        x=X[i]+V*q,y=Y[i]+W*w;
        if((q==w||V==0||W==0)&&q>=0&&w>=0&&x==A&&y==B) 
        Z=1;
    }
    cout<<(Z?"Yes":"No");
}