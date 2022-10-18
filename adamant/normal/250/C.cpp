#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    int n,k;
    cin>>n>>k;
    int*a=new int[n];
    vector<int>*b=new vector<int>[k];
    vector<int> gr,jr;
    gr.push_back(0);
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    if(i==0)
    {
            b[a[i]-1].push_back(0);
                jr.push_back(a[i]);
    }
    if(i==0 || a[i]==a[i-1])
    gr[gr.size()-1]++;
    else
        {
        b[a[i]-1].push_back(jr.size());
        jr.push_back(a[i]);
        gr.push_back(1);
        }
    }
    int mins=0;
    int ans=0;
       for(int i=0;i<k;i++)
       {
               int curs=0;
               for(int j=0;j<b[i].size();j++)
               {
                       if(jr[b[i][j]-1]==jr[b[i][j]+1])
                       curs+=2;
                       else
                       curs++;
               }
               if(curs>mins)
               {
                            mins=curs;
                            ans=i+1;
               }
       }
        
        cout<<ans<<endl;
        
    //system("PAUSE");
    return EXIT_SUCCESS;
}