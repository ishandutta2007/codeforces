#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long n,datanum[100*1001],k;
string a,datastr[100*1001];
int main()
{
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        bool mark=false;
        cin>>a;
        for(int j=0;j<k;j++)
            if(datastr[j]==a)
            {
                mark=true;
                cout<<a;
                printf("%d\n",datanum[j]);
                datanum[j]++;
            }
        if(mark==false) 
        {
            printf("OK\n");
            datastr[k]=a;
            datanum[k]=1;
            k++;
        }
    }

    return 0;
}