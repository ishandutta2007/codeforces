#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    char s[150001];
    while(t--)
    {
        scanf("%s",s);
        int n=strlen(s);
        vector<int> v;
        string a;
        for(int i=0;i<n;i++)
        {
            a+=s[i];
            if(a.size()>=3&&a.substr(a.size()-3,3)=="one")
            {
                v.push_back(i-1);
                char c=a.back();
                a.pop_back();
                a.pop_back();
                a.push_back(c);
            }
            else if(a.size()>=3&&a.substr(a.size()-3,3)=="two")
            {
                if(i==n-1||s[i+1]!='o')
                {
                    v.push_back(i);
                    a.pop_back();
                }
                else
                {
                    v.push_back(i-1);
                    char c=a.back();
                    a.pop_back();
                    a.pop_back();
                    a.push_back(c);
                }
            }
        }
        printf("%d\n",(int)v.size());
        for(int a:v) printf("%d ",a+1);
        printf("\n");
    }
    return 0;
}