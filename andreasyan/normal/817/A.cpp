#include <bits/stdc++.h>
using namespace std;
const int N=500005;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("dices.in","r",stdin);
    //freopen("dices.out","w",stdout);
    int x1,y1,x2,y2;
    int x,y;
    cin>>x1>>y1>>x2>>y2;
    cin>>x>>y;
    for(int i=x1,j=y1;-N<=i && i<=N && -N<=j && j<=N;i+=x,j+=y)
        if(abs(i-x2)%x==0 && abs(j-y2)%y==0 && abs(i-x2)/x==abs(j-y2)/y)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    for(int i=x1,j=y1;-N<=i && i<=N && -N<=j && j<=N;i-=x,j+=y)
        if(abs(i-x2)%x==0 && abs(j-y2)%y==0 && abs(i-x2)/x==abs(j-y2)/y)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    for(int i=x1,j=y1;-N<=i && i<=N && -N<=j && j<=N;i+=x,j-=y)
        if(abs(i-x2)%x==0 && abs(j-y2)%y==0 && abs(i-x2)/x==abs(j-y2)/y)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    for(int i=x1,j=y1;-N<=i && i<=N && -N<=j && j<=N;i-=x,j-=y)
        if(abs(i-x2)%x==0 && abs(j-y2)%y==0 && abs(i-x2)/x==abs(j-y2)/y)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    cout<<"NO"<<endl;
    return 0;
}