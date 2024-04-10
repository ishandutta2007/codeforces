#include <iostream>
#include <cstring>

using namespace std;

int n;
char sir[205];

int main()
{
    cin>>n;
    cin.get();
    cin.get(sir+1,205);

    int dif=0;
    for(int i=1;i<=n;i++)
        if(sir[i]=='X')
            dif++;
        else
            dif--;

    int ans=0;
    for(int i=1;i<=n;i++)
        if(dif<0 && sir[i]=='x') {
            sir[i]='X';
            ans++;
            dif+=2;
        }
        else if(dif>0 && sir[i]=='X') {
            sir[i]='x';
            ans++;
            dif-=2;
        }

    cout<<ans<<'\n';
    cout<<sir+1<<'\n';
    return 0;
}