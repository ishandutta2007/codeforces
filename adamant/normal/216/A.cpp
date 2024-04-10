#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int a,b,c;
    cin>>a>>b>>c;
    
    cout<<a*b+(c-1)*a+(c-1)*(b-1)<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}