#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <fstream>

#define u64 long long

using namespace std;

int main(int argc, char *argv[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    u64 n,k;
    in>>n>>k;
    vector<int> svetl;
    vector<int> svetl_c;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
            u64 tmp;
            in>>tmp;
            svetl.push_back(tmp);
    }
    svetl_c=svetl;
    for(int i=0;i<k;i++)
    {
            vector<int>::iterator it=max_element(svetl.begin(),svetl.end());
            ans.push_back(it-svetl.begin());
            *it=-1;
            
    }
    
    out<<svetl_c[ans[ans.size()-1]]<<endl;
    sort(ans.begin(),ans.end());
    out<<ans[0]+1;
    for(int i=1;i<k;i++)
    {
            out<<' '<<ans[i]+1;
    }
    out<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}