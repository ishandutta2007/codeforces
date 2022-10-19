#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
#define fo(a,b) for(int a=0; a<b; a++)
using namespace std;


int main()
{
    int n, k;
    cin >> n >> k;
    if(n==k){
        cout << -1;
    }
    else{
    cout << n-k << " ";
    fo(a,n-k-1){
        cout << a+1 << " ";
    }
    for(int a=n-k+1; a<=n; a++){
        cout << a;
        if(a!=n)
        cout << " ";
    }
    }


}