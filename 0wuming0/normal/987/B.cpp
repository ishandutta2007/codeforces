#include"bits/stdc++.h"
using namespace std;
int main()
{
    //printf("%.15f\n",log((double)1e9)/1e9);
    //printf("%.15f\n",log((double)1)/1);
    //printf("%.15f\n",log((double)2)/2);
    //printf("%.15f\n",log((double)3)/3);
    //printf("%.15f\n",log((double)4)/4);
    int x,y;
    cin>>x>>y;
    if(x==1)x=1e9+1;
    if(y==1)y=1e9+1;
    if(x==2)x=4;
    if(y==2)y=4;
    if(x==y)cout<<'='<<endl;
    else if(x>2&&y>2)
    {
        if(x<y)cout<<'>'<<endl;
        else cout<<'<'<<endl;
    }
    else return 1;
    return 0;
}