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

int gen(int x,int a,int b,int c)
{
 return (x*a+b)%c; 
}

int main(int argc, char *argv[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");    
    int n;
    in>>n;
    int x,a,b,c;
    in>>x>>a>>b>>c;
    
    string*com=new string[n];
    int *rate=new int[n];
    
    for(int i=0;i<n;i++)
    in>>com[i]>>rate[i];
    bool repeat;
    do
    {
                repeat=false;
                for(int i=0;i<n-1;i++)        
                {
                        if(rate[i]<rate[i+1])
                        {
                                             repeat=true;
                                             int tmp1=rate[i];
                                             string tmp2=com[i];
                                             rate[i]=rate[i+1];
                                             rate[i+1]=tmp1;
                                             com[i]=com[i+1];
                                             com[i+1]=tmp2;
                        }
                }
    }
    while(repeat);
    
    int m=n/4;
    
    vector<string> corzes_com[4];
    for(int i=0;i<4;i++)
    for(int j=0;j<m;j++)
    {
            corzes_com[i].push_back(com[i*m+j]);
    }
    
    vector<string> *groups_com=new vector<string>[m];
    for(int i=0;i<m-1;i++)
    {
            for(int j=0;j<4;j++)
            {
                    x=gen(x,a,b,c);
                    int s=corzes_com[j].size();
            groups_com[i].push_back(corzes_com[j][x%s]);
            corzes_com[j].erase(corzes_com[j].begin()+x%s,corzes_com[j].begin()+x%s+1);
            }
    }
    
    groups_com[m-1].push_back(corzes_com[0][0]);
    groups_com[m-1].push_back(corzes_com[1][0]);
    groups_com[m-1].push_back(corzes_com[2][0]);
    groups_com[m-1].push_back(corzes_com[3][0]);
    
    string ch="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    for(int i=0;i<m;i++)
    {
            out<<"Group "<<ch[i]<<':'<<endl;
            for(int j=0;j<4;j++)
            out<<groups_com[i][j]<<endl;
    }
    
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}