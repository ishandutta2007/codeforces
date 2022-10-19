
using namespace std;

//#define fileio

#ifndef fileio
#include <iostream>
#endif
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>

typedef long long ll;

#ifdef fileio
ifstream cin;
ofstream cout;
#endif



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef fileio
    cin.open("Text.txt");
    cout.open("Output.txt");
#endif

    long long n;
    cin >> n;

    

    vector<long long> v;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        v.push_back(x);
    }

    if (n == 1) {
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        cout << -v[0] << endl;
        return 0;
    }

    cout << 1 << " " << n << endl;

    cout << 0 << " ";
    for (long long i = 1; i < n; i++) {
        //want to add some amount of n to make v[i] a multiple of n-1
        cout << ((((n - 1) - (v[i] % (n - 1)))) * n) << " ";
        v[i] += ((((n - 1) - (v[i] % (n - 1)))) * n);
    }
    cout << endl;
    cout << 2 << " " << n << endl;
    for (long long i = 1; i < n; i++) {
        cout << -v[i] << " ";
    }
    cout << endl;
    cout << 1 << " " << 1 << endl;
    cout << -v[0] << endl;




}