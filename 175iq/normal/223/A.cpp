#include <bits/stdc++.h>
typedef long long ll;
#define M 1000000007
#define endl "\n"
#define int long long
using namespace std;
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int l = s.length();
    stack<pair<char,int>> st;
    vector<pair<int,int>> v;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='(')
        {
            st.push({'(',i});
        }
        if(s[i]=='[')
        {
            st.push({'[',i});
        }
        if(s[i]==')')
        {
            if(st.empty())
            {
                continue;
            }
            else
            {
                if(st.top().first=='[')
                {
                    while(!st.empty())
                    {
                        st.pop();
                    }
                }
                else
                {
                    v.push_back({st.top().second,i});
                    st.pop();   
                }                
            }            
        }
        if(s[i]==']')
        {
            if(st.empty())
            {
                continue;
            }
            else
            {
                if(st.top().first=='(')
                {
                    while(!st.empty())
                    {
                        st.pop();
                    }
                }
                else
                {
                    v.push_back({st.top().second,i});
                    st.pop();   
                }                
            }            
        }
    }
    int start=-5;
    int last=-5;
    int siz=v.size();
    vector<string> all;
    sort(v.begin(),v.end());
    for(int i=0;i<siz;i++)
    {
        //cout<<v[i].first<<" "<<v[i].second<<endl;
        if(v[i].first==(1+last))
        {
            last=v[i].second;            
        }
        if(i==siz-1)
        {
            if(start>=0 && last>=0)
            {
                all.push_back(s.substr(start,last-start+1));
                
            }             
        }
        if(v[i].first>(1+last) )//|| (i==(siz-1)))
        {
            if(start>=0 && last>=0)
            {
                all.push_back(s.substr(start,last-start+1));
                
            }
            start=v[i].first;
            last=v[i].second;
        }
        if(i==siz-1)
        { if(start>=0 && last>=0)
            {
                all.push_back(s.substr(start,last-start+1));
                
            }             
        }        
        if(v[i].first<last)
        {
            continue;
        }        
    }
    int ma=0;
    string ans="";
    for(auto x: all)
    {
        //cout<<x<<endl;
        int l=x.length();
        int cnt=0;
        for(int i=0;i<l;i++)
        {
            if(x[i]=='[')
            {
                cnt++;
            }
        }
        if(cnt>ma)
        {
            ma=cnt;
            ans=x;
        }
    }
    cout<<ma<<endl<<ans;
}