#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    string inp;
    
    cin>>inp;
    
    for(int i=0;i<int(inp.size())-2;i++)
    {
            //cout<<i<<' '<<int(inp.length())-2<<endl;
            bool wupped=false;
    while(inp[i]=='W' && inp[i+1]=='U' && inp[i+2]=='B')
    {
                      wupped=true;
                      inp.erase(inp.begin()+i,inp.begin()+i+3);
                      //cout<<inp<<endl;
    }
    if(i && wupped)
    {
     inp.insert(inp.begin()+i,' ');    
     //cout<<inp<<endl;
    }
    }
    
    
    cout<<inp<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}