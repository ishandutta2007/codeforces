#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (301*1000)
#define INF ((ll)1e9)

string s,ans,frac;
bool brack,zero=1;
ll i;

int main()
{ 
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s;
    if(s[0]=='-')cout<<"(",brack=1,i++;
    
    while(s[i]!='.' && i<s.size())
    {
        if(s[i]!='0' || zero==0)
            ans+=s[i],zero=0;
        i++;
    }
    if(ans.size()==0)ans+='0';  
        
    i++;
    while(i<s.size() && frac.size()<2)
        frac+=s[i],i++;
    while(frac.size()<2)
        frac+='0';
            
    cout<<"$";
    for(int i=0;i<ans.size();i++)
    {
        if((ans.size()-i)%3==0 && i)cout<<",";
        cout<<ans[i];
            
    }   
    cout<<".";
    for(int i=0;i<frac.size();i++)cout<<frac[i];
    if(brack)cout<<")";
    
    
    return 0;
}