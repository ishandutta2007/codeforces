#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int n,k;
    cin>>n>>k;
    
    int*a=new int[n];
    
    vector < vector<int> > anses;
    vector<int> sums;
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    if(sums.size()<k)
    {
                     bool oki=true;
                     for(int k=0;k<sums.size();k++)
            {
                    if(a[i]==sums[k])
                    {
                                    oki=false;
                                    break;
                    }
            }
            int to=anses.size();
            vector<int> tmp;
            if(oki)
            {
    sums.push_back(a[i]);
    tmp.push_back(a[i]);
    anses.push_back(tmp);
         }
    for(int j=0;j<to;j++)
    {
            tmp=anses[j];
            tmp.push_back(a[i]);
            int sum=sums[j]+a[i];
            bool ok=true;
            for(int k=0;k<sums.size();k++)
            {
                    if(sum==sums[k])
                    {
                                    ok=false;
                                    break;
                    }
            }
            if(ok)
            {
            anses.push_back(tmp);
            sums.push_back(sum);
            }
    }
    }
    }
    for(int i=0;i<k;i++)
    {
            cout<<anses[i].size()<<' ';
            for(int j=0;j<anses[i].size();j++)
            cout<<anses[i][j]<<' ';
            cout<<endl;
    }
    //system("PAUSE");
    return EXIT_SUCCESS;
}