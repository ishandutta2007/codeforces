#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long n,l;
    cin >> n >> l;
    vector<long> v ;
    for(int i=0; i<n; i++){
        long m;
        cin >> m;
        v.push_back(m);
    }
    sort(v.begin(),v.end());
    double m=0;

    for(int i=0; i<n-1; i++){
        if(v[i+1]-v[i]>2*m){
            m=v[i+1]-v[i];
            m/=2;
        }
    }
    if(v[0]>m){
        m=v[0];
    }
    if(l-v[n-1]>m){
        m=l-v[n-1];
    }

    cout << fixed << showpoint << setprecision(6) << m << endl;


}