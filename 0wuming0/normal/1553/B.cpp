#include"bits/stdc++.h"
using namespace std;
int main()
{
    char s[505],t[1005];
    int T;
    cin>>T;
    while(T--)
    {
        cin>>s>>t;
        int n=strlen(s),m=strlen(t);
        for(int i=0;i<n;i++)for(int j=i;j<n;j++)
        {
            if(t[j-i]!=s[j])break;
            int now=j-i+1,k=j-1;
            while(1)
            {
                if(now==m)
                {
                    cout<<"yes"<<endl;
                    goto ne;
                }
                if(k>=0&&s[k]==t[now])
                {
                    now++;
                    k--;
                }
                else break;
            }
        }
        cout<<"no"<<endl;
        ne:;
    }
    return 0;
}