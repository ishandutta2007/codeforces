#include <bits/stdc++.h>
using namespace std;
const int N=505;

int n;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("circle.in","r",stdin);
    //freopen("circle.out","w",stdout);
    cin>>n;
    string s;
    int ans=0;
    while(cin>>s)
    {
        int m=s.size();
        int yans=0;
        for(int i=0;i<m;++i)
            if('A'<=s[i] && s[i]<='Z')
                ++yans;
        ans=max(ans,yans);
    }
    cout<<ans<<endl;
    return 0;
}