#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.length();
    set<string> ans;
    if(n>6) ans.insert(s.substr(n-2,2));
    if(n>7) ans.insert(s.substr(n-3,3));
    reverse(s.begin(),s.end());
    vector<bool> dp2(n, false), dp3(n, false);
    dp2[0]=true; dp3[0]=true;
    for(int i=2; i<n; i++)
    {
        if(n-i>6)
            dp2[i]=(i==2?false:dp3[i-3])||(dp2[i-2]&&s.substr(i-2,2)!=s.substr(i,2));
        if(n-i>7)
            dp3[i]=dp2[i-2]||(i==2?false:dp3[i-3]&&s.substr(i-3,3)!=s.substr(i,3));
        if(dp2[i]) { string s2=s.substr(i,2); reverse(s2.begin(), s2.end()); ans.insert(s2); };
        if(dp3[i]) { string s3=s.substr(i,3); reverse(s3.begin(), s3.end()); ans.insert(s3); };
    }
    cout<<ans.size()<<endl;
    for(string str : ans)
        cout<<str<<endl;
    return 0;
}