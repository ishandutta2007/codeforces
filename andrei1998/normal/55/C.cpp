#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n=0,m=0,k=0;
    cin>>n>>m>>k;

    int x=0,y=0;
    int a,b,c,d;

    while(k--){
        cin>>x>>y;

        a=x;
        b=y;
        c=n-x+1;
        d=m-y+1;

        if(a<=5 || b<=5 || c<=5 || d<=5){ //Celula nu distanta
            cout<<"YES\n";
            return 0;
        }
    }

    cout<<"NO\n";
    return 0;
}