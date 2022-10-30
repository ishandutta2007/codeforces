#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <cstdlib>
#include <cmath>

using namespace std;

long long a,b,c,n,t[10000];
long long ki=0;
int main()
{
    cin >> n;
    long long h=9;
    for(int i=1;n>0;i++) {
        if(n<=h){
            ki+=n*i;
            n=0;
        }
        else {
            ki+=h*i;
            n-=h;
        }
        h*=10;
    }
    cout << ki << endl;
    return 0;
}