#include"bits/stdc++.h"
using namespace std;
char s[15];
char ans[15];
char ans2[15];
bool solve(int &n,int i,set<int>&st)
{//cout<<"<<"<<n<<" "<<i<<endl;
    if(i==n)return 1;
    for(auto a:st)
    {//cout<<"<<"<<i<<" "<<n<<" "<<((int)s[i])<<" "<<a<<endl;
        if(a==s[i])
        {
            ans[i]=a;
            //cout<<"ok"<<n<<" "<<i+1<<endl;
            //cout<<"!!!!"<<n<<endl;
            if(solve(n,i+1,st))return 1;
        }
        if(a>s[i])
        {
            ans[i]=a;
            set<int>ss;
            for(int j=0;j<=i;j++)ss.insert(ans[j]);
            if(ss.size()!=st.size())
            {
                for(int j=i+1;j<n;j++)
                {
                    ans[j]=0;
                }
            }
            else
            {
                for(int j=i+1;j<n;j++)
                {
                    ans[j]=*st.begin();
                }
            }
            return 1;
        }
    }//cout<<"ok"<<endl;
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        scanf("%s%d",&s,&k);
        n=strlen(s);
        ans[n]=ans2[n]=0;
        for(int i=0;i<n;i++)s[i]-='0';
        for(int i=0;i<=n;i++)ans[i]=0;
        map<int,int>save,mp;
        for(int i=n-1;i>=0;i--)
        {
            save[s[i]]=i;
        }
        for(auto pr:save)
        {
            mp[pr.second]=pr.first;
        }
        set<int>st;
        int p,lp,lnum;
        {
            auto it=mp.begin();
            for(int i=0;i<k;i++)
            {
                st.insert(it->second);
                lp=it->first;
                lnum=it->second;
                it++;
                if(it==mp.end())
                {//cout<<"<<ok"<<endl;
                    for(int j=0;j<n;j++)s[j]+='0';
                    printf("%s\n",s);
                    goto ne;
                }
            }
            p=it->first;
        }
        //for(int i=0;i<p;i++)ans[i]=s[i];
        {//bool sk;
            if(solve(n,0,st)==0)
            {
                for(int i=0;i<n;i++)ans[i]=9;
            }
            for(int j=0;j<n;j++)ans[j]+='0';
        }//cout<<"ok"<<" "<<lnum<<" "<<lp<<endl;
        st.erase(st.find(lnum));
        if(lnum==9)
        {
            printf("%s\n",ans);
            goto ne;
        }
        st.insert(lnum+1);
        for(int i=0;i<n;i++)ans2[i]=s[i];
        ans2[lp]=lnum+1;
        for(int i=lp+1;i<n;i++)
        {
            ans2[i]=*st.begin();
        }
        for(int j=0;j<n;j++)ans2[j]+='0';
        if(strcmp(ans,ans2)>0)printf("%s\n",ans2);
        else printf("%s\n",ans);
        ne:;
    }
    return 0;
}