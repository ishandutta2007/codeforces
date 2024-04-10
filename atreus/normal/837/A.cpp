#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

const int maxn = 1e5;
int m;
int a[maxn];

int howmanycapital(string a){
    int k = 0;
    for (int i = 0; i < a.length(); i++){
        int l = (int) a[i];
        if (l <= 90)
            k++;
    }
    return k;
}
int main (){
    int n, m = 0, p = 0;
    cin >> n;
    int q = n;
    string s[n];
    for (int i = 0; i < n; i++){
        cin >> s[i];
        if (howmanycapital(s[i]) > p)
            p = howmanycapital(s[i]);
        q -= s[i].length();
        if (q == 0)
            break;
        else
            q--;
    }
    cout << p << endl;
}