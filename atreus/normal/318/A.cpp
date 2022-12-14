#include <iostream>

using namespace std;

int main ()

{
    long long int n, k;
    cin >> n >> k;
    if ((n/2)+(n%2) - k >= 0){
        cout << ((k*2)-1);
    }
    else{
        cout << (2*(k-((n/2)+n%2)));
    }
}