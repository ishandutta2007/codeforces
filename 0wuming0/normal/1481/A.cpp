#include"bits/stdc++.h"
using namespace std;
char s[100005];
int main()
{
    int x,y;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        char cx,cy;
        scanf("%s",s);
        if(x<=0)cx='L';else cx='R';
        if(y<=0)cy='D';else cy='U';
        x=abs(x);y=abs(y);
        for(int i=0;s[i];i++)
        {
            if(cx==s[i])x--;
            if(cy==s[i])y--;
        }
        if(x>0||y>0)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}