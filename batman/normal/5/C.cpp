#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N (1001*1000)

string s;
ll dp[N],ans,p,last[N],t=1;
stack <pair <ll,char> > st;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        last[i]=i;
        if(s[i]=='(')st.push({i,s[i]});
        else if(st.size())
        {
            if(st.top().second=='(')
            {
                ll ex=i-st.top().first+1+((st.top().first)?dp[st.top().first-1]:0);
                dp[i]=ex;
                if(dp[st.top().first-1])last[i]=last[st.top().first-1];
                else last[i]=st.top().first;
                if(ex==ans)t++;
                if(ex>ans)ans=ex,p=last[i],t=1;
                st.pop();   
            }

            else
            {
                stack <pair <ll,char> > ex;
                swap(st,ex);
            }   
        }   
            
    }
    cout<<ans<<" "<<t;
    return 0;
}