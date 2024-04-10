#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string in;
    cin>>in;
    char max='a';
    int f=0;
    for(int i=0;i<in.size();i++)
    {
            if(in[i]>max)
            {
                max=in[i];
                f=1;         
            }
            else if(in[i]==max)
            f++;
    }
    for(int i=0;i<f;i++)
    cout<<max;
    cout<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}