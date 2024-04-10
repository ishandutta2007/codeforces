#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int a,b,c,d,n,t[10000], ki;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a >> b >> c >> d;
        ki+=(c-a+1)*(d-b+1);
    }
    cout << ki << endl;
    return 0;
}