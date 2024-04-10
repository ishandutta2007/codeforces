#include <iostream>
#include <set>
#include <utility>
#include <cstring>

using namespace std;

set<pair<int,int> > sol;
int sum[14];

int main()
{
    char sir[20];
    int t,i,j,l;
    cin>>t;

    for(l=0;l<t;l++)
    {
        sol.clear();
        cin.get();
        cin.get(sir+1,20);

        for(i=1;i<=12;i++)
        {
            if(12%i!=0)
                continue;
            for(j=0;j<14;j++)
                sum[j]=0;

                for(j=1;j<=12;j++)
                    sum[(j-1)%i+1]+=(sir[j]=='X');

            for(j=1;j<=i;j++)
            {
                if(sum[j]==(12/i))
                {
                    sol.insert(make_pair(12/i,i));
                    //break;
                }
            }
        }

        cout<<sol.size();
        for(set<pair<int,int> >::iterator it=sol.begin();it!=sol.end();it++)
            cout<<' '<<it->first<<'x'<<it->second;
        cout<<'\n';
    }

    return 0;
}