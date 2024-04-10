#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int l=s.length(),k=0,d=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
            k++;
        if(s[i]==')')
            d++;
    }
    k-=d;
    vector <int> ans;
    for(int i=0;i<l;i++)
        if(s[i]=='#')
            d=i;
    int o=0;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='(')
            o++;
        else
            if(s[i]==')')
                o--;
            else
                if(i!=d)
                {
                    ans.push_back(1);
                    o--;
                    k--;
                }
                else
                {
                    ans.push_back(k);
                    o-=k;
                }
        //cout<<o<<endl;
        if(o<0)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    if(ans[ans.size()-1]<=0)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}