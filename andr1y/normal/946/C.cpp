#include <iostream>


using namespace std;
int main()
{
    char s[100010];  char c='a';
    cin>>s;
    for(int i=0;s[i]!=0;i++)
    {
        if(s[i]<=c && c<='z') s[i]=c,c++;
    }
    if(c=='z'+1) cout<<s;
    else cout<<-1;
    return 0;
}