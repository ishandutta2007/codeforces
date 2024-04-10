#include <cstdlib>
#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int k;
    string b,bor;
    cin>>k>>bor;
    b=bor;
    
    sort(b.begin(),b.end());
    
    if(b.size()%k)
    cout<<-1<<endl;
    else
    {
        string ans="";
        bool ok=true;
        for(int i=0;i<b.size();i+=k)
        {
                for(int j=0;j<k;j++)
                if(!(b[i]==b[i+j]))
                ok=false;
                //cout<<b.size()<<endl;
                if(ok)
        ans.push_back(b[i]);
        else
        break;
        }
        if(!ok)
        cout<<-1<<endl;
        else
        {
            for(int i=0;i<k;i++)
            cout<<ans;
            cout<<endl;
        }
    }
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}