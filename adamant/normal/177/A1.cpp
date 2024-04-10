#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int N;
    
    cin>>N;
    
    long long answer=0;
    
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
    {
    int tmp;
    cin>>tmp;
            
            if( (i==j) || (i==N/2) || (j==N/2) || (j==N-1-i) )
            {
            answer+=tmp;
            //cout<<i<<' '<<j<<endl;
            }
            
            
    }
    
    cout<<answer<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}