#include<cstdlib>
#include<iostream>
using namespace std;
int main()
{
    string s,pp;
    cin>>s;
    pp="hello";
    int i,j;
    j=0;
    
    for(i=0;i<s.size();i++)
    {
         if(s[i]==pp[j])j++;
    }
    cout<<(j==5?"YES":"NO")<<endl; 
    
    
   // system("pause");
    return 0;
}