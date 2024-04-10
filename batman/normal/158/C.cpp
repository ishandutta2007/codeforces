#include <bits/stdc++.h>
using namespace std;
#define N (22000)
#define ll long long
ll q;
deque <string> dq;
int main()
{
    cin>>q;
    while(q--)
    {
        string x;
        cin>>x;
        if(x=="cd")
        {
            string s,ex="";
            cin>>s;
            if(s[0]=='/')
                dq.clear();
            for(int i=0;i<s.size();i++)
            {
                if(i<s.size()-1 && s[i]==s[i+1] && s[i]=='.')
                {
                    i++;
                    if(dq.size())
                        dq.pop_back();
                }
                    
                else if(s[i]=='/')
                {
                    if(ex!="")
                        dq.push_back(ex),ex="";
                }
                    
                else
                    ex+=s[i];           
            }
            if(ex!="")
                dq.push_back(ex);
        }
        else
        {
            cout<<"/";
            for(int i=0;i<dq.size();i++)
                cout<<dq[i]<<"/";
            cout<<"\n"; 
        }
                    
    }
    return 0;
}