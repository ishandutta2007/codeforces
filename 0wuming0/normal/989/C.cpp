#include"bits/stdc++.h"
using namespace std;
vector<pair<int,char> >v;
char s[55][55];
void solve()
{
    int n=50;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
    {
        s[i][j]=v[0].second;
    }
    int k=v[0].first;
    k--;
    int x=1,y=1;
    int op=2;
    for(int i=1;i<=k;i++)
    {
        s[x][y]=v[op].second;
        s[x][y+1]=v[op].second;
        s[x+2][y]=v[op^1].second;
        s[x+2][y+1]=v[op^1].second;
        s[x+1][y+1]=v[1].second;
        op^=1;
        y+=2;
        if(y==51)
        {
            x+=3;
            y=1;
            op^=1;
        }
    }
    x=50;y=1;
    for(int i=0;i<4;i++)v[i].first-=k;
    for(int i=1;i<4;i++)
    {
        while(v[i].first--)
        {
            s[x][y]=v[i].second;
            y+=2;
            if(y==51)
            {
                x-=2;
                y=1;
            }
        }
    }
    cout<<n<<" "<<n<<endl;
    for(int i=1;i<=50;i++)printf("%s\n",s[i]+1);
}
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    v.push_back(pair<int,char>(a,'A'));
    v.push_back(pair<int,char>(b,'B'));
    v.push_back(pair<int,char>(c,'C'));
    v.push_back(pair<int,char>(d,'D'));
    sort(v.begin(),v.end());
    solve();
    return 0;
}