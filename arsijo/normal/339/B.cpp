//============================================================================
// Author      : arsijo
// made in Ukraine
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n, m;

    cin >> n >> m;

    long long sum = 0;
    int pos = 1;
    int last;
    int r = 0;

    for(int i = 0; i < m; i++){

        int a;
        cin >> a;
        if (a < pos) {
        
            sum += n - pos + a;
            pos = 1;
        }else{
            sum += a - pos;
        }
        pos = a;

    }

    cout << sum;

}