#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

#define MAX 100
#define test(a) cout << "TEST " << a << endl;
#define go(a,b) for(int a=0; a<b; a++)
#define case(a) fout << "Case #"<< a << ": " <<
using namespace std;



int main()
{
    int a,b,d;

    cin >> a >> b;
    vector<int> v;
    go(c,a){
        cin >> d;
        v.push_back(d);
    }
    sort(v.begin(), v.end());
    cout << v[a-b];


}