#include <iostream>

using namespace std;

int n, t, ki;
int maradek[101];

int main()
{
    cin>>n>>t;
    if(n==1){
        if(t==10){
            cout<<-1;
            return 0;
        }
        cout<<t;
        return 0;

    }
    maradek[0]=1;
    for(int i=1;i<n;i++){
        maradek[i]=(maradek[i-1]*10)%t;
    }
    ki=t-maradek[n-1];
    if(t==10){
        ki=0;
    }
    cout<<1;
    for(int i=0;i<n-2;i++){
        cout<<0;
    }
    cout<<ki;

    return 0;
}