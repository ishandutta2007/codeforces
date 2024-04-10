#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<string>
using namespace std;
#define INF 0x3f3f3f3f
#define eps 1e-8
char s[100005];
int main()
{
    cin>>s;
    int len=strlen(s);
    if((s[len-1]-'0')%2)    cout<<0<<endl;
    else
    {
        int num;
        if(len>=2)  num=(s[len-2]-'0')*10+s[len-1]-'0';
        else num=s[len-1]-'0';
        if(!(num%4))   cout<<4<<endl;
        else cout<<0<<endl;
    }

}