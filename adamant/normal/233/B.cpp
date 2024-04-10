#include <cstdlib>
#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    long long n;
    
    cin>>n;
    
    for(long long i=sqrt(n)-min(1000000,int(sqrt(n)));i<sqrt(n)+2;i++)
    {
             char a[10];
             itoa(i,a,10);
             long long s=0;
             for(int j=0;j<strlen(a);j++)
             {
                     s+=a[j]-'0';
             }
             if(i*i+s*i==n)
             {
                           cout<<i<<endl;
                           //system("PAUSE");
                           return 0;
             }
    }
    cout<<-1<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}