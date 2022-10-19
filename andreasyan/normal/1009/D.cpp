#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=2550;

int n,m;

int gcd(int x,int y)
{
    if(x==0)
        return y;
    return gcd(y%x,x);
}

vector<pair<int,int> > ans;
void tpel()
{
    cout<<"Possible"<<endl;
    for(int i=0;i<ans.size();++i)
        cout<<ans[i].first<<' '<<ans[i].second<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("dynasties.in","r",stdin);
    //freopen("dynasties.out","w",stdout);
    cin>>n>>m;
    if(m<(n-1))
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
            if(gcd(i,j)==1)
            {
                ans.push_back(m_p(i,j));
                if(ans.size()==m)
                {
                    tpel();
                    return 0;
                }
            }
    }
    cout<<"Impossible"<<endl;
    return 0;
}