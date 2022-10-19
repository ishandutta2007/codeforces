#include"bits/stdc++.h"
using namespace std;
map<string,vector<int> >mp;
vector<int> clk;
int a[305],nn;
int val[305];
int sval[305];
int main()
{
    int next[305]={0};
    int n;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;//cout<<s;
        if(mp.find(s)==mp.end())
        {
            mp[s]=clk;
            (mp.find(s)->second).push_back(i);
        }
        else
        {
            (mp.find(s)->second).push_back(i);
        }
    }//cout<<mp.size()<<endl;;//
    for(map<string,vector<int> >::iterator it=mp.begin();it!=mp.end();++it)
    {

        for(vector<int>::iterator it2=(it->second).begin();it2!=(it->second).end();++it2)
        {
            val[*it2]=(it->first).size();
            a[*it2]=nn;//cout<<nn<<endl;;
        }
        nn++;
    }
    for(int i=1;i<=n;i++)sval[i]=sval[i-1]+val[i];
    next[1]=0;
    next[2]=1;
    int last=1;
    for(int i=3;i<=n;)
    {
        if(last==0)
        {
            last=1;
            next[i]=1;
            i++;
        }
        else if(a[last]==a[i-1])
        {
            next[i]=last+1;
            last++;
            i++;
        }
        else last=next[last];
    }//for(int i=1;i<=n;i++)cout<<sval[i]<<endl;
    int ans=0;
    for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)
    {
        int t0=i;
        int num=0;
        for(int k=j+1;k<=n;)
        {
            if(a[t0]==a[k])
            {
                t0++;k++;
                if(t0>j)
                {
                    t0=i;
                num++;
                }
            }
            else
            {
                //t0=next[t0];
                k=k-t0+i+1;
                t0=i;/*
                if(t0<i)
                {
                    t0=i;
                    k++;
                }*/
            }
        }//cout<<i<<" "<<j<<" "<<num<<"  "<<ans<<endl;
        if(num>0)ans=max(ans,(num+1)*(sval[j]-sval[i-1]-1));
    }
    cout<<sval[n]+n-1-ans<<endl;
    return 0;
}
/*
5
a a a a a
*/