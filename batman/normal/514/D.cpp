#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (101*1000)
#define K (11)
ll n,m,k,a[N][K],ans,res[K];
set <ll> s[K];
map <ll,ll> mp[K];

int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    ll maxi[K]={},sum=0;         
    for(int i=0,j=0;i<n;i++)
    {
        /*
        if(s[2].size())
        {
            set <ll>::iterator it=s[2].end();it--;
            cout<<*it<<endl;    
        }
        */
        
        for(int p=0;p<m;p++)
        {
            sum+=max(0ll,a[i][p]-maxi[p]);  
            maxi[p]=max(maxi[p],a[i][p]);
            //cout<<maxi[p]<<" ";
        }   
        for(int p=0;p<m;p++)
            mp[p][a[i][p]]++,s[p].insert(a[i][p]);  
        //cout<<endl;
        /*
        if(s[2].size())
        {
            set <ll>::iterator it=s[2].end();it--;
            cout<<*it<<endl;    
        }
        */
        //cout<<i<<" "<<j<<" "<<sum<<endl;
        while(sum>k && j<=i)
        {
            for(int p=0;p<m;p++)
                if(mp[p][a[j][p]]==1)
                {
                    //set <ll>::iterator it=s[p].end();it--;
                    //if(p==2)
                    //  cout<<*it<<endl;
                    mp[p][a[j][p]]--;
                    s[p].erase(a[j][p]);
                    //it=s[p].end();it--;
                    //if(p==2)
                    //  cout<<*it<<endl;
                    if(s[p].size())
                    {
                        set <ll>::iterator it=s[p].end();it--;
                        //if(p==2)
                        //  cout<<*it<<endl;
                        sum+=*it-maxi[p];
                        maxi[p]=*it;    
                    }
                    else
                        sum-=maxi[p],maxi[p]=0;
                }
            j++;    
        }
        
        if(i-j+1>ans)
        {
            ans=i-j+1;
            for(int p=0;p<m;p++)res[p]=maxi[p];
        }
        //cout<<i<<" "<<j<<" "<<sum<<endl;
    }   
    //cout<<ans<<"\n";
    for(int p=0;p<m;p++)cout<<res[p]<<" ";     
    return 0;
}