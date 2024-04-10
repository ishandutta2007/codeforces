#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int N;
    cin>>N;
    if(N==1)
    cout<<1<<endl;
    else
    {
        cout<<N;
        for(int i=0;i<N-1;i++)
        cout<<' '<<i+1;
        cout<<endl;
    }
    return EXIT_SUCCESS;
}