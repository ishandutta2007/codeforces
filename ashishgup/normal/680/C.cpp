#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;


int main()
{
    vector<int> p={2,3,5,7};
    vector<int> q={11,13,17,19,23,29,31,37,41,43,47};
    string s;
    int count=0;
    for(int i=0;i<4;i++)
    {
        cout<<p[i]<<endl;
        fflush(stdout);
        cin>>s;
        if(s=="yes")
        {
            count++;
            cout<<p[i]*p[i]<<endl;
            fflush(stdout);
            cin>>s;
            if(s=="yes")
            {
                cout<<"composite";
                return 0;
            }
        }
        if(count>=2)
        {
            cout<<"composite";
            return 0;
        }
        
    }
    for(int i=0;i<11;i++)
    {
        cout<<q[i]<<endl;
        fflush(stdout);
        cin>>s;
        if(s=="yes")
        {
            count++;
            if(count>=2)
            {
                cout<<"composite";
                return 0;
            }
        }
    }
    cout<<"prime";
    return 0;
}