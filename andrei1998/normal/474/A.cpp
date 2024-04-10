#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string x="qwertyuiopasdfghjkl;zxcvbnm,./";

    char lit;
    cin>>lit;

    int offset;
    if(lit=='R')
        offset=-1;
    else
        offset=+1;

    string sir;
    cin>>sir;

    for(int i=0;i<sir.size();i++)
        cout<<x[find(x.begin(),x.end(),sir[i])-x.begin()+offset];

    return 0;
}