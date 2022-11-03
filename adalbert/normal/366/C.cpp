#include <bits/stdc++.h>
using namespace std;
long long b[200000],a[200000],mn,imn,mxi,mxj,ans,mx1,mx2,sum1,sum2;
bool dp[10010][10010];
vector <pair <int ,int > > vec;
int main()
{
    long long n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum1+=a[i];
    }
    for (int i=1;i<=n;i++)
    {
        
        cin>>b[i];
        sum2+=b[i];
    }
    dp[0][0]=1;
    vec.push_back(make_pair (0,0));
    mxi=0;
    mxj=0;
    for (int i=1;i<=n;i++)
    {
        mx1=vec.size();
        for (int l=0;l<mx1;l++)
        {
            if (dp[a[i]+vec[l].first][b[i]+vec[l].second]==0 && (b[i]+vec[l].second<=(5000/k)))
            {
                dp[a[i]+vec[l].first][b[i]+vec[l].second]=1;
                vec.push_back(make_pair(a[i]+vec[l].first,b[i]+vec[l].second));
            }
        }
    }
  //  cout<<"!";
    for (int i=0;i<vec.size();i++)
    {
      //  cout<<i<<'\n';
      //  cout<<vec[i].first;
        if (vec[i].second!=0)
        if (vec[i].first/vec[i].second==k && vec[i].first%vec[i].second==0 && vec[i].first>ans) ans=vec[i].first;

        long long h=sum1-vec[i].first;
        long long  w=sum2-vec[i].second;
        if (w!=0)
        if (h/w==k && h%w==0 && h>ans) ans=h;

    }

    if (ans==0) cout<<-1; else
    cout<<ans;

}