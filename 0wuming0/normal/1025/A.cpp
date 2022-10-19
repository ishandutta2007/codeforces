#include"bits/stdc++.h"
using namespace std;
char s[100005];
int num[1000];
int main()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        scanf("%s",s);
        for(int i=0;s[i];i++)
        {
            num[s[i]]++;
            if(num[s[i]]==2)
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        cout<<"No"<<endl;
    }
    return 0;
}