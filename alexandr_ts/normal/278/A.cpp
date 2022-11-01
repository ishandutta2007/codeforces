#include <iostream>
#include <cmath>

using namespace std;

const long double EPS = 1e-9;

int a[1000000];

int main()
{
    int n;
    cin >> n;
    int summ = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];summ += a[i];}
    int st, en;
    cin >> st >> en;
    st--;
    en--;
    if(en < st)
    swap(en, st);
    int s1 = 0;
    for(int i = st; i < en; i++)
        s1 += a[i];
    cout << min(s1, summ - s1);
    return 0;
}