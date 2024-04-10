#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int a=0;a<t;a++)
    {
        string s;
        cin>>s;
        if(s.size()<=10)
        {
            cout<<s;
        }
        else
        {
            cout<<s[0]<<s.size()-2<<s[s.size()-1];
        }
        cout<<endl;
    }
    return 0;
}