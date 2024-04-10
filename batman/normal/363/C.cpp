#include <iostream>
using namespace std;
string s;
char k;
bool mark;
int main()
{
    
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=k)
        {
        if(s[i]==s[i+1] && mark==false)
        {
            cout<<s[i]<<s[i+1];
            k=s[i];
            mark=true;
        }
        else if(s[i]==s[i+1] && mark==true)
        {
            cout<<s[i];
            k=s[i];
            mark=false;
        }
        else
        {
            cout<<s[i];
            k=s[i];
            mark=false;
        }
            
        
        }
    
    
    }
    


    return 0;
}