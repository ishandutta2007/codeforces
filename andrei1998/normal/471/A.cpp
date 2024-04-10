#include <iostream>
#include <algorithm>

using namespace std;

int frecv[10];

int main()
{
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;

    frecv[a]++;
    frecv[b]++;
    frecv[c]++;
    frecv[d]++;
    frecv[e]++;
    frecv[f]++;

    sort(frecv+1,frecv+10);
    frecv[9]-=4;
    if(frecv[9]<0){
        cout<<"Alien\n";
        return 0;
    }

    sort(frecv+1,frecv+10);
    if(frecv[9]==1)
        cout<<"Bear\n";
    else
        cout<<"Elephant\n";

    return 0;
}