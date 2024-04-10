#include"bits/stdc++.h"
using namespace std;
int main()
{
    char s[400];
    int ans[400]={0};
    scanf("%s",s);
    for(int i=0;s[i];i++)ans[s[i]]++;
    scanf("%s",s);
    for(int i=0;s[i];i++)ans[s[i]]++;
    scanf("%s",s);
    for(int i=0;s[i];i++)ans[s[i]]--;
    for(int i=0;i<400;i++)if(ans[i])
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    return 0;
}