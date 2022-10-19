#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
#define N 1002
#define M 55

int q;
char a[M];
char b[M];

void gord(char* s)
{
    for(int i=0; s[i]; i++){
        if(s[i]>='A' && s[i]<='Z')
            s[i]=s[i]-'A'+'a';
        if(s[i]=='o')
            s[i]='0';
        if(s[i]=='i' || s[i]=='l')
            s[i]='1';
    }
}

int main()
{
    cin>>a;
    gord(a);
    cin>>q;
    bool z=true;
    while(q--)
    {
        cin>>b;
        gord(b);
        if(strcmp(a, b)==0)
            z=false;
    }
    if(z)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}