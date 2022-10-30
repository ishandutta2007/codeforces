#include <iostream>

using namespace std;
int t[5], n;
int main()
{
    cin >> n >> t[0] >> t[1] >> t[3] >> t[2];
    t[4]=t[0];
    int mini=200001, maxi=0;
    for(int i=0;i<4;i++) {
        int a=t[i]+t[i+1];
        if(a<mini) mini=a;
        if(a>maxi) maxi=a;
    }
    if(maxi-mini>n-1) {
        cout << "0" << endl;
    } else {
        cout << (long long)n*(n-(maxi-mini)) <<endl;
    }
    return 0;
}