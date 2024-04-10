#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> v={"N","H","HE","LI","BE","B","C","N","O","F","NE","NA","MG","AL","SI","P","S","CL","AR","K","CA","SC","TI","V","CR","MN","FE","CO","NI","CU","ZN","GA","GE","AS","SE","BR","KR","RB","SR","Y","ZR","NB","MO","TC","RU","RH","PD","AG","CD","IN","SN","SB","TE","I","XE","CS","BA","LA","CE","PR","ND","PM","SM","EU","GD","TB","DY","HO","ER","TM","YB","LU","HF","TA","W","RE","OS","IR","PT","AU","HG","TL","PB","BI","PO","AT","RN","FR","RA","AC","TH","PA","U","NP","PU","AM","CM","BK","CF","ES","FM","MD","NO","LR","RF","DB","SG","BH","HS","MT","DS","RG","CN","NH","FL","MC","LV","TS","OG"};
    string s;
    cin >> s;
    int n=s.size();
    s="0"+s;
    vector<bool> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(string x:v)
        {
            if(x.size()<=i&&s.substr(i-x.size()+1,x.size())==x&&dp[i-x.size()]==1) dp[i]=1;
        }
    }
    if(dp[n]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}