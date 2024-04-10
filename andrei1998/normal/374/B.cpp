#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    char nr[100005];
    int din[100005],i;
    long long int cate[100005];

    cin.get(nr,100005);
    int n=strlen(nr);


    din[n-1]=0;
    din[n]=0;
    cate[n-1]=1;
    cate[n]=1;

    if(nr[n-1]=='9')
        din[n-1]=1;

    for(i=n-2;i>=0;i--)
    {
        din[i]=din[i+1];
        cate[i]=cate[i+1];
        if(nr[i]=='9')
            din[i]++;

        if((nr[i]+nr[i+1]-'0'-'0')==9)
        {
            if(din[i]<(din[i+2]+1))
            {
                din[i]=din[i+2]+1;
                cate[i]=cate[i+2];
            }
            else if(din[i]==(din[i+2]+1))
                cate[i]+=cate[i+2];
        }
    }

    cout<<cate[0]<<'\n';

    return 0;
}