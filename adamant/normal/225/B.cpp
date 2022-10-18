#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char *argv[])
{
    int pu;
    int s,k;
    
    cin>>s>>k;
    if(s==1)
    {
            cout<<2<<endl<<0<<' '<<1<<endl;
            return 0;
    }
    if(s==2)
    {
            cout<<2<<endl<<0<<' '<<2<<endl;
            return 0;
    }
    vector<int> bon;
    bon.push_back(1);
    for(int i=0;i<k && bon[bon.size()-1]<s;i++)
    {
            pu=pow(2,i);
                              if(pu<=s)
                              bon.push_back( pu );
                              else
                              goto res;
    }
    do
    {
                              pu=accumulate( bon.end()-k,bon.end(),0 );
                              if(pu<=s)
                              bon.push_back( pu );
    }
    while(pu<s);
    
res:
    vector<int> ans;
    int y=0;
for(int i=0;i<bon.size();i++)
{
        if(s==bon[i])
        {
        cout<<2<<endl<<0<<' '<<s<<endl;
        return 0;
        }
}
    while(s)
    {
            if(bon[bon.size()-1-y]<=s)
            {
            s-=bon[bon.size()-1-y];
            ans.push_back(bon[bon.size()-1-y]);
            }
            y++;
    }
    cout<<ans.size()<<endl<<ans[0];
    for(int i=1;i<ans.size();i++)
    cout<<' '<<ans[i];
    cout<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}