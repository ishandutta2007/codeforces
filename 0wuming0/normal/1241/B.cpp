#include"bits/stdc++.h"
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        char s[105],t[105];
        scanf("%s%s",s,t);
        int n,f1=0,f2=0;
        n=strlen(s);
        if(strcmp(s,t)==0){cout<<"YES"<<endl;continue;}
            int num[300]={0};
            for(int i=0;i<n;i++)
            {
                num[s[i]-'a']++;
                if(num[t[i]-'a']==2)
                {
                    f1=1;
                }
            }
            int num2[300]={0};
            for(int i=0;i<n;i++)
            {
                num2[t[i]-'a']++;
                if(num2[t[i]-'a']==2)
                {
                    f2=1;
                }
            }
        int now1=1,now2=1;
        for(int i=0;i<26;i++)
        {
            if(num[i]!=0&&num2[i]!=0)now1=0;
            //if(num[i]==0&&num2[i]!=0)now2=0;
        }//cout<<num2[2];
        if(!now1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
/*
3
xabbc
aabxc
technocup
technocup
a
z
*/