#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF ((ll)1e14)
#define N (301*1000)

ll ans;
string s;
stack <char> st;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='<' || s[i]=='{' || s[i]=='(' || s[i]=='['){st.push(s[i]);continue;}
        if(!st.size())
            return cout<<"Impossible",0;
        if(s[i]=='>' && st.top()=='<')
            st.pop();
        else if(s[i]==')' && st.top()=='(')
            st.pop();
        else if(s[i]=='}' && st.top()=='{')
            st.pop();   
        else if(s[i]==']' && st.top()=='[')
            st.pop();               
        else st.pop(),ans++;    
    }
    if(st.size())return cout<<"Impossible",0;
    cout<<ans;
    return 0;
}