#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
long long a,ans;
ifstream fin("input.txt");
int main()
{
    
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='h' && s[i+1]=='e' && s[i+2]=='a' && s[i+3]=='v' && s[i+4]=='y')
            a++;
        if(s[i]=='m' && s[i+1]=='e' && s[i+2]=='t' && s[i+3]=='a' && s[i+4]=='l')   
            ans+=a;
    }
    cout<<ans;  
    return 0;
}