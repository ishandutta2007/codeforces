#include <iostream>

using namespace std;

long n,minim=1000000006,maxim=0,mini,maxi,i,x;
long long ans;

int main()
{
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> x;
        if(x < minim){
            minim = x; mini = 0;
        }
        if(x > maxim){
            maxim = x; maxi = 0;
        }
        if(x == minim) mini++;
        if(x == maxim) maxi++;
    }

    ans = 1LL*mini*maxi;

    if(minim == maxim) ans = (1LL*mini*(mini-1))/2;

    cout << maxim-minim << ' ' << ans;
    return 0;
}