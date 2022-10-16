#include <iostream>

using namespace std;

int n;
int h[100005];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }

    long long int minim=0;
    long long int e=0;
    for(int i=0;i<n;i++){
        if(e+h[i]-h[i+1]<0){
            minim+=(-e+h[i+1]-h[i]);
            h[i]+=(-e+h[i+1]-h[i]);
            e=0;
        }
        else{
            e+=(h[i]-h[i+1]);
        }
    }

    cout<<minim<<endl;
    return 0;
}