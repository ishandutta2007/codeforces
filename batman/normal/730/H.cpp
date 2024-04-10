#include<iostream>
using namespace std;
#define ll long long
#define N ((ll)110)

ll n,m;
string s[N],t;
bool mark[N];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    ll num=-1;
    for(int i=0;i<m;i++)
    {
        ll x;
        cin>>x;
        mark[x]=1;
        if(num==-1)num=s[x].size();
        else if(num!=s[x].size())return cout<<"No",0;
    }
    for(int i=0;i<num;i++)
    {
        char c='*';
        bool flg=1;
        for(int j=1;j<=n;j++)
            if(mark[j])
            {
                if(c=='*')c=s[j][i];
                else if(c!=s[j][i])flg=0;
            }
        if(!flg)c='?';
        t+=c;
    }
    for(int i=1;i<=n;i++)
        if(!mark[i] && s[i].size()==num)
        {
            bool flg=1;
            for(int j=0;j<num;j++)
            {
                if(t[j]!=s[i][j] && t[j]!='?')flg=0;
            }
            if(flg)return cout<<"No",0;
        }
    cout<<"Yes\n"<<t<<"\n";
}