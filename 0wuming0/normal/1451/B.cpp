#include"bits/stdc++.h"
using namespace std;
char s[106];
int main()
{
    int t,n,q;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        scanf("%s",s);
        while(q--)
        {
            int a,b;
            cin>>a>>b;
            a--,b--;
            int j=a;
            int op=-1;
            for(int i=0;i<n;i++)
            {
                if(op>=0&&s[i]==s[j])
                {
                    if(j==b&&b-a==i-op)continue;
                    j++;
                }
                if(op==-1&&s[i]==s[j])j++,op=i;
                //if(j==b)cout<<i<<op<<endl;
            }
            if(j>b)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}